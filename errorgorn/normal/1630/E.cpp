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

bool prime[1000005];
ll mu[1000005];

int n;
int arr[1000005];
int cnt[1000005];
vector<int> val;

ll ways[1000005];
ll cc[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	memset(prime,true,sizeof(prime));
	rep(x,1,1000005) mu[x]=1;
	rep(x,2,1000005) if (prime[x]){
		for (int y=x;y<1000005;y+=x){
			mu[y]*=-1;
			if (y%(x*x)==0) mu[y]=0;
			prime[y]=false;
		}
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		
		bool same=true;
		rep(x,1,n+1) if (arr[x]!=arr[1]) same=false;
		if (same){
			cout<<1<<endl;
			continue;
		}
		
		rep(x,1,n+1) cnt[x]=0;
		rep(x,1,n+1) cnt[arr[x]]++;
		
		int g=0;
		val.clear();
		rep(x,1,n+1){
			g=__gcd(g,cnt[x]);
			if (cnt[x]) val.pub(cnt[x]);
		}
		
		vector<int> div;
		rep(x,1,n+1) if (g%x==0) div.pub(x);
		
		for (auto it:div){
			ways[it]=fac[n/it];
			for (auto it2:val) ways[it]=ways[it]*ifac[it2/it]%MOD;
			cc[it]=ways[it];
			ll temp=ways[it]*inv(n/it)%MOD*inv(n/it-1)%MOD;
			for (auto it2:val){
				if (it2>=2) cc[it]=fix(cc[it]-temp*(it2/it)%MOD*(it2/it-1));
			}
			cc[it]=cc[it]*n%MOD;
		}
		
		rep(x,0,sz(div)) rep(y,x+1,sz(div)) if (div[y]%div[x]==0){
			ways[div[x]]=fix(ways[div[x]]+ways[div[y]]*mu[div[y]/div[x]]);
			cc[div[x]]=fix(cc[div[x]]+cc[div[y]]*mu[div[y]/div[x]]);
		}
		
		ll num=0,denom=0;
		rep(x,0,sz(div)){
			num=(num+cc[div[x]]*inv(n/div[x]))%MOD;
			denom=(denom+ways[div[x]]*inv(n/div[x]))%MOD;
		}
		
		cout<<num*inv(denom)%MOD<<endl;
	}
}