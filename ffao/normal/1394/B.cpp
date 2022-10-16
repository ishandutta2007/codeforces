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

vector<vector<pii>> g;

int come[210000][10][10];
int con[10][10][10][10];

int generated[10];

int gen(int cur, int k) {
    if (cur <= k) {
        int ans = 0;
        for (int i = 0; i < cur; i++) {
            generated[cur] = i;

            bool ok = true;
            for (int j = 1; j <= cur; j++) {
                if (con[j][generated[j]][cur][generated[cur]]) {
                    // dbg("break", j, generated[j], cur, generated[cur]);
                    ok = false;
                    break;
                }
            }

            if (ok) ans += gen(cur+1, k);
        }
        return ans;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    g = vector<vector<pii>>(n);

    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w; u--; v--;
        g[u].push_back({w,v});
    }

    vector< vector<pii> > incident(n);

    for (int v = 0; v < n; v++) {
        int th = sz(g[v]);
        sort(all(g[v]));

        for (int i = 0; i < th; i++) {
            come[g[v][i].second][th][i]++;
            if (come[g[v][i].second][th][i] == 2) {
                con[th][i][th][i] = 1;
            }
            // dbg(v,th,i);
            incident[g[v][i].second].push_back({th,i});
        }
    }

    for (int v = 0; v < n; v++) {
        sort(all(incident[v]));
        incident[v].erase(unique(all(incident[v])), incident[v].end());

        for (int i = 0; i < sz(incident[v]); i++) {
            for (int j = i+1; j < sz(incident[v]); j++) {
                // dbg(incident[v][i].first, incident[v][i].second, incident[v][j].first, incident[v][j].second);
                con[incident[v][i].first][incident[v][i].second][incident[v][j].first][incident[v][j].second]++;
                con[incident[v][j].first][incident[v][j].second][incident[v][i].first][incident[v][i].second]++;
            }
        }
    }

    cout << gen(1, k) << endl;

    return 0;
}