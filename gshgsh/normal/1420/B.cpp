#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];bool vis[MAXN]; 
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),vis[i]=0;
		ll ans=0;FOR(i,30,0){int cnt=0;For(j,1,N)cnt+=!vis[j]&&((a[j]>>i)&1);ans+=1ll*cnt*(cnt-1)/2;For(j,1,N)if((a[j]>>i)&1)vis[j]=1;}
		cout<<ans<<endl;
	}
	return 0;
}