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

const int B=20;
const int AF=(1<<B)-1;

const int MOD=1000000007;

int n;
int arr[1000005];
int memo[1<<B+5];
int p2[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	p2[0]=1;
	rep(x,1,1000005) p2[x]=p2[x-1]*2%MOD;
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n) memo[arr[x]^AF]++;
	
	rep(bit,0,B){
		rep(x,0,1<<B){
			if (x&(1<<bit)) memo[x]+=memo[x^(1<<bit)];
		}
	}
	
	//rep(x,0,1<<B) cout<<memo[x]<<" "; cout<<endl;
	
	ll ans=0;
	rep(x,0,1<<B){
		if (__builtin_parity(x)==(B&1)) ans=(ans+p2[memo[x]])%MOD;
		else ans=(ans-p2[memo[x]]+MOD)%MOD;
	}
	
	cout<<ans<<endl;
}