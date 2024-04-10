#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 5001
int N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get();For(i,1,N)a[i]=get();ll ans=1e18;
	For(i,1,N)
	{
		ll sum=0;ll pre=0;FOR(j,i-1,1){ll x=pre/a[j]+1;sum+=x,pre=x*a[j];}
		pre=0;For(j,i+1,N){ll x=pre/a[j]+1;sum+=x,pre=x*a[j];}ans=min(ans,sum);
	}
	cout<<ans<<'\n';
}