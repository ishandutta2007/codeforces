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

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n,m;
string grid[405];
int pref[405][405];

int side[405];
int mid[405];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,1,n+1) cin>>grid[x];
		
		rep(y,0,m){
			rep(x,1,n+1) pref[x][y]=pref[x-1][y]+(grid[x][y]=='1');
		}
		
		int ans=1e9;
		rep(x1,0,n+1-5) rep(x2,x1+5,n+1){
			rep(y,0,m) side[y]=(x2-x1-2)-(pref[x2-1][y]-pref[x1+1][y]);
			rep(y,0,m) mid[y]=pref[x2-1][y]-pref[x1+1][y]+(grid[x2][y]=='0')+(grid[x1+1][y]=='0');
			
			int curr=1e9;
			rep(y,3,m){
				curr=min(curr,side[y-3]+mid[y-2]);
				curr+=mid[y-1];
				ans=min(ans,curr+side[y]);
			}
		}
		
		cout<<ans<<endl;
	}
}