#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN];ll M;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
ll solve(int x,int y){return 1ll*x%(y+1)*(x/(y+1)+1)*(x/(y+1)+1)+1ll*(y+1-x%(y+1))*(x/(y+1))*(x/(y+1));}
pair<int,ll>check(ll d)
{
	ll ans=0;int cnt=0;
	For(i,1,N)
	{
		int x=a[i]-a[i-1];
		int l=1,r=x-1,p=0;while(l<=r){int mid=l+r>>1;if(solve(x,mid-1)-solve(x,mid)>=d)p=mid,l=mid+1;else r=mid-1;}
		ans+=solve(x,p);cnt+=p;
	}
	return {cnt,ans};
}
int main()
{
	N=get();For(i,1,N)a[i]=get();M=get();
	ll l=0,r=1e18,ans=0;while(l<=r){ll mid=l+r>>1;auto x=check(mid);if(x.second<=M)ans=mid,l=mid+1;else r=mid-1;}
	auto a=check(ans+1);cout<<a.first+(a.second-M+ans-1)/ans<<'\n';
}