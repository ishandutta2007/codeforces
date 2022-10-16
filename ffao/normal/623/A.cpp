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

int n, m;

vector< vi > g;
vector< int > ans;
vi seen;

bool dfs(int v, int c) {
    if (ans[v] != 0 && ans[v] != c) return false;
    if (ans[v] != 0) return true;

    ans[v] = c;
    for (int x : g[v]) if (ans[x]!=2) {
        if (!dfs(x, c)) return false;
    }
    return true;
}

int gg[510][510];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    g = vector<vi>(n);

    vi cnt(n);

    for (int i = 0; i < m; i++) {
        int u,v; cin >> u >> v; u--; v--;
        cnt[u]++; cnt[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
        gg[u][v]=gg[v][u]=1;
    }

    ans = vi(n);
    seen = vi(n);

    int s = 0;

    for (int i = 0; i < n; i++) if (cnt[i] == n-1) ans[i] = 2;
    for (int i = 0; i < n; i++) if (cnt[i] != n-1 && ans[i] == 0) {
        if (s > 1) {
            cout << "No" << endl;
            return 0;
        }
        else if (s == 0) {
            dfs(i,1);
        }
        else if (s == 1) dfs(i,3);

        s++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) if (ans[j] == ans[i] && !gg[i][j]) {
            // cout << i << " " << j << endl;
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    for (int i = 0; i < n; i++) {
        cout << (char)('a' + (ans[i]-1));
    }
    cout << endl;

    return 0;
}