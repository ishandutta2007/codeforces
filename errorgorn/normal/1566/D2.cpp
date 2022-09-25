// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
ii arr[100005];
ii pos[100005];
int has[305][305];


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n*m){
			cin>>arr[x].fi;
			arr[x].se=x;
		}
		
		sort(arr,arr+n*m);
		
		for (int x=0;x<n*m;){
			int curr=x;
			while (true){
				curr++;
				if (curr==n*m || arr[x].fi!=arr[curr].fi) break;
			}
			
			vector<ii> v;
			rep(z,x,curr){
				v.pub(ii(z/m,z%m));
			}
			
			sort(all(v),[](ii i,ii j){
				if (i.fi!=j.fi) return i.fi<j.fi;
				else return i.se>j.se;
			});
			
			rep(z,x,curr) pos[arr[z].se]=v[z-x];
			
			x=curr;	
		}
		
		rep(x,0,n) rep(y,0,m) has[x][y]=false;
		
		int ans=0;
		rep(x,0,n*m){
			has[pos[x].fi][pos[x].se]=true;
			rep(y,0,pos[x].se) if (has[pos[x].fi][y]) ans++;
		}
		
		cout<<ans<<endl;
	}
}