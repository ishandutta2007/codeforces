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
int arr[200005];
ii brr[200005];
vector<ii> ranges[200005];
vector<int> memo[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,m) cin>>brr[x].fi>>brr[x].se;
		
		rep(x,0,n+1) ranges[x].clear();
		
		sort(arr,arr+n);
		sort(brr,brr+m,[](ii i,ii j){
			return i.se<j.se;
		});
		
		int mx=-1e9-100;
		
		rep(x,0,m){
			if (mx<brr[x].fi){
				auto it=lb(arr,arr+n,brr[x].fi);
				if (it==arr+n || brr[x].se<(*it)){
					ranges[it-arr].pub({brr[x].fi,brr[x].se});
				}
				mx=brr[x].fi;
			}
		}
		
		rep(x,0,n+1){
			// cout<<x<<": ";
			// for (auto it:ranges[x]) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
			
			memo[x]=vector<int>(sz(ranges[x])+1,1e18);
		}
		
		memo[0][0]=0;
		
		rep(x,0,n){
			int mn=memo[x].back(); //go there
			int mn2=memo[x].back(); //go there come back
			
			rep(y,0,sz(memo[x])-1){
				mn=min(mn,memo[x][y]+arr[x]-ranges[x][y].se);
				mn2=min(mn2,memo[x][y]+2*(arr[x]-ranges[x][y].se));
			}
			
			memo[x+1][0]=mn;
			rep(y,0,sz(memo[x+1])-1){
				memo[x+1][y+1]=min(	
					mn+2*(ranges[x+1][y].fi-arr[x]),
					mn2+(ranges[x+1][y].fi-arr[x])		
				);
			}
		}
		
		cout<<memo[n].back()<<endl;
	}
}