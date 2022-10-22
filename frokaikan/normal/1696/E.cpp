#include "bits/stdc++.h"
#define rep(i, a, n) for (auto i = a; i <= (n); i++)
#define revrep(i, a, n) for (auto i = n; i >= (a); i--)
#define all(a) a.begin(), a.end()
#define sz(a) (int)(a).size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) { a = b; return 1; } return 0; }
using namespace std;

template<class A, class B> string to_string(pair<A, B> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A> string to_string(A v) {
    bool first = 1;
    string res = "{";
    for (const auto &x: v) {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
    #define debug(...) if(0) puts("No effect.")
#endif

using ll = long long;
// using LL = __int128;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using db = double;

const int maxn = 500'000;
const int mod = 1e9 + 7;

int fac[maxn + 5], ifac[maxn + 5], inv[maxn + 5];
int binom(int n, int m)
{
    if(m < 0 || n < m) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

inline void chadd(int &x, int y) { x += y; if (x >= mod) x -= mod; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    inv[1] = fac[0] = ifac[0] = 1;
    rep(i, 2, maxn) inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    rep(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    rep(i, 1, maxn) ifac[i] = 1ll * ifac[i - 1] * inv[i] % mod;

    
    int n; cin >> n;
    vi as(n + 1);
    for (auto &x: as) cin >> x;
    if (as[0] == 0) puts("0");
    else {
        while (as.back() == 0) as.pop_back();
        n = sz(as);
        as.push_back(0);

        int ans = 0;
        rep(i, 1, n) {
            if (as[i] == as[i - 1]) {
                if (as[i] > 0) chadd(ans, binom(i + as[i] - 1, i));
            }
            else {
                rep(j, as[i], as[i - 1] - 1) {
                    if (j == as[i]) {
                        if (j == 0) chadd(ans, 1);
                        else chadd(ans, binom(i + j, i));
                    } else {
                        chadd(ans, binom(i - 1 + j, i - 1));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}