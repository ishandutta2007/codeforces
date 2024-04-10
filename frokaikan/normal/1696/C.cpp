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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int cas; cin >> cas; while (cas--) {
        int n, m; cin >> n >> m;
        vi as(n);
        for (auto &x: as) cin >> x;
        int k; cin >> k;
        vi bs(k);
        for (auto &x: bs) cin >> x;
        
        auto get = [&](const vi &as) {
            vector<pair<int, ll>> res;
            for (auto x: as) {
                int cnt = 1;
                while (x % m == 0) cnt *= m, x /= m;
                if (res.empty() || res.back().first != x) res.push_back(make_pair(x, 0ll));
                res.back().second += cnt;
            }
            return res;
        };
        auto ra = get(as), rb = get(bs);
        puts(ra == rb ? "Yes" : "No");
    }
    return 0;
}