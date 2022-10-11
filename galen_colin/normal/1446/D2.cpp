#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef int ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
 
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 200005;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	
 
const ll mx = 302;
const ll C = 675;
ll cnt[mx + 5][mx + 5];
ll freq[200005];
ll ffreq[200005];
vector<ll> pos[mx + 5][mx + 5], neg[mx + 5][mx + 5];
ll lb[mx + 5][mx + 5], ub[mx + 5][mx + 5];
ll stor[200005];
 
void ins(ll a, ll b, ll i) {
	if (a > b) swap(a, b);
	ll v = freq[a] - freq[b];
	if (v < lb[a][b]) {
		neg[a][b][-(lb[a][b]--)] = i;
	} else if (v > ub[a][b]) {
		pos[a][b][++ub[a][b]] = i;
	}
}
 
void expand(ll a, ll b) {
	if (a > b) swap(a, b);
	ll v = freq[a] - freq[b];
	
	if (v < lb[a][b]) --lb[a][b];
	else if (v > ub[a][b]) ++ub[a][b];
}
 
ll get(ll a, ll b) {
	if (a > b) swap(a, b);
	ll v = freq[a] - freq[b];
	if (!(lb[a][b] <= v && v <= ub[a][b])) return 1e9;
	if (v >= 0) return pos[a][b][v];
	else return neg[a][b][-(v + 1)];
}
 
void solve_large() {
	memset(cnt, 0, sizeof(cnt));
	memset(freq, 0, sizeof(freq));
	memset(ub, 0, sizeof(ub));
	memset(lb, 0, sizeof(lb));
	
	for (ll i = 0; i < n; i++) {
		++freq[c[i]];
	}
	
	ll ct = 0;
	for (ll i = 0; i < n; i++) {
		if (freq[i] >= C) {
			stor[i] = ct++;
		}
	}
	
	for (ll i = 0; i < n; i++) {
		if (freq[c[i]] < C) a[i] = 1e8;
		else a[i] = stor[c[i]];
	}
	
	memset(freq, 0, sizeof(freq));
	
	for (ll i = 0; i < n; i++) {
		if (a[i] > 1e7) continue;
		++freq[a[i]];
		for (ll j = 0; j < mx; j++) {
			if (j != a[i]) {
				expand(a[i], j);
			}
		}
	}
	
	memset(freq, 0, sizeof(freq));
	
	for (ll i = 0; i < mx; i++) {
		for (ll j = i; j < mx; j++) {
			pos[i][j] = vector<ll>(ub[i][j] + 1, 1e9);
			neg[i][j] = vector<ll>(-lb[i][j] + 1, 1e9);
			
			ub[i][j] = lb[i][j] = 0;
			
			pos[i][j][0] = -1;
		}
	}
	
	ll mc = 0, mv = 0;
	for (ll i = 0; i < n; i++) {
		if (a[i] < 1e7) {
			++freq[a[i]];
			if (freq[a[i]] > mc) {
				mc = freq[a[i]];
				mv = a[i];
			}
		}
		for (ll j = 0; j < mx; j++) {
			if (j != mv && freq[j] > 0) {
				ans = max(ans, i - get(mv, j));
			}
			if (j != a[i] && a[i] < 1e7) {
				ins(a[i], j, i);
			}
		}
	}
}
 
void solve_small() {
	for (ll sz = 1; sz < C; sz++) {
		memset(freq, 0, sizeof(freq));
		ffreq[sz] = 0;
 
		ll pt = 0;
		bool fl = 0;
		for (ll i = 0; i < n; i++) {
			--ffreq[freq[c[i]]];
			fl |= (++freq[c[i]] == sz + 1);
			++ffreq[freq[c[i]]];
			
			while (fl) {
				--ffreq[freq[c[pt]]];
				fl &= !(--freq[c[pt]] == sz);
				++ffreq[freq[c[pt]]];
				
				++pt;
			}
			
			ans = (ffreq[sz] > 1 && ans < i - pt + 1 ? i - pt + 1 : ans);
		}
	}
}
 
void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> c[i];
		--c[i];
	}
	
	solve_small();	
	solve_large();
	
	// if (n == 200000 && c[0] == 188753 - 1) {
		// memset(freq, 0, sizeof(freq));
		// for (ll i = 0; i < n; i++) ++freq[c[i]];
		// sort(freq, freq + n);
		// reverse(freq, freq + n);
		// for (ll i = 0; i < n; i++) cout << freq[i] << " ";
	// }
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}