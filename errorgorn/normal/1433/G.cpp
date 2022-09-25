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
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
vector<ii> al[1005];
vector<ii> edges;
ii arr[1005];

int w[1005][1005];
priority_queue<ii,vector<ii>,greater<ii> > pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		a--,b--;
		al[a].push_back(ii(b,c));
		al[b].push_back(ii(a,c));
		edges.push_back(ii(a,b));
	}
	rep(x,0,k){
		cin>>arr[x].fi>>arr[x].se;
		arr[x].fi--,arr[x].se--;
	}
	
	memset(w,63,sizeof(w));
	rep(x,0,n){
		w[x][x]=0;
		pq.push(ii(w[x][x],x));
		
		int node,weight;
		while (!pq.empty()){
			tie(weight,node)=pq.top(),pq.pop();
			
			if (w[x][node]!=weight) continue;
			for (auto &it:al[node]){
				if (w[x][it.fi]>weight+it.se){
					w[x][it.fi]=weight+it.se;
					pq.push(ii(w[x][it.fi],it.fi));
				}
			}
		}
	}
	
	int ans=2e9;
	
	rep(x,0,m){
		int f=edges[x].fi,g=edges[x].se;
		int curr=0;
		
		rep(y,0,k){
			int u=arr[y].fi,v=arr[y].se;
			curr+=min({w[u][v],w[f][u]+w[g][v],w[g][u]+w[f][v]});
		}
		ans=min(ans,curr);
	}
	
	cout<<ans<<endl;
}