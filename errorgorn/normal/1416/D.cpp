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

int n,m,q;
int arr[200005];
ii edges[300005];

ii qq[500005];
ii mov[500005];

set<int> comp[200005];
int id[200005];

set<ii,greater<ii> > vals[200005];

bool in[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,m) cin>>edges[x].fi>>edges[x].se;
	rep(x,0,m) edges[x].fi--,edges[x].se--;
	rep(x,0,q) cin>>qq[x].fi>>qq[x].se;
	rep(x,0,q) qq[x].se--;
	
	rep(x,0,n){
		comp[x].insert(x);
		id[x]=x;
	}
	
	memset(in,true,sizeof(in));
	memset(mov,-1,sizeof(mov));
	
	rep(x,0,q) if (qq[x].fi==2) in[qq[x].se]=false;
	
	rep(x,0,m) if (in[x]){
		int u=id[edges[x].fi],v=id[edges[x].se];
		if (id[u]!=id[v]){
			if (sz(comp[u])<sz(comp[v])) swap(u,v);
			
			for (auto &it:comp[v]){
				comp[u].insert(it);
				id[it]=u;
			}
			
			//rep(x,0,n) cout<<id[x]<<" "; cout<<endl;
		}
	}
	
	rep(x,q,0) if (qq[x].fi==2){
		int u=id[edges[qq[x].se].fi],v=id[edges[qq[x].se].se];
		if (id[u]!=id[v]){
			if (sz(comp[u])<sz(comp[v])) swap(u,v);
			
			for (auto &it:comp[v]){
				comp[u].insert(it);
				id[it]=u;
			}
			
			mov[x]=ii(u,v);
		}
	}
	
	rep(x,0,n){
		vals[id[x]].insert(ii(arr[x],x));
	}
	
	//rep(x,0,n) cout<<id[x]<<" "; cout<<endl;
	
	rep(x,0,q){
		if (qq[x].fi==1){
			int grp=id[qq[x].se];
			
			if (vals[grp].empty()){
				cout<<0<<endl;
				continue;
			}
			
			auto temp=vals[grp].begin();
			cout<<(*temp).fi<<endl;
			arr[(*temp).se]=0;
			vals[grp].erase(temp);
		}
		else{
			if (mov[x]==ii(-1,-1)) continue;
			
			int u=mov[x].fi,v=mov[x].se;
			
			for (auto &it:comp[v]){
				comp[u].erase(it);
				
				if (arr[it]){
					vals[u].erase(ii(arr[it],it));
					vals[v].insert(ii(arr[it],it));
				}
				
				id[it]=v;
			}
			//cout<<u<<" "<<v<<endl;
		}
	}
	
}