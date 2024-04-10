//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
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

ll fac[1000005];
ll ifac[1000005];

int n;
int arr[5005];
int val[5005];
int memo[10100];

signed main(){
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
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		rep(x,1,n+1){
			if (arr[x-1]!=arr[x]){
				val[x]=0;
				int y=x;
				while (y<=n && arr[x]==arr[y]){
					val[x]++;
					y++;
				}
			}
			else{
				val[x]=0;
			}
		}
		
		memset(memo,0,sizeof(memo));
		
		rep(x,1,n+1){
			rep(y,0,n+1){
				int temp=0;
				if (x>=2 && y==x-2) temp=(temp+x-1)%MOD;
				temp=(temp+memo[x-y+5000])*val[x]%MOD;
				
				if (x==n && y==0){
					int ans=temp;
					rep(x,1,n+1) if (val[x]) ans=ans*ifac[val[x]]%MOD;
					cout<<ans<<endl;
				}
				temp=temp*y%MOD;
				
				memo[x-y+2+5000]=(memo[x-y+2+5000]+temp)%MOD;
			}
		}
	}
}