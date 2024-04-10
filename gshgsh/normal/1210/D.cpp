#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M,K,deg[MAXN];ll ans[MAXN],sum;vector<int>in[MAXN];
int main()
{
	cin>>N>>M;For(i,1,M){int u,v;cin>>u>>v;deg[u]++,deg[v]++;if(u>v)swap(u,v);in[u].push_back(v);}For(i,1,N)sum+=ans[i]=1ll*in[i].size()*(deg[i]-in[i].size());cout<<sum<<endl;
	cin>>K;For(i,1,K){int x;cin>>x;sum-=ans[x];ans[x]=0;for(auto y:in[x])sum-=ans[y],in[y].push_back(x),sum+=ans[y]=1ll*in[y].size()*(deg[y]-in[y].size());in[x].clear();cout<<sum<<endl;}return 0;
}