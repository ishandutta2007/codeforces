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

const int MOD=1000000007;

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

ll n,k;
ll p[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	ll ans=0;
	ll c1=1;
	
	rep(x,1,min(n,k)+1){
		c1=c1*(n-x+1)%MOD*inv(x)%MOD;
		
		p[x]=qexp(x,k,MOD)%MOD;

		
		ll c2=1;
		rep(y,1,x){
			c2=c2*(x-y+1)%MOD*inv(y)%MOD;
			p[x]=(p[x]-(p[y]*c2)%MOD+MOD)%MOD;
		}
		
		//cout<<p[x]<<endl;
		//cout<<p[x]*c1*qexp(2,n-x,MOD)<<endl;
		//cout<<endl;
		
		ans=(ans+p[x]*c1%MOD*qexp(2,n-x,MOD))%MOD;
	}
	
	cout<<ans<<endl;
}