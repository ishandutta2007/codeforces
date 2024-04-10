#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<ll,ll>
#define F first
#define S second
#define MAXN 400001
int N,M;bool vis[MAXN],in[MAXN];map<Pair,int>id;vector<Pair>E[MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}Pair turn(Pair x){return {x.F/GCD(x.F,x.S),x.S/GCD(x.F,x.S)};}
int dfs(int u)
{
	int now=-1;vis[u]=in[u]=1;
	for(auto i:E[u])
	{
		if(vis[i.F]){if(!in[i.F])now!=-1?ans.push_back({now,i.S}),now=-1:now=i.S;continue;}
		int x=dfs(i.F);if(x!=-1)ans.push_back({x,i.S});else now!=-1?ans.push_back({now,i.S}),now=-1:now=i.S;
	}
	in[u]=0;return now;
}
int main()
{
	N=get();For(i,1,N){int a=get(),b=get(),c=get(),d=get();Pair x=turn({1ll*b*c,1ll*(a+b)*d}),y=turn({1ll*b*(c+d),1ll*a*d});if(!id[x])id[x]=++M;if(!id[y])id[y]=++M;E[id[x]].push_back({id[y],i}),E[id[y]].push_back({id[x],i});}
	For(i,1,M)if(!vis[i])dfs(i);cout<<ans.size()<<endl;for(auto i:ans)cout<<i.F<<' '<<i.S<<endl;return 0;
}