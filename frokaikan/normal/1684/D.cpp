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
        int n, k; scanf("%d%d", &n, &k);
        static int a[maxn + 5];
        ll sum = 0;
        rep(i, 1, n) scanf("%d", &a[i]), sum += a[i];
        rep(i, 1, k) sum -= i - 1;
        vi vec;
        rep(i, 1, n) vec.pb(a[i] - (n - i));
        nth_element(vec.begin(), vec.begin() + (k - 1), vec.end(), greater<int>());
        rep(i, 0, k - 1) sum -= vec[i];
        printf("%lld\n", sum);
    }
    return 0;
}