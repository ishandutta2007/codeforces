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

const int MOD=1000000007;

ll n,k;

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

ll fac[400005];
ll ifac[400005];

ll nCk(ll i,ll j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,400005) fac[x]=fac[x-1]*x%MOD;
	rep(x,0,400005) ifac[x]=inv(fac[x])%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		
		int ans=0;
		
		//any | <=k-1 | ... | <=k-1 | any
		rep(x,1,n+1){
			ll use=(x-1)*(k-1)+x;
			
			ll curr=nCk(n-use+x,x);
			
			curr=curr*fac[x]%MOD;
			
			//cout<<x<<" "<<curr<<" "<<ifac[n]*fac[n-x]%MOD<<endl;
			ll perm=ifac[n]*fac[n-x]%MOD;
			ans=(ans+curr%MOD*perm)%MOD;
		}
		
		cout<<(ans+1)%MOD<<endl;
	}
}