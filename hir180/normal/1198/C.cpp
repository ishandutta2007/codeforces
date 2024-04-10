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

int n,m;
bool used[300005];
vector<P>edge[300005];

void solve(){
	scanf("%d%d",&n,&m);
	repn(i,3*n){
		used[i] = 0;
		edge[i].clear();
	}
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(P(b,i+1)); edge[b].pb(P(a,i+1));
	}
	vector<int>match;
	repn(i,3*n){
		if(used[i]) continue;
		rep(j,edge[i].size()){
			int to = edge[i][j].fi, id = edge[i][j].sc;
			if(!used[to]){
				used[i] = 1;
				used[to] = 1;
				match.pb(id);
				break;
			}
		}
	}
	if(match.size() >= n){
		puts("Matching");
		rep(i,n) printf("%d\n",match[i]);
		return ;
	}
	else{
		puts("IndSet");
		int zan = n;
		repn(i,3*n) if(!used[i]) { printf("%d\n",i); zan--; if(zan == 0) return; }
	}
}


int t;
int main(){
	scanf("%d",&t);
	while(t--) solve();
}