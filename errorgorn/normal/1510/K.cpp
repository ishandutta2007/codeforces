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

int n;
int arr[2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,2*n) cin>>arr[x];
	
	bool good=true;
	rep(x,0,2*n) if (arr[x]!=x+1) good=false;
	if (good){
		cout<<0<<endl;
		return 0;
	}
	
	int a1=0,a2=2*n;
	
	int ans=1e9;
	
	rep(x,0,2*n){
		if (x%2==0){
			rep(x,0,n) swap(arr[x],arr[x+n]);
		}
		else{
			rep(x,0,n) swap(arr[x*2],arr[x*2+1]);
		}
		
		good=true;
		rep(x,0,2*n) if (arr[x]!=x+1) good=false;
		
		a1++;
		if (good){
			ans=min(ans,a1);
		}
	}
	
	a1=0;
	rep(x,0,2*n){
		if (x%2==1){
			rep(x,0,n) swap(arr[x],arr[x+n]);
		}
		else{
			rep(x,0,n) swap(arr[x*2],arr[x*2+1]);
		}
		
		good=true;
		rep(x,0,2*n) if (arr[x]!=x+1) good=false;
		
		a1++;
		if (good){
			ans=min(ans,a1);
		}
	}
	
	if (ans!=1e9) cout<<ans<<endl;
	else cout<<"-1"<<endl;
}