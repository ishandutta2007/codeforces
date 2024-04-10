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

vector< vi > pars;
vector<int> cans;
vector<int> rans;

void ep(int v, vector<vector<pii>>& g, int n) {
    while (!g[v].empty()) {
        auto [dest, idx] = g[v].back();
        g[v].pop_back();

        int rev;
        for (int i = 0; i < g[dest%n].size(); i++) {
            if (g[dest%n][i].second == idx) {
                rev = g[dest%n][i].first;
                g[dest%n].erase(g[dest%n].begin() + i);
            }
        }

        ep(dest%n, g, n);
        cans.push_back(dest);
        rans.push_back(rev);
    }
}

int main() {
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "First" << endl;
        vi ans(2*n);

        vi ord(2*n - 2);
        for (int i = 1; i <= 2*n-2; i++) {
            ord[i-1] = i;
        }
        ord.insert(ord.begin() + n, 2*n);
        ord.insert(ord.begin() + (n-1), 2*n-1);
        
        for (int i = 0; i < n; i++) {
            ans[ord[2*i]-1] = ans[ord[2*i+1]-1] = i+1;
        }

        for (int x : ans) cout << x << " ";
        cout << endl;
        return 0;
    }

    cout << "Second" << endl;

    vi par(2*n + 1);
    for (int i = 1; i <= 2*n; i++) cin >> par[i];
    
    pars = vector<vi>(n);
    for (int i = 1; i <= 2*n; i++) {
        pars[par[i]-1].push_back(i);
    }

    vector< vector<pii> > g(n);
    for (int i = 0; i < n; i++) {
        g[pars[i][0]%n].push_back({pars[i][1], i});
        g[pars[i][1]%n].push_back({pars[i][0], i});
    }

    for (int i = 0; i < n; i++) {
        if (!g[i].empty()) ep(i,g,n);
    }

    int tot = 0;
    for (int x : cans) tot = (tot+x)%2;

    if (tot != 0) for (int x : rans) cout << x << " ";
    else for (int x : cans) cout << x << " ";
    cout << endl;
}