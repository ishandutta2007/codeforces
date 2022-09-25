// Super Idol
//    
//  
//    
//  105C
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

int n;
int arr[14];
int memo[1<<14];
int prob[14][14];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) rep(y,0,n) prob[x][y]=arr[x]*inv(arr[x]+arr[y])%MOD;
	
	int ans=0;
	rep(x,1,1<<n){
		memo[x]=1;
		for (int y=(x-1)&x;y;y=(y-1)&x){
			int p=memo[y];
			rep(a,0,n) if ((x&y)&(1<<a))
				rep(b,0,n) if ((x^y)&(1<<b)){
					
				p=p*prob[a][b]%MOD;
			}
		
			memo[x]=(memo[x]-p+MOD)%MOD;
		}
		
		int p=memo[x];
		int af=(1<<n)-1;
		
		rep(a,0,n) if ((af&x)&(1<<a))
			rep(b,0,n) if ((af^x)&(1<<b)){
				
			p=p*prob[a][b]%MOD;
		}
		
		ans=(ans+__builtin_popcount(x)*p)%MOD;
	}
	cout<<ans<<endl;
}