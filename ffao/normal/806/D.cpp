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
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.f)+", "+ts(p.s)+")"; }
 
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {cerr << ts(h); if (sizeof...(t)) cerr << ", ";	DBG(t...); }
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vi mark(n);
    vector<long long> perish(n);
    vector<vector<ll>> g(n, vector<ll>(n));
    vector<long long> dist(n, 1000000000000000000LL);
    vector<long long> minto(n, 1000000000);


    ll mc = 1000000007;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cin >> g[i][j];
            g[j][i] = g[i][j];

            if (g[i][j] < mc) {
                mc = g[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) minto[i] = min(minto[i], g[i][j]);
        }
        if (minto[i] == mc) dist[i] = 0;
    }

    for (int it = 0; it < n; it++) {
        ll md = 1000000000000000001LL;
        int mi = -1;

        for (int j = 0; j < n; j++) if (!mark[j] && dist[j] < md) {
            md = dist[j];
            mi = j;
        }
        mark[mi] = 1;


        for (int i = 0; i < n; i++) if (!mark[i]) {
            dist[i] = min(dist[i], dist[mi] + (g[i][mi] - mc));
            dist[i] = min(dist[i], dist[mi] + (minto[i] - mc) * 2);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] + mc * 1ll * (n-1) << '\n';
    }

    return 0;
}