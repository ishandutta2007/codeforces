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

#define mod_num 2
#define SZ 300005
ll M[10] = {1000000007,1000000009};
ll c[10] = {37, 41};
ll val[mod_num][SZ], hs[mod_num][SZ];

void init(){
	rep(i,mod_num) val[i][0] = 1;
	rep(j,SZ-1){
		rep(i,mod_num) val[i][j+1] = val[i][j] * c[i] % M[i];
	}
}

set<P>S[300005];

int n;
vector<P>edge[300005];
int num[300005];
void dfs(int v,int u,int d){
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		int cs = edge[v][i].sc;
		
		rep(j,2){
			hs[j][to] = (hs[j][v] + val[j][d] * cs)%M[j];
		}
		dfs(to,v,d+1);
	}
}
void rec(int v,int u,int d){
	P mx = mp(-1,-1);
	int gen;
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		int cs = edge[v][i].sc;
		num[d+1] ++;
		rec(to,v,d+1);
		if(mx < mp((int)(S[to].size()),to)){
			mx = mp((int)(S[to].size()),to);
			gen = cs;
		}
	}
	if(mx.sc == -1){
		return;
	}
	swap(S[v],S[mx.sc]);
	vector<P>vec;
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		int cs = edge[v][i].sc;
		if(to == mx.sc) continue;
		for(auto a:S[to]){
			ll x = a.fi, y = a.sc;
			x -= val[0][d] * (cs-gen) % M[0];
			y -= val[1][d] * (cs-gen) % M[1];
			if(x < 0) x+=M[0]; else if(x >= M[0]) x-=M[0];
			if(y < 0) y+=M[1]; else if(y >= M[1]) y-=M[1];
			
			if(S[v].find(mp(x,y)) != S[v].end()){
			    num[d+1] ++;
			}
			else{
				S[v].insert(mp(x,y));
				vec.pb(P(x,y));
			}
		}
	}
	for(auto a:vec) S[v].erase(a);
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		int cs = edge[v][i].sc;
		if(to == mx.sc) continue;
		for(auto a:S[to]){
			S[v].insert(a);
		}
		S[to].clear();
	}
	rep(i,edge[v].size()){
		int to = edge[v][i].fi;
		S[v].insert(mp(hs[0][to],hs[1][to]));
	}
}
int main(){
    init();
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; char c; scanf("%d%d %c",&a,&b,&c);
		int cc = c-'a'+1;
		edge[a].pb(mp(b,cc));
	}
	P ans = mp(n,INF);
	dfs(1,-1,0);
	rec(1,-1,0);
	for(int i=1;i<=n;i++){
		ans = min(ans,mp(n-num[i],i));
	}
	cout<<ans.fi<<endl<<ans.sc<<endl;
	return 0;
}