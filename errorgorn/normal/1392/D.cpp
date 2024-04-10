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

ll n;
string s;

ll memo[200005];
ll get(){
	//cout<<s<<endl;
	
	memo[0]=0;
	memo[1]=1e18;
	memo[2]=memo[0]+(s[1]!='R')+(s[0]!='L');
	memo[3]=min(memo[1]+(s[2]!='R')+(s[1]!='L'),
			memo[0]+(s[2]!='R')+(s[0]!='L'));
	
	rep(x,3,n+1){
		memo[x+1]=min({memo[x-1]+(s[x]!='R')+(s[x-1]!='L'),
			memo[x-2]+(s[x]!='R')+(s[x-2]!='L'),
			memo[x-3]+(s[x]!='R')+(s[x-1]!='R')+(s[x-2]!='L')+(s[x-3]!='L')});
	}
	
	//cout<<memo[n]<<endl;
	return memo[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s;
		
		ll ans=1e18;
		
		rep(x,0,5){
			ans=min(ans,get());
			rep(x,0,n-1) swap(s[x],s[x+1]);
		}
		
		cout<<ans<<endl;
	}
}