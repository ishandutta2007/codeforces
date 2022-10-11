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
// typedef int ll;
// #pragma warning("int")
 
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

struct SCC {
  vector<vector<int> > edges, redges;
  vector<bool> used;
  vector<int> order, component;
  int n;

  void init(int _n) {
    n = _n;
    edges = vector<vector<int> >(n);
    redges = vector<vector<int> >(n);
    order.clear();
    component.clear();
  }

  void edge(int u, int v) {
    edges[u].push_back(v);
    redges[v].push_back(u);
  }

  void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
      if (!used[edges[v][i]]) {
        dfs1(edges[v][i]);
      }
    }
    order.push_back(v);
  }

  void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < redges[v].size(); i++) {
      if (!used[redges[v][i]]) {
        dfs2(redges[v][i]);
      }
    }
  }

  vector<vector<int> > run() {
    vector<vector<int> > components;
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs1(i);
      }
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      int v = order[n - 1 - i];
      if (!used[v]) {
        dfs2(v);
        components.push_back(component);
        component.clear();
      }
    }

    return components;
  }
};

// template by maksim1744
struct Factorizer {
    // Factorizer factorizer(prec_n, sp_bound, rng_seed);
    //    prec_n is the bound for sieve (inclusive)
    //    all numbers will first be checked on primes <= sp_bound (if prec_n >= sp_bound)
    //    factorization for one number ~1e18 takes ~13ms

    vector<int> min_prime;
    vector<int> primes;
    int prec_n;
    int sp_bound;

    Factorizer(int prec_n = 1000000, int sp_bound = 100, int64_t rng_seed = -1) :
        prec_n(max(prec_n, 3)),
        sp_bound(sp_bound),
        rng(rng_seed != -1 ? rng_seed : chrono::steady_clock::now().time_since_epoch().count()) {
        min_prime.assign(prec_n + 1, -1);
        for (int i = 2; i <= prec_n; ++i) {
            if (min_prime[i] == -1) {
                min_prime[i] = i;
                primes.push_back(i);
            }
            int k = min_prime[i];
            for (int j : primes) {
                if (j * i > prec_n) break;
                min_prime[i * j] = j;
                if (j == k) break;
            }
        }
    }

    bool is_prime(int64_t n, bool check_small = false) {
        if (n <= prec_n)
            return min_prime[n] == n;

        if (check_small) {
            for (int p : primes) {
                if (p > sp_bound || (int64_t)p * p > n) break;
                if (n % p == 0) return false;
            }
        }

        int s = 0;
        int64_t d = n - 1;
        while (d % 2 == 0) {
            ++s;
            d >>= 1;
        }
        for (int64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
            if (a >= n) break;
            int64_t x = mpow_long(a, d, n);
            if (x == 1 || x == n - 1)
                continue;
            bool composite = true;
            for (int i = 0; i < s - 1; ++i) {
                x = mul_mod(x, x, n);
                if (x == 1)
                    return false;
                if (x == n - 1) {
                    composite = false;
                    break;
                }
            }
            if (composite)
                return false;
        }
        return true;
    }

    vector<pair<int64_t, int>> factorize(int64_t n, bool check_small = false) {
        vector<pair<int64_t, int>> res;
        if (check_small) {
            for (int p : primes) {
                if (p > sp_bound) break;
                if ((int64_t)p * p > n) break;
                if (n % p == 0) {
                    res.emplace_back(p, 0);
                    while (n % p == 0) {
                        n /= p;
                        res.back().second++;
                    }
                }
            }
        }

        if (n == 1) return res;
        if (is_prime(n, false)) {
            res.emplace_back(n, 1);
            return res;
        }

        if (n <= prec_n) {
            while (n != 1) {
                int d = min_prime[n];
                if (res.empty() || res.back().first != d)
                    res.emplace_back(d, 0);
                res.back().second++;
                n /= d;
            }
            return res;
        }

        int64_t d = get_divisor(n);
        auto a = factorize(d, false);
        for (auto &[div, cnt] : a) {
            cnt = 0;
            while (n % div == 0) {
                n /= div;
                ++cnt;
            }
        }
        auto b = factorize(n, false);

        int ia = 0, ib = 0;
        while (ia < a.size() || ib < b.size()) {
            bool choosea;
            if (ia == a.size()) choosea = false;
            else if (ib == b.size()) choosea = true;
            else if (a[ia].first <= b[ib].first) choosea = true;
            else choosea = false;

            res.push_back(choosea ? a[ia++] : b[ib++]);
        }
        return res;
    }

