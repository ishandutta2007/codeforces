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

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, qexp(root, mod >> s, mod)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vector<int> rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
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

int n;
string s[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>s[x];
	
	ll ans=0;
	
	bool ok=true;
	rep(x,0,n){ //all WB
		if (s[x][0]=='B' || s[x][1]=='W') ok=false; 
	}
	if (ok) ans++;
	ok=true;
	rep(x,0,n){ //all BW
		if (s[x][0]=='W' || s[x][1]=='B') ok=false;
	}
	if (ok) ans++;
	
	//now the only cases we need to check is that BB=WW and BB>1
	
	int pad=1<<18;
	vector<vl > v= {
		{0,0,1},
		{1,0,0},
		{0,1,1},
		{1,1,0},
		{1,2,1}
	};
	
	for (auto &it:v){
		it.resize(pad);
		ntt(it);
	}
	
	int arr[5]={0,0,0,0,0};
	
	rep(x,0,n){
		sort(all(s[x]));
		if (s[x]=="BB") arr[0]++;
		if (s[x]=="WW") arr[1]++;
		if (s[x]=="?B") arr[2]++;
		if (s[x]=="?W") arr[3]++;
		if (s[x]=="??") arr[4]++;
	}
	
	rep(x,0,5) rep(y,0,pad) v[x][y]=qexp(v[x][y],arr[x],MOD);
	
	vl ifft(pad);
	rep(x,0,pad){
		ll temp=1;
		rep(y,0,5){
			temp=(temp*v[y][x])%MOD;
		}
		ifft[-x&(pad-1)]=temp*inv(pad)%MOD;
	}
	
	ntt(ifft);
	
	ll extra=0;
	
	int sz=0;
	rep(x,0,5) sz+=arr[x];
	ans=(ans+ifft[sz])%MOD;

	//we overcounted those with BB=WW=0
	
	extra=1;
	rep(x,0,n){
		if (s[x]=="BB") extra=0;
		if (s[x]=="WW") extra=0;
		if (s[x]=="?B") ;
		if (s[x]=="?W") ;
		if (s[x]=="??") extra=(extra*2)%MOD;
	}
	
	cout<<fix(ans-extra)<<endl;
}