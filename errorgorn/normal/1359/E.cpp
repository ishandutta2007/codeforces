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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

const int MOD=998244353;

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll fac[500005];
ll ifac[500005];

ll C(int i,int j){
	if (i<j) return 0;

	return fac[i]*ifac[i-j]%MOD*ifac[j]%MOD;
}


int n,k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fac[0]=1;
	rep(x,1,500005) fac[x]=(fac[x-1]*x)%MOD;
	rep(x,0,500005) ifac[x]=qexp(fac[x],MOD-2,MOD);
	
	cin>>n>>k;
	
	ll ans=0;
	
	rep(x,1,n+1){
		ll val=n/x;
		
		//cout<<x<<" "<<val<<endl;
		
		ans=(ans+C(val-1,k-1))%MOD;
	}
	
	cout<<ans<<endl;
}