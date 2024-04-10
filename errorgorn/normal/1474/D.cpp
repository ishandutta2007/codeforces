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
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
ll arr[200005];

ll fwd[200005];
ll bwd[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		if (n==1){
			cout<<"NO"<<endl;
			continue;
		}
		
		fwd[0]=0;
		rep(x,1,n+1){
			fwd[x]=arr[x]-fwd[x-1];
			if (fwd[x]<0) fwd[x]=1e18;
		}
		
		bwd[n+1]=0;
		rep(x,n+1,1){
			bwd[x]=arr[x]-bwd[x+1];
			if (bwd[x]<0) bwd[x]=1e18;
		}
		
		bool can=false;
		
		rep(x,1,n){
			ll t1,t2;
			
			t1=arr[x]-fwd[x-1],t2=arr[x+1]-bwd[x+2];
			if (t1>=0 && t2>=0 && t1==t2) can=true;
			swap(arr[x],arr[x+1]);
			
			t1=arr[x]-fwd[x-1],t2=arr[x+1]-bwd[x+2];
			if (t1>=0 && t2>=0 && t1==t2) can=true;
			swap(arr[x],arr[x+1]);
		}
		
		if (can) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}