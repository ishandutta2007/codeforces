#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 300001
int N,a[MAXN],f[MAXN],top0,top1,sta0[MAXN],sta1[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();For(i,1,N)a[i]=get();f[0]=N;sta0[top0=1]=sta1[top1=1]=1;
	For(i,2,N)
	{
		f[i]=f[i-1]+1;
		while(top0&&a[i]<=a[sta0[top0]])a[i]!=a[sta0[top0]]&&(f[i]=min(f[i],f[sta0[top0-1]]+1)),top0--;sta0[++top0]=i;
		while(top1&&a[i]>=a[sta1[top1]])a[i]!=a[sta1[top1]]&&(f[i]=min(f[i],f[sta1[top1-1]]+1)),top1--;sta1[++top1]=i;
	}
	cout<<f[N]<<endl;return 0;
}