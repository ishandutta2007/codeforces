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

ll n,k;
ll arr[100005];
ll f[100005];

map<int,int> cnt;
map<int,int> ccnt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>k;
	rep(x,0,n) cin>>arr[x];
	
	int extra=0;
	rep(x,0,n){
		if (arr[x]==-1) extra++;
		else cnt[arr[x]]++;
	}
	
	for (auto &it:cnt) ccnt[it.se]++;
	ccnt[0]=k-sz(cnt);
	
	rep(x,1,n){
		ll temp=x+(n-2*x+x*k)%MOD*inv(k-1)%MOD*f[x]-x*f[x-1];
		f[x+1]=fix(temp)*inv(n-x)%MOD*(k-1)%MOD;
	}
	
	//rep(x,0,m+1) cout<<f[x]<<" "; cout<<endl;
	
	//rep(x,0,n+1) cout<<f[x]<<" "; cout<<endl;
	
	ll ans=f[n];
	
	ll in=inv(k),out=MOD+1-inv(k);
	
	for (auto &it:ccnt){
		rep(x,0,extra+1){
			ans=fix(ans-f[it.fi+x]*it.se%MOD*nCk(extra,x)%MOD*qexp(in,x,MOD)%MOD*qexp(out,extra-x,MOD));
		}
	}
	
	cout<<ans*k%MOD*inv(k-1)%MOD<<endl;
}