#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,a[MAXN];ll M;
ll get(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(ll x){ll sum=0;For(i,1,N)sum+=i==N?x:min(x,0ll+a[i+1]-a[i]);return sum>=M;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)a[i]=get();
		ll l=0,r=1e18,ans=0;while(l<=r){ll mid=l+r>>1;check(mid)?ans=mid,r=mid-1:l=mid+1;}
		cout<<ans<<'\n';
	}
	return 0;
}