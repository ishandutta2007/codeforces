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
    auto solve = [&]()
    {
        int n, m; scanf("%d%d", &n, &m);
        static vi a[maxn + 5];
        rep(i, 1, n) 
        {
            a[i].resize(m + 5);
            rep(j, 1, m) scanf("%d", &a[i][j]);
        }
        auto le = [&](int j, int k) 
        {
            int ok = 1;
            rep(i, 1, n) if(a[i][j] > a[i][k]) ok = 0;
            if(ok) return 1;
            
            ok = 1;
            rep(i, 1, n) if(a[i][k] > a[i][j]) ok = 0;
            if(ok) return 0;
            return -1;
        };

        int bad = -1;
        rep(j, 1, m - 1) 
        {
            int res = le(j, j + 1);
            if(res == 0) { bad = j; break; }
            else if(res == -1) return 0;
        }

        if(bad == -1) return puts("1 1"), 1;
        else
        {
            int X = bad, Y = bad + 1;
            rep(j, bad + 2, m)
            {
                int res = le(j, Y);
                if(res == 1) Y = j;
                else if(res == -1) return 0;
            }
            per(j, 1, bad - 1)
            {
                int res = le(X, j);
                if(res == 1) X = j;
                else if(res == -1) return 0;
            }
            rep(i, 1, n) swap(a[i][X], a[i][Y]);
            int ok = 1;
            rep(i, 1, n) rep(j, 1, m - 1) if(a[i][j] > a[i][j + 1]) ok = 0;
            if(ok) return printf("%d %d\n", X, Y), 1;
            else return 0;
        }
    };

    int cas; scanf("%d", &cas); while(cas--) if(solve() == 0) puts("-1");
    return 0;
}