#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1001
int T,N,K,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get();
		sort(a+1,a+N+1);int ans=0;For(i,2,N)ans+=(K-a[i])/a[1];cout<<ans<<endl;
	}
	return 0;
}