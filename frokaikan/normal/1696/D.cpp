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

template<class T, class F = function<T(const T&, const T&)>> struct SparseTable
{   // 0-based indexing.
    int n;
    vector<vector<T>> st;
    F func;
    SparseTable(const vector<T> &a, const F &f): n(sz(a)), func(f)
    {
        st.assign(__lg(n) + 1, vector<T>(n));
        st[0] = a;
        rep(i, 1, __lg(n)) rep(j, 0, n - (1 << i)) st[i][j] = func(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
    T ask(int l, int r)
    {
        assert(0 <= l && l <= r && r < n);
        int k = __lg(r - l + 1);
        return func(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int cas; cin >> cas; while (cas--) {
        int n; cin >> n;
        vi as(n);
        for (auto &x: as) cin >> x;
        
        if (n == 1) { puts("0"); continue; }

        vi ps(n);
        iota(all(ps), 0);
        SparseTable<int> spmn(ps, [&](int i, int j){ return as[i] < as[j] ? i : j; });
        SparseTable<int> spmx(ps, [&](int i, int j){ return as[i] > as[j] ? i : j; });

        function<int(int, int)> solve = [&](int l, int r) {
            int mnpos = spmn.ask(l, r);
            // int mx = spmx.ask(l, r);
            if (mnpos != l && mnpos != r) return solve(l, mnpos) + solve(mnpos, r);
            else {
                int mxpos = spmx.ask(l, r);
                if (mxpos != l && mxpos != r) return solve(l, mxpos) + solve(mxpos, r);
                else return 1;
            }
        };
        printf("%d\n", solve(0, n - 1));
    }
    return 0;
}