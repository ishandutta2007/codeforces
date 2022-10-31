#include<cstdio>
#include<iostream>
using namespace std;
const int N=50;
int n,x,ans;
int a[N][N],stat[N];
int abs(int n) { return n>0?n:-n;}
int main()
{
	scanf("%d",&n);x=n/2;
	ans=-1000000000;
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	for (int sta=0;sta<(1<<x);sta++)
	for (int c=-1;c<=1;c+=2)
	{
		int sum=0;
		for (int i=0;i<x;i++) stat[i]=((sta>>i)&1)?-1:1;
		sum+=a[x][x]*c;
		for (int i=0;i<x;i++) 
			sum+=a[i][x]*stat[i]+a[i+x+1][x]*stat[i]*c;
		for (int j=0;j<x;j++)
		{
			int res=-1000000000;
			for (int k=-1;k<=1;k+=2)
			{
				int tmp=k*a[x][j]+k*c*a[x][j+x+1];
				for (int i=0;i<x;i++)
					tmp+=abs(a[i][j]+a[i][j+x+1]*stat[i]+a[i+x+1][j]*k+a[i+x+1][j+x+1]*k*c*stat[i]);
				res=max(res,tmp);
			}
			sum+=res;
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}