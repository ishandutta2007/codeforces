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

int n,q;
ll val[6];
ll memo[1000000];

vector<int> parts;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,6) cin>>val[x];
	
	n--;
	n*=3;
	ll curr=1;
	while (curr<=n){
		parts.push_back(curr);
		n-=curr;
		curr<<=1;
	}
	if (n) parts.push_back(n);
	
	memset(memo,128,sizeof(memo));
	memo[0]=0;
	
	curr=1;
	rep(x,0,6){
		for (auto &it:parts){
			rep(y,1000000,0){
				if (y+curr*it*3>=1000000) continue;
				memo[y+curr*it*3]=max(memo[y+curr*it*3],memo[y]+it*val[x]);
			}
		}
		
		rep(y,1000000,0){
			rep(z,1,10){
				if (y+curr*z>=1000000) continue;
				memo[y+curr*z]=max(memo[y+curr*z],memo[y]+(z%3==0?z/3*val[x]:0LL));
			}
		}
		
		curr*=10;
	}
	
	int q,k;
	cin>>q;
	while (q--){
		cin>>k;
		cout<<memo[k]<<endl;
	}
}