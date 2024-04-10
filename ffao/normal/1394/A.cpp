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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,d,m;
    cin >> n >> d >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> lo, hi;
    for (int i = 0; i < n; i++) {
        if (a[i] <= m) lo.push_back(a[i]);
        else hi.push_back(a[i]);
    }  

    sort(all(lo));
    sort(all(hi));

    long long tot = 0;
    for (int i = 0; i < sz(lo); i++) tot += lo[i];

    int curlo = 0;
    int curhi = sz(hi)-1;
    ll ans = 0;
    for (int uhi = 0; uhi <= sz(hi); uhi++) {
        if (uhi > 0) tot += hi[curhi--];
        if (sz(hi) > uhi * 1ll * (d+1)) continue;

        int filtered = sz(hi) - uhi;
        ll ndfilt = max(0LL, (uhi-1) * 1ll * d - filtered);

        if (ndfilt > sz(lo)) break;
        
        // dbg(uhi, sz(hi), filtered, (uhi-1) * 1ll * d, ndfilt);
        while (curlo < ndfilt) {
            // dbg("remove", lo[curlo]);
            tot -= lo[curlo++];
        }

        ans = max(ans, tot);

        // dbg("add", hi[curhi]);
    }

    cout << ans << endl;
    return 0;
}