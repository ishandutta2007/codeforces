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
 
// typedef long long ll;
typedef int ll;
#pragma warning("int")
 
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

// factorizer by maksim1744
struct Factorizer {
    // Factorizer factorizer(prec_n, sp_bound, rng_seed);
    //    prec_n is the bound for sieve (inclusive)
    //    all numbers will first be checked on primes <= sp_bound (if prec_n >= sp_bound)
    //    factorization for one number ~1e18 takes ~13ms
 
    vector<int> min_prime;
    vector<int> primes;
    int prec_n;
    int sp_bound;
 
    Factorizer(int prec_n = 100, int sp_bound = 100, int64_t rng_seed = -1) :
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
 
    bool is_prime(int64_t n, bool check_small = true) {
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
 
    vector<pair<int64_t, int>> factorize(int64_t n, bool check_small = true) {
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
};

template<typename int_t>
struct sparse {
	const int LG = 20;
	vector<vector<int_t>> st;
	vector<int> sp2;
	
	void init(int n, int_t* a) {
		st = vector<vector<int_t>>(LG, vector<int_t>(n));
		sp2 = vector<int>(n + 1);
		
		for (int i = 0; i < n; i++) st[0][i] = a[i];
		
		int r = 0;
		for (int i = 1; i <= n; i++) {
			while (2 * (1 << r) <= i) ++r;
			sp2[i] = r;
		}
		
		for (int j = 1; j < LG; j++) {
			for (int i = 0; i < n; i++) {
				if (i + (1 << j) - 1 >= n) break;
				
				st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]); // combine
			}
		}
	}
	
	int_t query(int l, int r) {
		int x = sp2[r - l + 1];
		
		return max(st[x][l], st[x][r - (1 << x) + 1]);
	}
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

sparse<ll> st[16];
Factorizer ft;
int last[6969420][9];
int targ[16][200005];

vector<ll> factors(ll x) {
	vector<pair<int64_t, int>> f = ft.factorize(x);
	vector<ll> r;
	for (pair<int64_t, int> x: f) {
		for (ll i = 0; i < x.s % 2; i++) {
			r.push_back(x.f);
		}
	}
	return r;
}

void solve(int tc = 0) {
	cin >> n >> q;
	
	memset(last, -1, sizeof(last));
	memset(targ, -1, sizeof(targ));
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		vector<ll> f = factors(a[i]);
		assert(f.size() <= 7);
				
		ll s = f.size();
		for (ll m = 0; m < (1 << s); m++) {
			ll p = 1, c = __builtin_popcount(m);
			for (ll k = 0; k < s; k++) {
				if ((m >> k) & 1) p *= f[k];
			}
						
			for (ll oc = 0; oc < 8; oc++) {
				ll tot = (s - c) + oc;
								
				targ[tot][i] = max(targ[tot][i], last[p][oc]);
			}
			
			last[p][s - c] = i;
		}
	}
	
	for (ll i = 0; i < 15; i++) {
		st[i].init(n, targ[i]);
	}
	
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		--l; --r;
		
		ll ans;
		
		for (ll j = 14; j >= 0; j--) {
			ll p = st[j].query(l, r);
			if (p >= l) ans = j;
		}
		
		cout << ans << '\n';
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
	

		
	int tc = 1;
	// cin >> tc; 	
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}