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

const int mod = 1000000007;

pii pd[61][2][2][2];

pii go(int rem, bool eqx, bool eqy, bool eqk, int x, int y, int k) {
    if (x < 0 || y < 0 || k < 0) return {0, 0};

    if (rem == -1) {
        return {0, 1};
    }

    pii &ret = pd[rem][eqx][eqy][eqk];
    if (ret.first == -1) {
        ret = {0, 0};

        for (int putx = 0; putx <= 1; putx++) {
            for (int puty = 0; puty <= 1; puty++) {
                int putk = putx ^ puty;

                if (eqx && putx && !(x&(1<<rem))) continue;
                if (eqy && puty && !(y&(1<<rem))) continue;
                if (eqk && putk && !(k&(1<<rem))) continue;

                bool neqx = eqx && putx==!!(x&(1<<rem));
                bool neqy = eqy && puty==!!(y&(1<<rem));
                bool neqk = eqk && putk==!!(k&(1<<rem));

                pii ot = go(rem-1, neqx, neqy, neqk, x, y, k);

                ret.second = (ret.second + ot.second);
                if (ret.second >= mod) ret.second -= mod;

                // dbg(putk, ret.first, ot.second);
                ret.first = (ret.first + putk * 1ll * (1<<rem) * 1ll * ot.second + ot.first) % mod;
            }
        }
    }

    return ret;
}

void solve() {
    int x1,y1,x2,y2,k;
    cin >> x1 >> y1 >> x2 >> y2 >> k;
    x1--; y1--; x2--; y2--; k--;
    
    memset(pd,-1,sizeof(pd));
    pii aa1 = go(30, true, true, true, x2, y2, k);
    
    memset(pd,-1,sizeof(pd));
    pii aa2 = go(30, true, true, true, x1-1, y2, k);

    memset(pd,-1,sizeof(pd));
    pii aa3 = go(30, true, true, true, x2, y1-1, k);
    
    memset(pd,-1,sizeof(pd));
    pii aa4 = go(30, true, true, true, x1-1, y1-1, k);

    int a1 = (aa1.first + aa1.second) % mod;
    int a2 = (aa2.first + aa2.second) % mod;
    int a3 = (aa3.first + aa3.second) % mod;
    int a4 = (aa4.first + aa4.second) % mod;

    dbg(aa1,aa2,aa3,aa4);
    int ans = a1 - a2;
    if (ans < 0) ans += mod;
    ans -= a3;
    if (ans < 0) ans += mod;
    ans += a4;
    if (ans >= mod) ans -= mod;

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // // memset(pd,-1,sizeof(pd));
    // // pii r = go(30, true, true, true, 1, 1, 5);
    // // dbg(r);
    // return 0;

    int q;
    for (cin >> q; q; q--) solve();

    return 0;
}