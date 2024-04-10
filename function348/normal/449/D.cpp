#include<cstdio>
#include<iostream>
const int mo=1000000007;
int n;
int f[22][1100000];
int cnt[1100000];
int pow(int j,int p)
{
	int r=2,q=1;
	while (j)
	{
		if (j&1) q=1LL*q*r%p;
		r=1LL*r*r%p;
		j>>=1;
	}
	return q;
}
int main()
{
	scanf("%d",&n);
	while (n--)
	{
		int x;
		scanf("%d",&x);
		f[0][x]++;
	}
	
	for (int i=1;i<=20;i++)
	for (int j=0;j<(1<<20);j++)
	if ((j>>(i-1))&1) f[i][j]=f[i-1][j];
				 else f[i][j]=f[i-1][j]+f[i-1][j+(1<<(i-1))];
	
	for (int i=1;i<(1<<20);i++) cnt[i]=cnt[i-(i&-i)]+1;
	for (int i=0;i<(1<<20);i++) if (cnt[i]%2) cnt[i]=-1;else cnt[i]=1;
	int ans=0;
	for (int i=0;i<(1<<20);i++) ans=(ans+cnt[i]*pow(f[20][i],mo))%mo;
	ans=(ans+mo)%mo;
	printf("%d\n",ans);
	return 0;
}