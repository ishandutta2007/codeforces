#include <cstdio>

typedef unsigned int uint;

const int MN = 2e3+10;

int gcd(int a, int b){return a?gcd(b%a,a):b;}

int A, B, C, mu[MN], l[MN], p[MN], P;
uint f;
bool c[MN], ok[MN][MN];

uint solve(int x, int m)
{
	uint r=0;
	for(int i=1;i<=m;++i)
		if(ok[i][x])
			r+=m/i;
	return r;
}

int main()
{
	mu[1]=1;
	for(int i=2;i<MN;++i)
	{
		if(!c[i]) l[i]=P, p[P++]=i, mu[i]=-1;
		for(int j=0,k;(k=i*p[j])<MN;++j)
		{
			c[k]=1;
			l[k]=j;
			if(l[i]==j)
				break;
			mu[k]=-mu[i];
		}
	}
	for(int i=1;i<MN;++i)
		for(int j=1;j<MN;++j)
			ok[i][j]=gcd(i,j)==1;
	scanf("%d%d%d", &A, &B, &C);
	for(int g=1;g<MN;++g)
		if(mu[g])
			for(int i=1;i<=A;++i)
				if(ok[i][g])
					f+=mu[g]*(A/i)*solve(i, B/g)*solve(i, C/g);
	printf("%d\n", f&0x3fffffff);
	return 0;
}