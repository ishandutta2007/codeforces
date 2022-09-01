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
vector<P>edge[1005];
map<P,int>M;
int n;
int dfs(int v,int u){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i].fi==u) continue;
		return dfs(edge[v][i].fi,v);
	}
	return v;
}
int main(){
	cin>>n;
	rep(i,n-1){
		int a,b,c; cin>>a>>b>>c;
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	repn(i,n){
		if(edge[i].size() == 2){
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge[i].size();j++){
			if(i > edge[i][j].fi) continue;
			if(edge[i].size() == 1 && edge[edge[i][j].fi].size() == 1){
				M[mp(i,edge[i][j].fi)] += edge[i][j].sc;
			}
			else if(edge[i].size() == 1){
				int L[2];
				int id = 0;
				rep(ii,edge[edge[i][j].fi].size()){
					int to = edge[edge[i][j].fi][ii].fi;
					if(to == i) continue;
					L[id++] = dfs(to,edge[i][j].fi);
					if(id == 2) break;
				}
				M[mp(min(i,L[0]),max(i,L[0]))] += edge[i][j].sc / 2;
				M[mp(min(i,L[1]),max(i,L[1]))] += edge[i][j].sc / 2;
				M[mp(min(L[0],L[1]),max(L[0],L[1]))] -= edge[i][j].sc / 2;
			}
			else if(edge[edge[i][j].fi].size() == 1){
				int L[2];
				int id = 0;
				rep(ii,edge[i].size()){
					int to = edge[i][ii].fi;
					if(to == edge[i][j].fi) continue;
					L[id++] = dfs(to,i);
					if(id == 2) break;
				}
				M[mp(min(edge[i][j].fi,L[0]),max(edge[i][j].fi,L[0]))] += edge[i][j].sc / 2;
				M[mp(min(edge[i][j].fi,L[1]),max(edge[i][j].fi,L[1]))] += edge[i][j].sc / 2;
				M[mp(min(L[0],L[1]),max(L[0],L[1]))] -= edge[i][j].sc / 2;
			}
			else{
				int L[2];
				int id = 0;
				rep(ii,edge[edge[i][j].fi].size()){
					int to = edge[edge[i][j].fi][ii].fi;
					if(to == i) continue;
					L[id++] = dfs(to,edge[i][j].fi);
					if(id == 2) break;
				}
				int LL[2];
				id = 0;
				rep(ii,edge[i].size()){
					int to = edge[i][ii].fi;
					if(to == edge[i][j].fi) continue;
					LL[id++] = dfs(to,i);
					if(id == 2) break;
				}
				M[mp(min(L[0],LL[0]),max(L[0],LL[0]))] += edge[i][j].sc / 2;
				M[mp(min(L[1],LL[1]),max(L[1],LL[1]))] += edge[i][j].sc / 2;
				M[mp(min(L[0],L[1]),max(L[0],L[1]))] -= edge[i][j].sc / 2;
				M[mp(min(LL[0],LL[1]),max(LL[0],LL[1]))] -= edge[i][j].sc / 2;
			}
		}
	}
	cout << "YES" << endl;
	cout << M.size() << endl;;
	for(auto x:M){
		cout << x.fi.fi << " " << x.fi.sc << " " << x.sc << endl;
	}
}