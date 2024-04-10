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

int dp[251][251][251];
vector< array<int, 26> > nxt;
string s[3];
int n, q;

void recalc(int i, int j, int k) {
    dp[i][j][k] = n+1;

    if (i > 0) {
        int nn = nxt[dp[i-1][j][k]][s[0][i-1]-'a'];
        if (nn != n) {
            dp[i][j][k] = min(dp[i][j][k], nn+1);
        }
    }
    if (j > 0) {
        int nn = nxt[dp[i][j-1][k]][s[1][j-1]-'a'];
        if (nn != n) {
            dp[i][j][k] = min(dp[i][j][k], nn+1);
        }
    }
    if (k > 0) {
        int nn = nxt[dp[i][j][k-1]][s[2][k-1]-'a'];
        if (nn != n) {
            dp[i][j][k] = min(dp[i][j][k], nn+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;

    string w;
    cin >> w;

    nxt = vector< array<int, 26> >(n+2);

    for (int j = 0; j < 26; j++) nxt[n][j] = nxt[n+1][j] = n;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][w[i]-'a'] = i;
    }

    for (int i = 0; i <= 250; i++) {
        for (int j = 0; j <= 250; j++) {
            for (int k = 0; k <= 250; k++) dp[i][j][k]=n+1;
        }
    }

    dp[0][0][0] = 0;    

    for (; q; q-- ){
        char op; int i;
        cin >> op >> i; i--;
        if (op == '-') {
            s[i].pop_back();
        }
        else {
            char l; cin >> l;
            s[i].push_back(l);

            if (i == 0) {
                for (int j = 0; j <= sz(s[1]); j++) {
                    for (int k = 0; k <= sz(s[2]); k++) {
                        recalc(sz(s[0]), j, k);
                    }
                }
            }
            if (i == 1) {
                for (int j = 0; j <= sz(s[0]); j++) {
                    for (int k = 0; k <= sz(s[2]); k++) {
                        recalc(j, sz(s[1]), k);
                    }
                }
            }
            if (i == 2) {
                for (int j = 0; j <= sz(s[0]); j++) {
                    for (int k = 0; k <= sz(s[1]); k++) {
                        recalc(j, k, sz(s[2]));
                    }
                }
            }
        }


        cout << (dp[sz(s[0])][sz(s[1])][sz(s[2])] == n+1 ? "NO" : "YES") << endl;
    }

    return 0;
}