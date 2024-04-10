#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll gh(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0)return a;else return gh(b,a%b);
}
int n,dep[100005],up[100005][20];
ll v[100005],g[100005][20];
vector<int>edge[100005];
void dfs(int v,int u){
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	up[v][0]=u;
	rep(i,edge[v].size()){
		if(u == edge[v][i]) continue;
		dfs(edge[v][i],v);
	}
}
ll ans;
void dfs2(int x,int u,ll A){
	if(x == 1){
		ans += v[x];
		A = v[x]%mod;
	}
	else{ int xx = x;
		if(v[x] == 0){
			ans += A;
		}
		else{ 
			ll cur = v[x]; A = 0;
			while(x != -1){
				int num = 0;
				for(int i=19;i>=0&&x>=0;i--){
					if((1<<i) > dep[x]+1) continue;
					if(g[x][i]%cur == 0){
						num += (1<<i);
						x = up[x][i];
					}
				}
				ans += cur%mod*num%mod; A += cur%mod*num%mod;
				if(x >= 0) {assert(cur != gh(cur,v[x])); cur = gh(cur,v[x]);}
			}
		}
		A%=mod;
		x = xx;
	}
	rep(i,edge[x].size()){
		if(u == edge[x][i]) continue;
		dfs2(edge[x][i],x,A);
	}
}
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%lld",&v[i]);
		g[i][0] = v[i];
	}
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	rep(j,19) repn(i,n){
		if(up[i][j] == -1) up[i][j+1] = -1;
		else up[i][j+1] = up[up[i][j]][j];
	}
	rep(j,19) repn(i,n){
		if(up[i][j] == -1) g[i][j+1] = g[i][j];
		else g[i][j+1] = gh(g[i][j],g[up[i][j]][j]);
	}
	dfs2(1,-1,0);
	cout << (ans%mod+mod)%mod << endl;
}