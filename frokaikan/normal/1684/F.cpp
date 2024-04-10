#include "bits/stdc++.h"
#define rep(i,a,n) for(auto i=a;i<=n;i++)
#define per(i,a,n) for(auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define all(A) A.begin(),A.end()
#define sz(A) (int)A.size()
template<class T> inline bool chmax(T &a, T b) { if(a < b) {a = b; return 1;} return 0; }
template<class T> inline bool chmin(T &a, T b) { if(b < a) {a = b; return 1;} return 0; }
using namespace std;

string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(char c) { return "'" + string(1,c) + "'"; }
string to_string(bool x) { return x ? "true" : "false"; }
template<class A, class B> string to_string(pair<A, B> p) { return "(" + to_string(p.FI) + ", " + to_string(p.SE) + ")"; }
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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 200'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;


int main()
{
    int cas; scanf("%d", &cas); while(cas--)
    {
        int n, m; scanf("%d%d", &n, &m);
        static int a[maxn + 5];
        rep(i, 1, n) scanf("%d", &a[i]);
        vi mn(n + 1);
        rep(i, 1, n) mn[i] = i;
        while(m--)
        {
            int l, r; scanf("%d%d", &l, &r);
            chmin(mn[r], l);
        }
        per(i, 1, n - 1) chmin(mn[i], mn[i + 1]);

        vi nxt(n + 5, inf), pre(n + 5, 0);
        map<int, int> last;
        rep(i, 1, n)
        {
            int x = a[i];
            if(last.count(x) == 0) last[x] = 0;
            pre[i] = last[x];
            last[x] = i;
        }

        last.clear();
        per(i, 1, n)
        {
            int x = a[i];
            if(last.count(x) == 0) last[x] = inf;
            nxt[i] = last[x];
            last[x] = i;
        }

        static vector<pii> pool[maxn + 5];
        rep(i, 1, n) pool[i].clear();
        rep(r, 1, n) 
        {
            int l = mn[r];
            pool[l].pb({r, a[r]});
        }

        vector<pii> res;
        last.clear();
        per(i, 1, n)
        {
            int x = a[i];
            if(last.count(x) == 0) last[x] = inf;
            last[x] = i;
            for(auto [r, ar]: pool[i]) if(last[ar] != r) res.pb({last[ar], r});
        }
        // debug(res);

        auto check = [&](int L)
        {
            int M = sz(res);
            if(M == 0) return 1;
            static vi ps; ps.assign(n + 5, 0);
            auto add = [&](int l, int r, int x) { ps[l] += x; ps[r + 1] -= x; };
            auto get = [&](int l, int r) 
            {
                int x = max(r, L);
                int y = min(l + L - 1, n);
                if(x <= y) return pii{x, y};
                return pii{-1, -1};
            };
            for(auto [l, r]: res)
            {
                auto [l1, r1] = get(nxt[l], r);
                auto [l2, r2] = get(l, pre[r]);
                // debug(L, l1, r1, l2, r2);
                if(l1 == -1 && l2 == -1) return 0;
                if(l1 != -1) add(l1, r1, 1);
                if(l2 != -1) add(l2, r2, 1);
                if(l1 != -1 && l2 != -1)
                {
                    int ll = max(l1, l2);
                    int rr = min(r1, r2);
                    if(ll <= rr) add(ll, rr, -1);
                }
            }
            rep(i, 1, n) ps[i] += ps[i - 1];
            rep(i, 1, n) if(ps[i] == M) return 1;
            return 0;
        };
        
        int l = 0, r = n;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        // debug(l, r);
        assert(r < n);
        printf("%d\n", r);
    }
    return 0;
}