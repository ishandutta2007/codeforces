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

struct card {
    char type;
    int r;
    int b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector< card > cards(n);

    int reds = 0;
    int blues = 0;

    int needR = 0;
    int needB = 0;

    for (int i = 0; i < n; i++) {
        cin >> cards[i].type >> cards[i].r >> cards[i].b;
        if (cards[i].type == 'R') reds++;
        else blues++;

        needR += cards[i].r;
        needB += cards[i].b;
    }

    vi redsb((1<<n));
    vi bluesb((1<<n));

    for (int bm = 1; bm < (1<<n); bm++) {
        redsb[bm] = redsb[bm - (bm&-bm)] + (cards[__builtin_ctz(bm)].type == 'R');
        bluesb[bm] = bluesb[bm - (bm&-bm)] + (cards[__builtin_ctz(bm)].type == 'B');
    }

    vector<  vi > dp( (1<<n), vi(150, -1));
    dp[0][0] = 0;

    for (int bm = 0; bm < (1<<n)-1; bm++) {
        for (int rs = 0; rs <= 130; rs++) if (dp[bm][rs] != -1) {
            int cmpl = ((1<<n)-1) ^ bm;
            while (cmpl) {
                int nxt = __builtin_ctz(cmpl);
                int nrs = rs + min(redsb[bm], cards[nxt].r);
                int nbs = dp[bm][rs] + min(bluesb[bm], cards[nxt].b);

                dp[bm ^ (1<<nxt)][nrs] = max(dp[bm ^ (1<<nxt)][nrs], nbs);
                cmpl ^= cmpl&-cmpl;
            }
        }
    }

    ll ans = 1000000000000000000;
    for (int rs = 0; rs <= 130; rs++) if (dp[(1<<n)-1][rs] != -1) {
        int rr = needR - rs;
        int bb = needB - dp[(1<<n)-1][rs];
        ans = min(ans, (ll)max(rr,bb));
    }

    cout << ans + n << endl;
    return 0;
}