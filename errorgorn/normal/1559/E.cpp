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
ii arr[55];

bool prime[100005];
int mobius[100005];
int memo[2][100005];
int pref[100005];

ll get(int i){
	int m=::m/i;
	
	//cout<<"debug: "<<i<<" "<<m/i<<endl;
	
	int a=0,b=1;
	rep(x,0,m+1) memo[a][x]=0;
	memo[a][0]=1;
	
	rep(x,0,n){
		int l=(arr[x].fi+i-1)/i,r=arr[x].se/i;
		if (l>r) return 0;
		
		//cout<<l<<" "<<r<<endl;
		
		pref[0]=memo[a][0];
		rep(x,1,m+1) pref[x]=fix(pref[x-1]+memo[a][x]);
		
		rep(x,0,m+1){
			memo[b][x]=0;
			if (x-l>=0) memo[b][x]=fix(memo[b][x]+pref[x-l]);
			if (x-r-1>=0) memo[b][x]=fix(memo[b][x]-pref[x-r-1]);
		}
		
		//rep(x,0,m+1) cout<<memo[b][x]<<" "; cout<<endl;
		swap(a,b);
	}
	
	ll ans=0;
	rep(x,0,m+1) ans=(ans+memo[a][x])%MOD;
	
	//cout<<ans<<endl;
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	rep(x,1,100005) mobius[x]=1;
	rep(x,1,100005) prime[x]=true;
	rep(x,2,100005) if (prime[x]){
		for (int y=x;y<100005;y+=x){
			if (y%((ll)x*x)==0) mobius[y]=0;
			else mobius[y]*=-1;
			
			prime[y]=false;
		}
	}
	
	//rep(x,1,11) cout<<mobius[x]<<" "; cout<<endl;
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	ll ans=0;
	rep(x,1,m+1) if (mobius[x]){
		ans=fix(ans+mobius[x]*get(x));
	}
	
	cout<<ans<<endl;
}