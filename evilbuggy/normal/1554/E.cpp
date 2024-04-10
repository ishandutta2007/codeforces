#include <bits/stdc++.h>
using namespace std;

const int THR = 15;
const int N = 100005;
const int mod = 998244353;
const int root = 15311432;
const int iroot = 469870224;

vector<int> g[N], fac[N];
int base[1 << 22], ibase[1 << 22];
int dp0[N], dp1[N], deg[N], ans[N], posib[N];

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

inline void init(){
	base[0] = ibase[0] = 1;
	for(int i = 1; i < (1 << 22); i++){
		base[i] = 1LL*base[i - 1]*root%mod;
		ibase[i] = 1LL*ibase[i - 1]*iroot%mod;
	}
	for(int n = 1; n < N; n++){
		for(int m = n; m < N; m += n){
			fac[m].emplace_back(n);
		}
	}
}

inline int power(int a, int b){
	int ret = 1;
	while(b){
		if(b&1)ret = ret*1LL*a%mod;
		a = a*1LL*a%mod;
		b >>= 1;
	}
	return ret;
}
 
inline void fft(vector<int> &a, bool inv){
	int n = a.size();
	for(int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		while(j&bit){
			j ^= bit; bit >>= 1;
		}
		j ^= bit;
		if(i < j){
			swap(a[i], a[j]);
		}
	}
	for(int len = 2; len <= n; len <<= 1){
		int hlen = len >> 1, diff = (1 << 23)/len;
		for(int i = 0; i < n; i += len){
			int cur = 0;
			for(int j = 0; j < hlen; j++){
				int u = a[i + j];
				int v = (a[i + j + hlen]*1LL*(inv?base[cur]:ibase[cur]))%mod;
				a[i + j] = u + v;
				a[i + j + hlen] = u + mod - v;
				cur += diff;
			}
		}
		for(int i = 0; i < n; i++){
			if(a[i] >= mod)a[i] -= mod;
		}
	}
	if(inv){
		int mul = power(n, mod - 2);
		for(int i = 0; i < n; i++){
			a[i] = (a[i]*1LL*mul)%mod;
		}
	}
}

inline vector<int> multiply(const vector<int> &a, const vector<int> &b){
	int sz = 1;
	while(sz < a.size() + b.size())sz <<= 1;
	vector<int> fa(a.begin(), a.end());
	vector<int> fb(b.begin(), b.end());
	fa.resize(sz);
	fb.resize(sz);
	fft(fa, false);
	fft(fb, false);
	for(int i = 0; i < sz; i++){
		fa[i] = fa[i]*1LL*fb[i]%mod;
	}
	fft(fa, true);
	while(!fa.empty() && fa.back() == 0)fa.pop_back();
	return fa;
}

inline vector<int> products(vector<pair<int, int> > &vec, int lo, int hi, int k){
	if(hi - lo <= THR){
		vector<int> ret(hi - lo + 2);
		ret[0] = 1;
		for(int i = lo; i <= hi; i++){
			int a = vec[i].first;
			int b = vec[i].second;
			for(int j = i - lo; j >= 0; j--){
				add(ret[j + 1], b*1LL*ret[j]%mod);
				ret[j] = ret[j]*1LL*a%mod;
			}
		}
		if(ret.size() > k){
			for(int i = k, j = 0; i < (int)ret.size(); i++, j++){
				if(j == k)j = 0;
				add(ret[j], ret[i]);
			}
			ret.resize(k);
		}
		return ret;
	}
	int mi = (lo + hi)/2;
	vector<int> ret = multiply(products(vec, lo, mi, k), products(vec, mi + 1, hi, k));
	if(ret.size() > k){
		for(int i = k, j = 0; i < (int)ret.size(); i++, j++){
			if(j == k)j = 0;
			add(ret[j], ret[i]);
		}
		ret.resize(k);
	}
	return ret;
}

void dfs(int v, int p, int k){
	vector<pair<int, int> > vec;
	for(int u : g[v]){
		if(u != p){
			dfs(u, v, k);
			vec.emplace_back(dp1[u], dp0[u]);
		}
	}
	if(vec.empty()){
		dp1[v] = 1;
		dp0[v] = 0;
		if(k == 1)dp0[v] = 1;
		return;
	}
	int sz = (int)vec.size();
	if(deg[v] < k){
		dp0[v] = dp1[v] = 0;
		if(deg[v] == sz){
			dp0[v] = 1;
			for(auto x : vec){
				dp0[v] = dp0[v]*1LL*x.second%mod;
			}
			vector<int> pref(sz), suff(sz);
			for(int i = 0; i < sz; i++){
				pref[i] = vec[i].second;
				if(i)pref[i] = pref[i - 1]*1LL*pref[i]%mod;
			}
			for(int i = sz - 1; i >= 0; i--){
				suff[i] = vec[i].second;
				if(i + 1 < sz)suff[i] = suff[i + 1]*1LL*suff[i]%mod;
			}
			for(int i = 0; i < sz; i++){
				int tmp = vec[i].first;
				if(i)tmp = tmp*1LL*pref[i - 1]%mod;
				if(i + 1 < sz)tmp = tmp*1LL*suff[i + 1]%mod;
				add(dp1[v], tmp);
			}
		}else{
			// sz = deg[v] - 1
			dp1[v] = 1;
			for(auto x : vec){
				dp1[v] = dp1[v]*1LL*x.second%mod;
			}
		}
		return;
	}
	vector<int> poly = products(vec, 0, sz - 1, k);
	{
		int r = deg[v]%k;
		dp0[v] = 0;
		for(int i = r; i < (int)poly.size(); i += k){
			add(dp0[v], poly[i]);
		}
	}
	{
		int r = (deg[v] + k - 1)%k;
		dp1[v] = 0;
		for(int i = r; i < (int)poly.size(); i += k){
			add(dp1[v], poly[i]);
		}
	}
}

inline int check(int k, int n){
	int tot = 0;
	for(int i = 1; i <= n; i++){
		tot += deg[i]%k;
	}
	return tot < n;
}

inline void solve(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		posib[i] = 0;
	}
	for(int i = 0; i + 1 < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	set<int> st;
	for(int i = 1; i <= n; i++){
		deg[i] = (int)g[i].size();
		st.insert(__gcd(n - 1, deg[i]));
	}
	for(auto x : st){
		for(auto y : fac[x]){
			posib[y] = 1;
		}
	}
	for(int k = 1; k <= n; k++){
		if(!posib[k] || !check(k, n)){
			ans[k] = 0;
		}else{
			dfs(1, 0, k);
			ans[k] = dp0[1];
		}
	}
	for(int i = n; i >= 1; i--){
		for(int j = i + i; j <= n; j += i){
			add(ans[i], mod - ans[j]);
		}
	}
	for(int i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	cout << '\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	init();

	int t;
	cin >> t;
	while(t--)solve();

	return 0;
}