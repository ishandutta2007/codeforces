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

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll n,k,l;

ll memo[4005][4005];

ll dp(ll i,ll j){
	if (i==0) return 0;
	if (memo[i][j]!=-1) return memo[i][j];
	
	ll res=0;
	
	if (j) res=(res+j*dp(i-1,j-1))%MOD;
	if (i!=j) res=(res+(i-j)*dp(i-1,j+1))%MOD;
	
	res=(res*inv(i))%MOD;
	
	if (j>=k) res=(res+1)%MOD;
	
	//cout<<i<<" "<<j<<" "<<res<<endl;
	return memo[i][j]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k>>l;
	
	memset(memo,-1,sizeof(memo));
	cout<<dp(2*n,0)*inv(2*n+1)%MOD*l%MOD<<endl;
}