#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,M,a[MAXN],ans[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();int cnt=0;For(i,1,N)a[i]=get(),cnt+=a[i]*2==M;
		int x=0;For(i,1,N)if(a[i]*2!=M)ans[i]=a[i]*2<M;else x++,ans[i]=x*2<=cnt;For(i,1,N)cout<<ans[i]<<" \n"[i==N];
	}
	return 0;
}