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
int arr[200005];
vector<ii> val[2500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(l,1,n){
		rep(x,0,n-l){
			int y=x+l;
			int temp=abs(arr[x]-arr[y]);
			for (auto &it:val[temp]){
				if (it.fi!=x && it.se!=x && it.fi!=y && it.se!=y){
					cout<<"YES"<<endl;
					
					if (arr[x]>arr[y]) swap(x,y);
					if (arr[it.fi]>arr[it.se]) swap(it.fi,it.se);
					
					cout<<it.fi+1<<" "<<y+1<<" "<<x+1<<" "<<it.se+1<<endl;
					return 0;
				}
			}
			val[temp].pub(ii(x,y));
		}
	}
	
	cout<<"NO"<<endl;
}