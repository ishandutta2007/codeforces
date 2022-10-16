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

vi is_gov;
vi par, tam;

ll C(ll a) {
    return a * (a-1) /2;
}

int find(int x) {
    if (par[x]==x) return x;
    return par[x]=find(par[x]);
}

void link(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;

    tam[y] += tam[x];
    is_gov[y] |= is_gov[x];
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    is_gov = vi(n);
    par = vi(n);
    tam = vi(n);

    for (int i = 0; i < n; i++) {
        par[i] = i;
        tam[i] = 1;
    }

    for (int i = 0; i < k; i++) {
        int x; cin >> x; x--;
        is_gov[x] = 1;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y; x--; y--;
        link(x,y);
    }

    int bg = -1;
    int ot = 0;
    for (int i = 0; i < n; i++) if (par[i]==i) {
        if (is_gov[i]) {
            if (bg == -1 || tam[bg] < tam[i]) bg = i;
        }
        else ot += tam[i];
    }

    ll ed = 0;
    for (int i = 0; i < n; i++) if (par[i]==i) {
        if (i == bg) {
            ed += C(tam[i] + ot);
        }
        else if (is_gov[i]) {
            ed += C(tam[i]);
        }
    }

    cout << ed - m << endl;
    return 0;
}