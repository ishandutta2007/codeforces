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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define ld long double
const ll mod = 1000000007;

int n,m,k;
vector<int>edge[200005];
vector<P>G;
int ans[200005],deg[200005];
set<P>er;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b); edge[b].pb(a);
		G.pb(P(a,b));
	}
	queue<int>que;
	repn(i,n){
		deg[i] = edge[i].size();
		if(deg[i] < k){
			que.push(i);
		}
	}
	ans[m] = n;
	for(int i=m-1;i>=0;i--){
		ans[i] = ans[i+1];
		while(!que.empty()){
			int q = que.front(); que.pop();
			ans[i] --;
			rep(i,edge[q].size()){
				int to = edge[q][i];
				if(er.find(P(min(to,q),max(to,q))) != er.end()) continue;
				er.insert(P(min(to,q),max(to,q)));
				deg[to] --; if(deg[to] == k-1) que.push(to);
			}
		}
		int x = G[i].fi, y = G[i].sc;
		if(x > y) swap(x,y);
		if(er.find(P(x,y)) != er.end()) continue;
		deg[x]--; deg[y]--;
		if(deg[x] == k-1) que.push(x);
		if(deg[y] == k-1) que.push(y);
		er.insert(P(x,y));
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
}