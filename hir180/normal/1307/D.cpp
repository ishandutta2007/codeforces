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

const ll mod = 1000000007;

int n,m,k;
bool sp[200005];
int dist[2][200005];
vector<int>edge[200005];
bool used[200005];
void make(int b,int id){
	rep(i,200005) dist[id][i] = INF;
	rep(i,200005) used[i] = 0;
	
	queue<int>que; que.push(b); dist[id][b] = 0;
	
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(used[q]) continue; used[q] = 1;
		rep(i,edge[q].size()){
			int to = edge[q][i];
			dist[id][to] = min(dist[id][to],dist[id][q]+1);
			if(!used[to]) que.push(to);
		}
	}
}
bool cmp(const P1&a,const P1&b){
    if(a.sc.fi-a.sc.sc != b.sc.fi-b.sc.sc) return a.sc.fi-a.sc.sc < b.sc.fi-b.sc.sc;
    else return a.fi < b.fi;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	repn(i,k){
		int a; scanf("%d",&a); sp[a] = 1;
	}
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	make(1,0);
	make(n,1);
	
	vector<P1>vec;
	repn(i,n){
		if(!sp[i]) continue;
		vec.pb(mp(i,mp(dist[0][i],dist[1][i])));
	}
	sort(vec.begin(),vec.end(),cmp);
	int ans = dist[0][n];
	assert(dist[1][1] == ans);
	
	int cur_max = 0, use_max = 0;
	for(int i=0;i<vec.size();i++){
	    if(i == 0){
	        cur_max = max(cur_max,vec[i].sc.fi);
	    }
	    else{
	        use_max = max(use_max, cur_max+vec[i].sc.sc+1);
	        cur_max = max(cur_max,vec[i].sc.fi);
	    }
	}
	
	ans = min(ans,use_max);
	
	cout << ans << endl;
}