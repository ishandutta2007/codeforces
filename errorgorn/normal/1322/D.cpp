//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
int arr[2005];
int w[2005];
int w2[4005];

ll memo[2055][2055]; //level, number

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) cin>>w[x];
	rep(x,1,n+m+1) cin>>w2[x];
	
	reverse(arr,arr+n);
	reverse(w,w+n);
	
	memset(memo,128,sizeof(memo));
	
	memo[0][0]=0;
	
	rep(x,0,n){
		rep(y,0,2054) memo[y+1][0]=max(memo[y+1][0],memo[y][0]);
		
		rep(y,2055,0) if (memo[arr[x]][y] > -1e10){
			ll curr=arr[x];
			ll num=y+1;
			ll extra=-w[x]+w2[arr[x]];
			
			while (true){
				//cout<<curr<<" "<<num<<" "<<memo[arr[x]][y]+extra<<endl;
				memo[curr][num]=max(memo[curr][num],memo[arr[x]][y]+extra);
				if (num==0) break;
				num>>=1;
				curr++;
				extra+=num*w2[curr];
			}
		}
	}
	
	ll ans=0;
	rep(x,0,2055) ans=max(ans,memo[x][0]);
	cout<<ans<<endl;
}