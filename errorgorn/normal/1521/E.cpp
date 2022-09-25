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

int m,k;
ii arr[100005];

int grid[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	rep(tc,1,TC+1){
		
		cin>>m>>k;
		
		rep(x,0,k) cin>>arr[x].fi,arr[x].se=x+1;
		
		sort(arr,arr+k);
		reverse(arr,arr+k);
		
		int n=1;
		while (n*n-(n/2)*(n/2)<m || n*((n+1)/2)<arr[0].fi) n++;
		
		vector<ii> proc;
		
		rep(x,0,n) rep(y,0,n){
			grid[x][y]=0;
		}
		
		rep(x,0,n) rep(y,0,n) if (x%2==1 && y%2==0){
			proc.pub(ii(x,y));
		}
		
		rep(x,0,n) rep(y,0,n) if (x%2==0 && y%2==0){
			proc.pub(ii(x,y));
		}
		
		rep(x,0,n) rep(y,0,n) if (x%2==0 && y%2==1){
			proc.pub(ii(x,y));
		}
		
		int idx=0;
		rep(x,0,k) rep(y,0,arr[x].fi){
			grid[proc[idx].fi][proc[idx].se]=arr[x].se;
			idx++;
		}
		
		cout<<n<<endl;
		rep(x,0,n){
			rep(y,0,n) cout<<grid[x][y]<<" ";
			cout<<endl;
		}
	}
	
}