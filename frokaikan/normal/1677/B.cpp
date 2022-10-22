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
const int mod = 1e9+7;

void solve()
{
    int n,m; scanf("%d%d",&n,&m);
    static char s[maxn+5];
    scanf("%s",s);
    int cols = 0;
    vi mark_col(m), ans(n*m), ps(n*m+1), cnt_rows(n*m);
    rep(i,0,n*m-1)
    {
        int y = i % m;
        if(s[i]=='1') 
        {
            if(mark_col[y] == 0) cols++;
            mark_col[y] = 1;
        }
        ans[i] = cols;
    }
    rep(i,1,n*m) ps[i] = ps[i-1] + (s[i-1] == '1');
    rep(i,0,m-1) cnt_rows[i] = ps[i+1] > 0;
    rep(i,m,n*m-1) cnt_rows[i] = cnt_rows[i-m] + (ps[i+1] - ps[i+1-m] > 0);
    rep(i,0,n*m-1) ans[i] += cnt_rows[i];
    rep(i,0,n*m-1) printf("%d%c",ans[i]," \n"[i+1==n*m]);
}

int main()
{
    int cas = 1; scanf("%d",&cas);
    while(cas--) solve();
}