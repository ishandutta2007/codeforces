#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

typedef string str;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) { str res = ""; F0R(i,SZ) res += char('0'+b[i]); return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { bool fst = 1; str res = "{"; for (const auto& x: v) {if (!fst) res += ", ";	fst = 0; res += ts(x);}	res += "}"; return res;}
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

#define double long double

struct level {
    int f, s;
    double p;
};

double dp[51][51000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, r;
    cin >> n >> r;

    vector<level> lvl(n);
    int extra = r;

    for (int i = 0; i < n; i++) {
        cin >> lvl[i].f >> lvl[i].s >> lvl[i].p;
        lvl[i].p /= 100.0;
        extra -= lvl[i].f;
    }

    double st = 0, ed = 1e18;
    for (int i = 0; i < 100; i++) {
        double md = (st+ed)/2;

        for (int i = n-1; i >= 0; i--) {
            for (int ot = 0; ot <= extra; ot++) {
                double fast = dp[i+1][ot] + lvl[i].f;
                int nt = ot + (lvl[i].s - lvl[i].f);
                double slow = (nt <= extra ? dp[i+1][nt] : md) + lvl[i].s;

                dp[i][ot] = (fast * lvl[i].p + slow * (1-lvl[i].p));
                dp[i][ot] = min(md, dp[i][ot]);
            }
        }

        if (dp[0][0] == md) st = md;
        else ed = md;
    }

    cout << fixed << setprecision(15) << (st+ed)/2 << endl;
    return 0;
}