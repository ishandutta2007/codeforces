//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
//#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
int deg[2005];
vector<ii> edges;

int match[2005][1005];

void dfs(int i,int p,int c1,int c2){
	if (match[i][c1]==-1){
		match[i][c1]=p;
		match[p][c1]=i;
		match[i][c2]=-1;
	}
	else{
		dfs(match[i][c1],i,c2,c1);
		match[i][c1]=p;
		match[p][c1]=i;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	int a,b;
	rep(x,0,k){
		cin>>a>>b;
		
		deg[a]++;
		deg[b+1000]++;
		
		edges.push_back(ii(a,b+1000));
	}
	
	int mx=0;
	rep(x,0,2005) mx=max(mx,deg[x]);
	
	memset(match,-1,sizeof(match));
	for (auto &it:edges){
		int u=it.fi,v=it.se;
			
		int ca,cb;
		rep(y,0,mx){
			if (match[u][y]==-1) ca=y;
			if (match[v][y]==-1) cb=y;
		}
		
		if (match[v][ca]==-1){
			match[u][ca]=v;
			match[v][ca]=u;
		}
		else if (match[u][cb]==-1){
			match[u][cb]=v;
			match[v][cb]=u;
		}
		else{
			dfs(v,u,ca,cb);
		}
	}
		
	map<ii,int> m;
	rep(x,1,n+1){
		rep(y,0,mx){
			if (match[x][y]!=-1) m[ii(x,match[x][y])]=y+1;
		}
	}
	
	cout<<mx<<endl;
	for (auto &it:edges) cout<<m[it]<<" ";
}