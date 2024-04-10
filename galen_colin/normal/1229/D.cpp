#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;


 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> p[200005];
vector<ll> ord[125];
ll rev[5005];
pair<ll, ll> has[125];
ll trans[125][125];

ll ghash(vector<ll> p) {
	ll r = 1, s = 0;
	for (ll x: p) {
		s += r * x;
		r *= k;
	}
	return s;
}

vector<ll> apply(vector<ll> a, vector<ll> p) {
	vector<ll> b(k);
	for (ll i = 0; i < k; i++) {
		b[i] = a[p[i]];
	}
	return b;
}

void solve(int tc = 0) {
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		p[i] = vector<ll>(k);
		for (ll j = 0; j < k; j++) {
			cin >> p[i][j];
			--p[i][j];
		}
	}
	
	vector<ll> aa(k);
	iota(aa.begin(), aa.end(), 0);
	ll cnt = 0;
	do {
		ll h = ghash(aa);
		rev[h] = cnt;
		ord[cnt] = aa;
		
		++cnt;
	} while (next_permutation(aa.begin(), aa.end()));
	
	for (ll i = 0; i < cnt; i++) {
		for (ll j = 0; j < cnt; j++) {
			trans[i][j] = rev[ghash(apply(ord[i], ord[j]))];
		}
	}
	
	for (ll i = 0; i < cnt + 1; i++) has[i] = make_pair(n + 1, -1);
	
	for (ll i = n - 1; i >= 0; i--) {
		b[i] = ghash(p[i]);
		a[i] = rev[b[i]];
		
		ll pos;
		for (ll j = 0; j < cnt + 1; j++) {
			pos = j;
			if (has[j].s == a[i] || has[j].s == -1) {
				break;
			}
		}
				
		for (ll j = pos; j > 0; j--) {
			swap(has[j], has[j - 1]);
		}
		
		has[0] = make_pair(i, a[i]);
		
		while (has[pos].s != -1) ++pos;
		
		vector<pair<ll, ll>> last = vector<pair<ll, ll>>(pos + 1);
		for (ll j = 0; j < pos; j++) last[j] = has[j];
		last[pos] = make_pair(n, -1);
		
		bool ppos[125];
		memset(ppos, 0, sizeof(ppos));
		ll can[250], cp = 1;
		memset(can, 0, sizeof(can));
		ll basis[100], bp = 0;
		
		ppos[0] = 1;
						
		for (ll j = 0; j + 1 < last.size(); j++) {
			ll sz = last[j + 1].f - last[j].f;
			
			if (!ppos[last[j].s]) {
				basis[bp++] = last[j].s;
				for (ll k = 0; k < cp; k++) {
					for (ll l = 0; l < bp; l++) {
						ll ov = trans[can[k]][basis[l]];
						if (!ppos[ov]) {
							ppos[ov] = 1;
							can[cp++] = ov;
						}
					}
				}
			}
			
			ans += cp * sz;
		}
	}
	
	cout << ans << endl;
	exit(0);
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