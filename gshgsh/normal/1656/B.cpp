#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,K,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);bool flag=0;
		For(i,1,N){int x=a[i]-K;if(*lower_bound(a+1,a+N+1,x)==x)flag=1;}
		cout<<(flag?"YES\n":"NO\n");
	}
}