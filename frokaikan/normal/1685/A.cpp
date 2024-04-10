 #include "bits/stdc++.h"
#define rep(i, a, n) for(auto i = a; i <= n; i++)
#define per(i, a, n) for(auto i = n; i >= a; i--)
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
using pii = pair<int,int>;
using vi = vector<int>;
using db = double;
using ldb = long double;

const int maxn = 100'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int main()
{
    int cas; scanf("%d", &cas); while(cas--)
    {
        int n; scanf("%d", &n);
        static int a[maxn + 5];
        rep(i, 1, n) scanf("%d", &a[i]);
        if(n & 1) { puts("NO"); continue; }
        sort(a + 1, a + n + 1);
        int x = a[n / 2 + 1];
        int cnt_1 = 0, cnt_2 = 0;
        rep(i, 1, n / 2) if(a[i] == x) cnt_1++;
        rep(i, n / 2 + 1, n) if(a[i] == x) cnt_2++;
        if(cnt_2 != n / 2) cnt_2++;
        int slots = n / 2 - cnt_2;
        if(slots < cnt_1) puts("NO");
        else
        {
            puts("YES");
            static int ans[maxn + 5];
            rep(i, 1, n / 2)
            {
                ans[i * 2 - 1] = a[i];
                ans[i * 2] = a[i + n / 2];
            }
            rep(i, 1, n) printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}