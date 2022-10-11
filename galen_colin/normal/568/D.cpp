#include "bits/stdc++.h"
using namespace std;

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
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
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
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



ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<ll, ll>> res;
vector<pair<ll, ll>> cur;
vector<pair<pair<ll, ll>, pair<ll, ll>>> lines;
map<pair<pair<ll, ll>, pair<ll, ll>>, vector<ll>> isect;
vector<pair<ll, pair<ll, ll>>> cand;
bool tried[100005];
bool done[100005];

void dfs(ll pos, ll mask, ll cnt) {
	if (cnt <= k) {
		if (mask == (1 << lines.size()) - 1) {
			for (pair<ll, ll> x: cur) res.push_back(x);
			
			assert(cur.size() <= k);
			cout << "YES\n";
			cout << res.size() << '\n';
			for (pair<ll, ll> x: res) {
				++x.f;
				if (x.s > -1) ++x.s;
				cout << x.f << " " << x.s << '\n';
			}
			exit(0);
		}
	} else return;
	
	// ll cv = __builtin_popcountll(mask);
	// if (cv + (k - cnt) * k < lines.size()) return;
	
	for (ll i = pos; i < cand.size(); i++) {
		ll nmask = mask | cand[i].f;
		cur.push_back(cand[i].s);
		dfs(i + 1, nmask, cnt + 1);
		cur.pop_back();
	}
}

ll gcd(ll x, ll y) {
	if (x == 0 || y == 0) return x ^ y;
	return __gcd(x, y);
}

const ll sent = 1e15;
pair<pair<ll, ll>, pair<ll, ll>> touch(pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) {
	ll nx, dx, ny, dy;
	if (b.f.s != 0) {
		nx = b.s.f * a.f.s - a.s.f * b.f.s;
		dx = b.f.f * a.f.s - a.f.f * b.f.s;
	} else {
		swap(a, b);
		nx = b.s.f * a.f.s - a.s.f * b.f.s;
		dx = b.f.f * a.f.s - a.f.f * b.f.s;
		swap(a, b);
	}
	
	if (b.f.f != 0) {
		ny = b.s.f * a.f.f - a.s.f * b.f.f;
		dy = b.f.s * a.f.f - a.f.s * b.f.f;
	} else {
		swap(a, b);
		ny = b.s.f * a.f.f - a.s.f * b.f.f;
		dy = b.f.s * a.f.f - a.f.s * b.f.f;
		swap(a, b);
	}
	
	if (dx == 0 || dy == 0) return pair{pair{sent, sent}, pair{sent, sent}};
	if (nx == 0) dx = 1;
	if (ny == 0) dy = 1;
	if (nx < 0) {
		nx *= -1;
		dx *= -1;
	}
	if (ny < 0) {
		ny *= -1;
		dy *= -1;
	}
	ll gx = gcd(nx, dx);
	nx /= gx;
	dx /= gx;
	ll gy = gcd(ny, dy);
	ny /= gy;
	dy /= gy;
	return pair{pair{nx, dx}, pair{ny, dy}};
}

void solve(int tc = 0) {
	cin >> n >> k;
	
	for (ll i = 0; i < n; i++) {
		pair<pair<ll, ll>, pair<ll, ll>> x;
		cin >> x.f.f >> x.f.s >> x.s.f;
		x.s.s = i;
		lines.push_back(x);
	}
	
	bool have = 1;
	while (have && lines.size() > 0 && k > 0) {
		have = 0;
		memset(tried, 0, sizeof(tried));
		for (ll it = 0; it < 100; it++) {
			ll targ = -1;
			ll itt = 0;
			for (itt = 0; itt < 10000; itt++) {
				targ = rng() % lines.size();
				if (!tried[lines[targ].s.s]) break;
			}
			if (tried[lines[targ].s.s]) continue;
			
			pair<pair<ll, ll>, pair<ll, ll>> x = lines[targ];
			tried[x.s.s] = 1;
			
			isect.clear();
			for (pair<pair<ll, ll>, pair<ll, ll>> y: lines) {
				if (y.s.s != x.s.s) {
					pair<pair<ll, ll>, pair<ll, ll>> z = touch(x, y);
					
					// cout << x << " " << y << " " << z << endl;
					
					if (z.f.f != sent) {
						isect[z].push_back(y.s.s);
					}
				}
			}
						
			for (pair<pair<pair<ll, ll>, pair<ll, ll>>, vector<ll>> y: isect) {
				// cout << x << " " << y << endl;
				if (y.s.size() + 1 > k) {
					have = 1;
					
					res.push_back({x.s.s, y.s[0]});
					
					vector<pair<pair<ll, ll>, pair<ll, ll>>> nlines;
					done[x.s.s] = 1;
					for (ll z: y.s) done[z] = 1;
					for (pair<pair<ll, ll>, pair<ll, ll>> z: lines) {
						if (!done[z.s.s]) nlines.push_back(z);
					}
					lines = nlines;
					--k;
					
					break;
				}
			}
			if (have) break;
		}
	}
	
	// cout << lines << endl;
		
	if (lines.size() > k * k) {
		cout << "NO\n";
		return;
	}
	
	vector<pair<pair<pair<ll, ll>, pair<ll, ll>>, pair<ll, ll>>> pos;
	for (ll i = 0; i < lines.size(); i++) {
		cand.push_back(pair{1 << i, pair{lines[i].s.s, -1}});
		for (ll j = i + 1; j < lines.size(); j++) {
			pair<pair<ll, ll>, pair<ll, ll>> r = touch(lines[i], lines[j]);
			if (r.f.f != sent) {
				pos.push_back(pair{r, pair{lines[i].s.s, lines[j].s.s}});
			}
		}
	}
	
	set<pair<pair<ll, ll>, pair<ll, ll>>> vis;
	
	for (pair<pair<pair<ll, ll>, pair<ll, ll>>, pair<ll, ll>> x: pos) {
		if (vis.find(x.f) != vis.end()) continue;
		vis.insert(x.f);
		ll mask = 0;
		
		for (ll i = 0; i < lines.size(); i++) {
			pair<pair<ll, ll>, pair<ll, ll>> y = lines[i];
			if (y.f.f * x.f.f.f * x.f.s.s + y.f.s * x.f.s.f * x.f.f.s == y.s.f * x.f.f.s * x.f.s.s) {
				mask += (1 << i);
			}
		}
		
		cand.push_back(pair{mask, x.s});
	}
	// cout << lines << " " << cand << endl;
	
	dfs(0, 0, 0);
	
	cout << "NO\n";
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
	// freopen("tc2.cpp", "w", stdout);
 		
	cout << setprecision(15) << fixed;
							
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}