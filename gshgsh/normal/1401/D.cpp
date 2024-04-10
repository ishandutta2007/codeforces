#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
int T,N,M,a[MAXN],siz[MAXN],ans;ll val[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int f){siz[u]=1;for(auto v:E[u])if(v!=f)dfs(v,u),siz[u]+=siz[v];}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)E[i].clear();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}dfs(1,0);
		For(i,2,N)val[i-1]=1ll*siz[i]*(N-siz[i]);sort(val+1,val+N,greater<ll>());M=get();For(i,1,M)a[i]=get();sort(a+1,a+M+1,greater<ll>());
		if(M>N-1){ans=0;int mul=1;For(i,1,M-N+2)mul=1ll*mul*a[i]%P;ans=(ans+val[1]%P*mul)%P;For(i,2,N-1)ans=(ans+val[i]%P*a[M-N+1+i])%P;}
		else{ans=0;For(i,1,M)ans=(ans+1ll*val[i]%P*a[i])%P;For(i,M+1,N-1)ans=(ans+val[i])%P;}cout<<ans<<'\n';
	}
	return 0;
}