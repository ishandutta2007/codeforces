#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get()-2;get();For(i,1,N)a[i]=get();get();
		bool flag=0;For(i,1,N)flag|=a[i]>1;if(!flag){cout<<"-1\n";continue;}
		flag=0;For(i,1,N)flag|=a[i]%2==0;
		if(!flag){if(N==1){cout<<"-1\n";continue;}ll ans=0;For(i,1,N)ans+=a[i]+1>>1;cout<<ans<<'\n';continue;}
		ll ans=0;For(i,1,N)ans+=a[i]+1>>1;cout<<ans<<'\n';
	}
}