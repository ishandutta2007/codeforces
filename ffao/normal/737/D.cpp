#if 1
#ifdef LOCAL
#define _GLIBCXX_DEBUG 1
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif

#include <bits/stdc++.h>
using namespace std;

#if 0
    #include <bits/extc++.h>
    using namespace __gnu_pbds;

    template<class T>
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
#endif

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

mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

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

int myrand(int l, int r) { return uniform_int_distribution(l, r)(rng); }

#endif

#define ps auhauhaua

int seen[2200][190][100][2];
vi a;
vi ps;
int n;

int rec(int x, int y, int tak, int pl) {
    int tam = y - x + 1;
    if (tam < tak) {
        int le = ps[x];
        int ri = (ps[n] - ps[y+1]);
        // dbg(ps);
        // dbg(x,y,tak,pl,le,ri);
        return le - ri;
    }
    
    int taken_y = (n-1)-y;
    int diff = (x-taken_y) + 95;
    if (pl == 1) diff -= tak;

    int& ret = seen[x][diff][tak][pl];
    if (ret == 0x3f3f3f3f) {
        if (pl == 0) {
            ret = -ret;
            ret = max(ret, rec(x + tak, y, tak, pl^1));
            if (tam >= tak+1) ret = max(ret, rec(x + tak + 1, y, tak+1, pl^1));
        }
        else {
            ret = min(ret, rec(x, y - tak, tak, pl^1));
            if (tam >= tak+1) ret = min(ret, rec(x, y - tak - 1, tak+1, pl^1));
        }
    }

    // dbg(x,y,tak,pl,ret);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(seen,0x3f,sizeof(seen));
    cin >> n;
    a = vi(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ps = vi(n+1);
    for (int i = 1; i <= n; i++) ps[i] = ps[i-1] + a[i-1];
    
    cout << rec(0, n-1, 1, 0) << endl;

    return 0;
}