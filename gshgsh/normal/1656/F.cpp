#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);ll sum=0;For(i,1,N)sum+=a[i];
		if(1ll*a[1]*(N-2)+sum>0||1ll*a[N]*(N-2)+sum<0){cout<<"INF\n";continue;}
		ll k=1ll*a[N]*(N-2)+sum,v=-1ll*(N-1)*a[N]*a[N],ans=v;
		FOR(i,N-1,1){int d=a[i+1]-a[i];v+=d*k;ans=max(ans,v);k+=a[1]-a[N];}cout<<ans<<'\n';
	}
}