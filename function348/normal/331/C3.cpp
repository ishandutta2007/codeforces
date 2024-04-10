#include<cstdio>
#include<iostream>
using namespace std;
typedef long long LL;
struct rec{LL l;int p;};
int n;
rec dp[20],f[20][10][10];
int a[20];
int main()
{
	LL tmp;
	cin>>tmp;
	if (tmp==0) { printf("0\n");return 0;}
	if (tmp<10) { printf("1\n");return 0;}
	for (int i=1;i<=19;i++) a[i]=tmp%10,tmp/=10;
	int mx=0;
	for (int i=2;i<=19;i++) mx=max(mx,a[i]);
	if (mx>a[1]) dp[1]=(rec){1,mx-a[1]};else dp[1]=(rec){2,a[1]};
	for (int j=0;j<=9;j++)
	for (int k=1;k<=9;k++)
	if (j>10-k)	f[1][j][k]=(rec){1,j+k-10};else
	if (j>0) f[1][j][k]=(rec){2,j};else f[1][j][k]=(rec){1,0};
	
	for (int i=2;i<=19;i++)
	{
		int mx=0;
		for (int j=19;j>i;j--) mx=max(mx,a[j]);
		LL len=dp[i-1].l;int p=dp[i-1].p;
		for (int j=a[i]-1;j>=0;j--)
		{
			len+=f[i-1][max(mx,j)][p].l;
			p=f[i-1][max(mx,j)][p].p;
		}
		dp[i]=(rec){len,p};
		for (int j=0;j<=9;j++)
		for (int k=1;k<=9;k++)
		{
			LL len=0;int p=k;
			for (int q=9;q>=0;q--)
			{
				len+=f[i-1][max(j,q)][p].l;
				p=f[i-1][max(j,q)][p].p;
			}
			f[i][j][k]=(rec){len,p};
		}
	}
	printf("%lld\n",dp[19].l);
	return 0;
}