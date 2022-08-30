//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const int mod = 1000000007;
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
template<class T>
T mul(T a, T b){
	return (T) ((ll)(a) * b % mod);
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
template<class T>
vector<T>BerlekampMassey(vector<T>x){
	vector<T>ls,cur;
	T lf,ld;
	rep(i,x.size()){
		T t = 0;
		for(int j=0;j<cur.size();j++){
			t = (t+(ll)x[i-j-1]*cur[j])%mod;
		}
		if( ((t-x[i])%mod+mod)%mod == 0 ) continue;
		if(!cur.size()){
			cur.resize(i+1); lf = i; ld = (t-x[i])%mod;
			continue;
		}
		T k = (ll) -(x[i]-t)*modpow(ld,mod-2)%mod;
		vector<T>c(i-lf-1);
		c.pb(k);
		rep(j,ls.size()) c.pb((ll)-ls[j]*k%mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		rep(j,cur.size()){
			c[j]=(c[j]+cur[j]);
			while(c[j] < 0) c[j] += mod;
			while(c[j] >= mod) c[j] -= mod;
		}
		if(i-lf+(int)(ls.size()) >= (int)(cur.size())){
			ls = cur, lf = i, ld = (t-x[i])%mod;
		}
		cur = c;
	}
	rep(i,cur.size()) cur[i] = (cur[i]%mod+mod)%mod;
	return cur;
}

vector<int>rand_vec(int n, int seed = -1){
	if(seed == -1) seed = n;
	mt19937 mt(seed);
	vector<int>ret(n);
	rep(i, n) ret[i] = mt() % (mod-1) + 1;
	return ret;
}
int dot(vector<int>&a, vector<int>&b){
	int ret = 0;
	rep(i, a.size()) add(ret, mul(a[i], b[i]));
	return ret;
}
vector<int>find_min_poly(int n, vector<P1>mat){
	srand((unsigned)time(NULL));
	vector<int>M = rand_vec(n), R = rand_vec(n);
	vector<int>test(2*n);
	rep(i, 2*n){
		test[i] = dot(M, R);
		vector<int>nw(n);
		rep(j, mat.size()){
			int r = mat[j].sc.fi, c = mat[j].sc.sc;
			add(nw[r], mul(mat[j].fi, M[c]));
		}
		swap(nw, M);
	}
	vector<int>ret = BerlekampMassey(test);
	for(int i=0;i<ret.size();i++){
		if(ret[i]) ret[i] = mod-ret[i];
	}
	reverse(all(ret));
	ret.pb(1);
	return ret;
}
int calc_det(int n, vector<P1>mat){
	srand((unsigned)time(NULL));
	while(1){
		vector<int>M = rand_vec(n);
		vector<P1>cp = mat;
		rep(j, mat.size()){
			int r = mat[j].sc.fi, c = mat[j].sc.sc;
			cp[j].fi = mul(cp[j].fi, M[c]);
		}
		vector<int>ret = find_min_poly(n, cp);
		if(ret[0] == 0) return 0;
		if(ret.size() != n+1) continue;
		int ans = (n%2 == 0 ? ret[0] : mod-ret[0]);
		int d1 = 1;
		for(auto a:M) d1 = mul(d1, a);
		d1 = modpow(d1, mod-2);
		return (mul(ans, d1)%mod+mod)%mod;
	}
}
int n, k;
vector<P1>m;
int deg[10005];
int main(){
	scanf("%d%d",&n, &k);
	repn(i, k) repn(j, i-1){
		if(i != n){
			m.pb(mp(mod-1, mp(j-1, i-1)));
			m.pb(mp(mod-1, mp(i-1, j-1)));
		}
		deg[i]++; deg[j]++;
	}
	for(int i=k+1;i<=n;i++){
		rep(j, k){
			int a; scanf("%d", &a);
			if(i != n){
				m.pb(mp(mod-1, mp(a-1, i-1)));
				m.pb(mp(mod-1, mp(i-1, a-1)));
			}
			deg[a]++; deg[i]++;
		}
	}
	repn(i, n-1) m.pb(mp(deg[i], mp(i-1, i-1)));
	
	printf("%d\n", calc_det(n-1, m));
}