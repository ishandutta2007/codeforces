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
#define ii pair<int,int>
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

int n;
int arr[300005];
map<int,int> m[300005];
int memo[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,n) m[x].clear();
		rep(x,0,n) memo[x]=0;
		
		ll ans=0;
		
		rep(x,n-1,0){
			int pos=-1;
			if (arr[x]==arr[x+1]){
				pos=x+2;
			}
			else if (m[x+1].count(arr[x])){
				pos=m[x+1][arr[x]]+1;
			}
			
			if (pos==-1) continue;
			
			if (pos<n){
				swap(m[x],m[pos]);
				m[x][arr[pos]]=pos;
				memo[x]=memo[pos];
			}
			ans+=++memo[x];
		}
		
		cout<<ans<<endl;
	}
}