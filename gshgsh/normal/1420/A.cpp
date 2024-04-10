#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 50001
int T,N,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();
		bool flag=1;For(i,2,N)flag&=a[i-1]>a[i];cout<<(flag?"NO\n":"YES\n");
	}
	return 0;
}