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
int arr[405][405];
vector<ii> stk[160005];

ll mx[405];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) rep(y,0,m) cin>>arr[x][y];
	
	ll ans=0;
	rep(y,0,m){
		rep(x,0,n) mx[x]=m-1;
		
		rep(x,0,160005) stk[x].clear();
		
		rep(x,0,n){
			rep(y1,y,m){
				int temp=arr[x][y1];
				
				while (!stk[temp].empty() && stk[temp].back().fi>=y1){
					mx[stk[temp].back().se]=
						min(mx[stk[temp].back().se],stk[temp].back().fi-1);
					stk[temp].pob();
				}
				if (!stk[temp].empty()){
					mx[stk[temp].back().se]=
						min(mx[stk[temp].back().se],y1-1LL);
				}
				stk[temp].pub({y1,x});
			}
			
			rep(x1,x,0) mx[x1]=min(mx[x1],mx[x1+1]);
			
			rep(x1,0,x+1){
				ans=max(ans,(x-x1+1)*(mx[x1]-y+1));
			}
		}
	}
	cout<<ans<<endl;
}