#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 998244353;
int n,q;
vector<P1>query[150005];
vector<int>edge[150005];
ll cur[150005],add[150005];
vector<int>big;
ll num[150005];
int dep[150005],in[150005],out[150005],sub[150005],up[150005][20],id;
void dfs(int v,int u){
	up[v][0] = u;
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	in[v] = id++; sub[v] = 1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		sub[v] += sub[edge[v][i]];
	}
	out[v] = id-1;
}
int lca(int a,int b){
	if(dep[a] > dep[b] ) swap(a,b);
	int D = dep[b]-dep[a];
	rep(j,19){
		if(((D>>j)&1)) b = up[b][j];
	}
	if(a == b) return a;
	for(int j=18;j>=0;j--){
		if(up[a][j] != up[b][j]){
			a = up[a][j];
			b = up[b][j];
		}
	}
	return up[a][0];
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
struct BIT
{
	int bit[150005];
	void add(int i,int x)
	{
		i++;
		for(int s=i;s<150005;s+=s&-s){
			bit[s]+=x;
			if(bit[s] >= mod) bit[s] -= mod;
		}
	}
	int sum(int i)
	{
		i++;
		int res=0;
		for(int s=i;s>0;s-=s&-s){
		    res+=bit[s];
		    if(res >= mod) res -= mod;
		}
		return res;
	}
}kaede;
#define SZ 614
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	rep(j,18) repn(i,n){
		if(up[i][j] == -1) up[i][j+1] = -1;
		else up[i][j+1] = up[up[i][j]][j];
	}
	repn(i,n){
		if(edge[i].size() >= SZ){
			big.pb(i);
		}
	}
	rep(i,q){
		int ty; scanf("%d",&ty);
		if(ty == 1){
			int v,d; scanf("%d%d",&v,&d);
			add[v] = (add[v]+1LL*d*n)%mod;
			if(edge[v].size() >= SZ){
				num[v] = (num[v]+d)%mod;
			}
			else{
				rep(x,edge[v].size()){
					int to = edge[v][x];
					if(dep[v] < dep[to]){
						int L = in[to], R = out[to];
						ll add = 1LL*(n-sub[to])*d%mod;
						kaede.add(L,add);
						kaede.add(R+1,mod-add);
					}
					else{
						ll add = 1LL*sub[v]*d%mod;
						int L = in[v], R = out[v];
						kaede.add(0,add);
						kaede.add(L,mod-add);
						kaede.add(R+1,add);
					}
				}
			}
		}
		else{
			int v; scanf("%d",&v);
			ll ans = add[v];
			ans += kaede.sum(in[v]);
			rep(k,big.size()){
				if(big[k] == v) continue;
				int y = lca(v,big[k]);
				if(y == big[k]){
					int x = dep[v]-dep[big[k]]-1;
					int cur = v;
					rep(j,19) if(((x>>j)&1)) cur = up[cur][j];
					assert(up[cur][0] == big[k]);
					ans += 1LL*(n-sub[cur])*num[big[k]];
				}
				else{
					ans += 1LL*sub[big[k]]*num[big[k]];
				}
			}
			ans %= mod;
			ans = ans*modpow(n,mod-2)%mod;
			printf("%lld\n",ans);
		}
	}
}