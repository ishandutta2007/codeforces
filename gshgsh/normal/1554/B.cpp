#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,K,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=get();
		ll ans=-1e18;FOR(i,N,1)if(1ll*i*(i-1)>=ans)FOR(j,i-1,1)if(1ll*i*j>=ans)ans=max(ans,1ll*i*j-K*(a[i]|a[j]));else break;else break;
		cout<<ans<<endl;
	}
	return 0;
}