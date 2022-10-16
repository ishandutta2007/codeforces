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

vector<vi> groups;
vector<int> g[510000];
int seen[510000];
vector<int> stk;
vector<int> done;
int lim;

bool dfs(int v) {
    stk.push_back(v);

    if (sz(stk) == lim) {
        cout << "PATH" << '\n';
        cout << lim << '\n';
        for (int x : stk) cout << x+1 << ' ';
        cout << '\n';
        return true;
    }

    seen[v] = 1;

    for (int x : g[v]) if (!seen[x]) {
        if (dfs(x)) return true;
    }

    stk.pop_back();
    done.push_back(v);
    if (sz(done) * 2 >= lim) {
        cout << "PAIRING" << '\n';
        cout << sz(done) << '\n';
        
        int cur = 0;
        for (int x : done) {
            while (seen[cur]) cur++;
            cout << x+1 << ' ' << cur+1 << endl;
            cur++;
        }

        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        int n,m;
        cin >> n >> m;

        lim = (n+1)/2;

        for (int i = 0; i < n; i++) {
            seen[i] = 0;
            g[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int u,v; cin >> u >> v; u--; v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        stk.clear();
        done.clear();
        dfs(0);
    }

    return 0;
}