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

const int maxn = 1'000'000;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

void solve()
{
    int n, k; scanf("%d%d",&n,&k);
    vi a(n);
    rep(i,0,n-1) scanf("%d",&a[i]);
    rep(i,1,k) if(a[n-i] > 0) { puts("0"); return; }
    int base = 1, ans = 1;
    rep(i,1,k) base = 1ll * base * i % mod;
    rep(i,0,n-k-1) 
    {
        if(a[i] == 0) base = 1ll * base * (k + 1) % mod;
        else if(a[i] == -1) ans = 1ll * ans * (k + 1 + i) % mod;
    }
    ans = 1ll * ans * base %mod;
    printf("%d\n", ans);
}

int main()
{
    int cas; scanf("%d",&cas);
    while(cas--) solve();
}