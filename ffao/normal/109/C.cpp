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

vector<int> lucky;
const int LIM = 1000000000;

void genluck(int x) {
    ll a1 = x*1ll*10 + 4;
    ll a2 = x*1ll*10 + 7;

    if (a1 <= LIM) {
        lucky.push_back((int)a1);
        genluck((int)a1);
    }
    if (a2 <= LIM) {
        lucky.push_back((int)a2);
        genluck((int)a2);
    }
}

bool islucky(int x) {
    auto it = lower_bound(all(lucky), x);
    if (it == lucky.end()) return false;
    return *it == x;
}

vi par;
vi tam;

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void link(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;

    tam[y] += tam[x];
    par[x] = y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    genluck(0);
    sort(all(lucky));

    int n;
    cin >> n;

    vector< pii > edges;
    
    par = vi(n);
    iota(all(par),0);
    tam = vi(n, 1);

    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (!islucky(w)) {
            link(u-1,v-1);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) if (par[i]==i) {
        ans += tam[i] * 1ll * (n-tam[i]) * 1ll * (n-tam[i]-1);
    }

    cout << ans << endl;
    return 0;
}