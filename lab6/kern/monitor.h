#ifndef JOS_KERN_MONITOR_H
#define JOS_KERN_MONITOR_H
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

#include <inc/memlayout.h>

struct Trapframe;

void print_pfields(pte_t pte);

// Activate the kernel monitor,
// optionally providing a trap frame indicating the current state
// (NULL if none).
void monitor(struct Trapframe *tf);

// Functions implementing monitor commands.
int mon_quit(int argc, char **argv, struct Trapframe *tf);
int mon_help(int argc, char **argv, struct Trapframe *tf);
int mon_kerninfo(int argc, char **argv, struct Trapframe *tf);
int mon_backtrace(int argc, char **argv, struct Trapframe *tf);
int mon_vaddrinfo(int argc, char **argv, struct Trapframe *tf);
int mon_pgdir(int argc, char **argv, struct Trapframe *tf);
int mon_vminfo(int argc, char **argv, struct Trapframe *tf);
int mon_envinfo(int argc, char **argv, struct Trapframe *tf);
#endif	// !JOS_KERN_MONITOR_H