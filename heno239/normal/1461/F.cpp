#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
    ll res = 1;
    while (n) {
        if (n & 1)res = res * x % m;
        x = x * x % m; n >>= 1;
    }
    return res;
}
struct modint {
    ll n;
    modint() :n(0) { ; }
    modint(ll m) :n(m) {
        if (n >= mod)n %= mod;
        else if (n < 0)n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
    if (n == 0)return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)res = res * a;
    return res;
}

ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 20;
modint fact[max_n], factinv[max_n];
void init_f() {
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) {
        fact[i + 1] = fact[i] * modint(i + 1);
    }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * modint(i + 1);
    }
}
modint comb(int a, int b) {
    if (a < 0 || b < 0 || a < b)return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}

ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    while (b) {
        ll r = a % b; a = b; b = r;
    }
    return a;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    string s; cin >> s;
    sort(all(s));
    if (s.size() == 1) {
        rep(i, n) {
            if (i > 0)cout << s;
            cout << a[i];
        }
        cout << "\n";
    }
    else if (s == "*-") {
        vector<char> c(n - 1,'*');
        for (int i = 1; i < n; i++)if (a[i] == 0) {
            c[i - 1] = '-';
            break;
        }
        rep(i, n) {
            cout << a[i];
            if (i < n - 1)cout << c[i];
        }
        cout << "\n";
    }
    else if (s == "+-") {
        vector<char> c(n - 1, '+');
        rep(i, n) {
            cout << a[i];
            if (i < n - 1)cout << c[i];
        }
        cout << "\n";
    }
    else {
        //+*
        vector<char> c(n - 1,'*');
        vector<P> ps;
        rep(i, n) {
            if (a[i] == 0) {
                if (i - 1 >= 0)c[i-1] = '+';
                if (i < n - 1)c[i] = '+';
                continue;
            }
            int le = i;
            while (i + 1 < n && a[i + 1] > 0)i++;
            ps.push_back({ le,i + 1 });
        }
        for (P p : ps) {
            int l = p.first, r = p.second;
            while (l<r&&a[l] == 1) {
                if (l - 1 >= 0)c[l - 1] = '+';
                if (l < n - 1)c[l] = '+';
                l++;
            }
            if (l == r)continue;
            while (a[r - 1] == 1) {
                r--;
                if (r - 1 >= 0)c[r-1] = '+';
                if (r < n - 1)c[r] = '+';
            }
            ll pro = 1;
            for (int i = l; i < r; i++) {
                pro = pro * a[i];
                if (pro > mod)pro = mod;
            }
            if (pro > 1000000) {
                for (int i = l; i < r-1; i++) {
                    //c[i] = '*';
                }
                continue;
            }
            vector<int> ps;
            vector<int> cs; cs.push_back(0);
            vector<P> segs;
            while (l < r) {
                int memo = l;
                if (a[l] >= 2) {
                    while (l+1<r&&a[l + 1] >= 2)l++;
                    int p = 1;
                    for (int j = memo; j <= l; j++)p *= a[j];
                    ps.push_back(p);
                }
                else {
                    while (l+1<r&&a[l + 1] == 1)l++;
                    cs.push_back(l - memo + 1);
                    segs.push_back({ memo,l });
                }
                l++;
            }
            cs.push_back(0);
            int len = ps.size();
            vector<int> dp(len + 1,-mod);
            vector<int> pre(len + 1);
            dp[0] = 0;
            rep(i, len) {
                int cost = 1;
                for (int j = i + 1; j <= len; j++) {
                    cost *= ps[j - 1];
                    if (dp[j] < dp[i] + cost + cs[j]) {
                        dp[j] = dp[i] + cost + cs[j];
                        pre[j] = i;
                    }
                }
            }
            int cur = len;
            while (cur > 0) {
                cur = pre[cur];
                if (cur > 0) {
                    for (int j = segs[cur - 1].first-1; j <= segs[cur - 1].second; j++) {
                        c[j] = '+';
                    }
                }
            }
        }
        rep(i, n) {
            if (a[i] == 0) {
                //if (i - 1 >= 0)assert(c[i - 1] == '+');
                //if (i < n - 1)assert(c[i] == '+');
            }
            if (a[i] == 1) {
                if (i - 1 >= 0 && i < n - 1) {
                    assert(c[i - 1] == c[i]);
                }
            }
            if (i + 1 < n && a[i] >= 2 && a[i + 1] >= 2) {
                //assert(c[i] == '*');
            }
        }

        rep(i, n) {
            cout << a[i];
            if (i < n - 1)cout << c[i];
        }
        cout << "\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}