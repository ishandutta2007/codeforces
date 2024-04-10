#include<cstdio>

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}

void solve(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(gcd(a,b)==1) printf("Finite\n");
	else printf("Infinite\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}