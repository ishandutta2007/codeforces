#include <bits/stdc++.h>
int plus(register int a,register int b)
{
	register int res;
	__asm__ __volatile__ (
		"add %2, %1;"
		"mov %0, %2;"
		:"=r"(res)
		:"r"(a),"r"(b));
	return res;
}

int main() {
    int a, b,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&a,&b);
    printf("%d\n", plus(a, b));
	}
}