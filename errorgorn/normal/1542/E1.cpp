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
#define debug(x) cout << #x << ": " << x << endl

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

int n,MOD;

ll fix (ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll nCk[505][505];
ll fac[505];

const int INV=55*55/2;
int perms[55][INV]; //perms and no. inversion
ll pref[INV];


ll cnt[505]; //diff between a and b

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>MOD;
	
	fac[0]=1;
	rep(x,1,505) fac[x]=(fac[x-1]*x)%MOD;
	
	nCk[0][0]=1;
	rep(x,1,505){
		nCk[x][0]=1;
		rep(y,1,x+1) nCk[x][y]=(nCk[x-1][y-1]+nCk[x-1][y])%MOD;
	}
	
	// rep(x,0,5){
		// rep(y,0,5) cout<<nCk[x][y]<<" "; cout<<endl;
	// } cout<<endl;
	
	perms[0][0]=1;
	
	rep(x,0,54){
		pref[0]=perms[x][0];
		rep(y,1,INV) pref[y]=(pref[y-1]+perms[x][y])%MOD;
		
		rep(y,0,INV){
			perms[x+1][y]=pref[y];
			if (y-x-1>=0) perms[x+1][y]=(perms[x+1][y]-pref[y-x-1]+MOD)%MOD;
		}
	}
	
	// rep(x,0,5){
		// rep(y,0,10) cout<<perms[x][y]<<" "; cout<<endl;
	// } cout<<endl;
	
	ll ans=0;
	
	rep(x,0,n){
		//cout<<x<<endl;
		
		ll curr=0;
		ll count=0;
		rep(y,0,INV){
			curr=(curr+perms[x][y]*count)%MOD;
			count=(count+perms[x][y])%MOD;
		}
		
		cnt[0]=curr;
		rep(y,1,55){
			rep(a,0,INV) if (a+y<INV){
				curr=fix(curr-(ll)perms[x][a]*perms[x][a+y]);
			}
			cnt[y]=curr;
		}
		
		//rep(y,0,5) cout<<cnt[y]<<" "; cout<<endl;
		
		curr=0;
		rep(a,0,x+1) rep(b,a+1,x+1){
			//cout<<a<<" "<<b<<endl;
			curr=(curr+cnt[b-a])%MOD;
		}
		
		//cout<<curr<<endl;
		
		ans=(ans+curr*nCk[n][x+1]%MOD*fac[n-x-1])%MOD;
	}
	
	cout<<ans<<endl;
}