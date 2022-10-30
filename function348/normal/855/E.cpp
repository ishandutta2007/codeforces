#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=10;
typedef long long LL;
//LL f[70][1100][2][2];
LL g[70][12][12];
int xx[1100],a[70];
int p;
LL dp(int n,int s,int f1,int f2)
{
	if (n==0)
	{
		if (s!=0) return 0;
		if (!f2) return 0;
		return 1;
	}
//	if (f[n][s][f1][f2]!=-1) return f[n][s][f1][f2];
	if (!f1&&f2) return g[n][xx[s]][p];
	int r=(f1?a[n]:p-1);
	LL res=0;
	for (int i=0;i<=r;i++)
	if (i>0) res+=dp(n-1,s^(1<<i),f1&&i==r,f2||i>0);
	else res+=dp(n-1,s^f2,f1&&i==r,f2||i>0);
//	f[n][s][f1][f2]=res;
//	printf("%d %d %d %d %lld\n",n,s,f1,f2,res);
	return res;
}
LL calc(LL n,int p)
{
	int len=0;
	while (n)
	{
		len++;a[len]=n%p;
		n/=p;
	}
//	cout<<endl;
/*	for (int i=0;i<=len;i++)
	for (int j=0;j<=1024;j++)
	for (int k1=0;k1<2;k1++)
	for (int k2=0;k2<2;k2++)
		f[i][j][k1][k2]=-1;*/
	return dp(len,0,1,0);
}
int main()
{
	for (int i=2;i<=10;i++) g[0][0][i]=1;
	for (int l=2;l<=10;l++)
	for (int n=1;n<=70;n++)
	for (int k=0;k<=l;k++)
		g[n][k][l]=g[n-1][k-1][l]*k+g[n-1][k+1][l]*(l-k);
	for (int i=1;i<1024;i++) xx[i]=xx[i>>1]+(i&1);
	int cas;scanf("%d",&cas);
	while (cas--)
	{
		LL l,r;
	//	p=10,l=1LL<<58,r=l*2;
		scanf("%d%lld%lld",&p,&l,&r);
		printf("%lld\n",calc(r,p)-calc(l-1,p));
	}
	return 0;
}