  private:
    mt19937_64 rng;
    int64_t rnd(int64_t l, int64_t r) {
        return uniform_int_distribution<int64_t>(l, r)(rng);
    }

    int64_t mpow_long(int64_t a, int64_t p, int64_t mod) {
        int64_t res = 1;
        while (p) {
            if (p & 1) res = mul_mod(res, a, mod);
            p >>= 1;
            a = mul_mod(a, a, mod);
        }
        return res;
    }

    int64_t mul_mod(int64_t a, int64_t b, int64_t mod) {
        int64_t res = a * b - mod * (int64_t)((long double)1 / mod * a * b);
        if (res < 0) res += mod;
        if (res >= mod) res -= mod;
        return res;
    }

    int64_t get_divisor(int64_t n) {
        auto f = [&](int64_t x) -> int64_t {
            int64_t res = mul_mod(x, x, n) + 1;
            if (res == n) res = 0;
            return res;
        };

        while (true) {
            int64_t x = rnd(1, n - 1);
            int64_t y = f(x);
            while (x != y) {
                int64_t d = gcd(n, abs(x - y));
                if (d == 0)
                    break;
                else if (d != 1)
                    return d;
                x = f(x);
                y = f(f(y));
            }
        }
    }
} ft;

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<pair<pair<ll, ll>, ll>> elist;
ll comp[200005];
bool vis[200005];
ll gv[200005];
vector<pair<ll, ll>> edges[200005];
SCC sc;

ll val[200005];
ll find_one(ll v, ll d) {
	if (val[v] == -1) val[v] = d;
	else return d - val[v];
		
	for (pair<ll, ll> x: edges[v]) {
		ll y = find_one(x.f, d + x.s);
		if (y != -1) return y;
	}
	return -1;
}

bool test(ll v, ll d, ll y) {
	if (val[v] == -1) val[v] = d;
	else return val[v] == d;
	
	for (pair<ll, ll> x: edges[v]) {
		bool b = test(x.f, (d + x.s) % y, y);
		if (!b) return b;
	}
	return 1;
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	sc.init(n);
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y >> z;
		--x; --y;
		elist.push_back(pair{pair{x, y}, z});
		
		sc.edge(x, y);
	}
	
	vector<vector<int>> comps = sc.run();
	
	for (ll i = 0; i < comps.size(); i++) {
		for (ll x: comps[i]) {
			comp[x] = i;
		}
	}
		
	for (pair<pair<ll, ll>, ll> x: elist) {
		pair<ll, ll> r = x.f;
		if (comp[r.f] == comp[r.s]) {
			edges[r.f].push_back({r.s, x.s});
		}
	}
	
	map<ll, vector<pair<int64_t, int>>> prec;
	
	for (ll i = 0; i < n; i++) {
		if (!vis[comp[i]]) {
			if (comps[comp[i]].size() == 1) {
				gv[comp[i]] = -1;
			} else {
				for (ll x: comps[comp[i]]) val[x] = -1;
				ll x = find_one(i, 0);
				
				if (x == -1) {
					gv[comp[i]] = -1;
				} else {
					vector<pair<int64_t, int>> f;
					if (prec.find(x) != prec.end()) f = prec[x];
					else if (comps[comp[i]].size() > 2) f = ft.factorize(x);
					else {
						gv[comp[i]] = x;
						continue;
					}
					
					ll g = 1;
					for (pair<ll, ll> z: f) {
						ll y = 1;
						for (ll zz = 0; zz < z.s; zz++) {
							y *= z.f;
							for (ll x: comps[comp[i]]) val[x] = -1;
							if (test(i, 0, y)) g *= z.f;
						}
					}
					gv[comp[i]] = g;
				}
			}
		}
		vis[comp[i]] = 1;
		
		// cout << "f " << i << " " << comp[i] << " " << gv[comp[i]] << endl;
	}
	
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll v, s, t;
		cin >> v >> s >> t;
		--v;
		
		ll g = gv[comp[v]];
		
		if (g == -1) {
			cout << (s ? "NO\n" : "YES\n");
			continue;
		}
		
		ll gc = __gcd(g, t);
		
		if ((t - s) % gc == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
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
	
	// gen_btree();
		
	int tc = 1;
	// cin >> tc; 	
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}