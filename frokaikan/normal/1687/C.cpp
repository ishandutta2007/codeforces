#include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= (n); i++)
#define per(i, a, n) for(auto i = n; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
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
template<class A> string to_string(A v)
{
    bool first = 1;
    string res = "{";
    for(const auto &x: v) 
    {
        if (!first) res += ", ";
        first = 0;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }

void debug_out() { cerr << endl; }
template<class Head, class... Tail> void debug_out(Head H, Tail... T) 
{
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
using ldb = long double;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int cas; cin >> cas; while(cas--)
    {
        int n, m; cin >> n >> m;
        vi a(n), b(n);
        ll sum = 0;
        for(auto &x: a) cin >> x, sum += x;
        for(auto &x: b) cin >> x, sum -= x;
        vector<pii> seg(m);
        for(auto &[x, y]: seg) cin >> x >> y, x--, y--;

        if(sum != 0) { puts("NO"); continue; }
        vi vec{-1};
        rep(i, 0, n - 1)
        {
            sum += a[i];
            sum -= b[i];
            if(sum == 0) vec.pb(i);
        }
        int N = sz(vec);
        static vvi pool; pool.assign(N, {});
        vi rst(m);
        rep(i, 0, m - 1)
        {
            auto &[l, r] = seg[i];
            
            int pos = upper_bound(all(vec), r) - vec.begin() - 1;
            if(r != vec[pos]) pool[pos + 1].pb(i), rst[i]++;
            r = pos;
            
            pos = upper_bound(all(vec), l - 1) - vec.begin() - 1;
            if(l - 1 != vec[pos]) 
            {
                pool[pos + 1].pb(i), rst[i]++;
                l = pos + 2;
            }
            else l = pos + 1;
        }
        // debug(vec);
        // debug(seg);
        set<int> S;
        rep(i, 1, N - 1) if(vec[i] != vec[i - 1] + 1) S.insert(i);
        queue<int> q;
        rep(i, 0, m - 1) if(rst[i] == 0) q.push(i);
        while(sz(q))
        {
            int now = q.front(); q.pop();
            auto [l, r] = seg[now];
            while(1)
            {
                auto it = S.lower_bound(l);
                if(it == S.end() || *it > r) break;
                int x = *it;
                S.erase(x);
                for(auto v: pool[x]) if(--rst[v] == 0) q.push(v);
            }
        }
        puts(S.empty() ? "YES" : "NO");
    }
    return 0;
}