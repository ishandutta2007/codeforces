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

int p2[100005];

int n,m;
int arr[100005];
int pos[100005];
vector<int> pref;
vector<int> ppref;
vector<int> pref2;
vector<int> ppref2;

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
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = qexp(n, mod - 2, mod);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int memo[100100];

void dnc(vector<int> v2,vector<int> v,int l){
	if (sz(v)==1) return;
	int m=sz(v)/2;
	
	vector<int> vl,vr;
	vector<int> v2l,v2r;
	
	rep(x,0,m) vl.pub(v[x]),v2l.pub(v2[x]);
	rep(x,m,sz(v)) vr.pub(v[x]),v2r.pub(v2[x]);
	
	auto res=conv(v2l,vr);
	
	rep(x,0,sz(res)){
		int pos=2*l+m+x;
		if (pos%2==1) memo[(pos+1)/2]=(memo[(pos+1)/2]+res[x])%MOD;
	}
	
	dnc(v2l,vl,l);
	dnc(v2r,vr,l+m);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	p2[0]=1;
	rep(x,1,100005) p2[x]=p2[x-1]*2%MOD;
	
	cin>>n>>m;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,0,m) cin>>pos[x];
	pref.resize(n+5);
	rep(x,0,m) pref[pos[x]]++;
	rep(x,1,sz(pref)) pref[x]+=pref[x-1];
	
	int num=pref.back();
	rep(x,0,sz(pref)) pref2.pub(qexp(2,pref[x],MOD));
	rep(x,0,sz(pref)) pref[x]=inv(qexp(2,pref[x],MOD));
	
	rep(x,0,sz(pref)) ppref.pub((pref[x]+(x?ppref[x-1]:0))%MOD);
	rep(x,0,sz(pref2)) ppref2.pub((pref2[x]+(x?ppref2[x-1]:0))%MOD);
	
	int ans=0;
	rep(x,1LL,n+1){
		int sum=2*x-1;
		
		int l1=x-1,l2=x-n;
		int r1=x,r2=x+n-1;
		
		//real things are inside [1,n]
		int extra=min(r2-n,1-l2);
		l2+=extra,r2-=extra;
		memo[x]=extra*pref.back()%MOD*pref2.front();
		
		if (l2<1){
			int len=1-l2;
			memo[x]=(memo[x]+pref2.front()*(ppref[r2]-ppref[r2-len]))%MOD;
			l2+=len,r2-=len;
		}
		if (n<r2){
			int len=r2-n;
			memo[x]=(memo[x]+pref.back()*(ppref2[l2+len-1]-ppref2[l2-1]))%MOD;
			l2+=len,r2-=len;
		}
	}
	
	pref.resize(n+1);
	pref2.resize(n+1);
	pref[0]=pref2[0]=0;
	
	dnc(pref2,pref,0);
	
	//rep(x,1,n+1) cout<<memo[x]<<endl;
	
	rep(x,1,n+1) ans=fix(ans+(qexp(2,num,MOD)*memo[x]-n)%MOD*arr[x]);
	
	cout<<ans*inv(qexp(2,m,MOD)-1)%MOD<<endl;
}