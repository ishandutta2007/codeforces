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

vi seqs(42);
vi maxs(42);

bool check(vi pots, vi inters, int tgt) {
    if (maxs[0] < tgt) return false;

    for (int i = 39; i >= 0; i--) {
        seqs[i] = min(tgt, maxs[i]);
        pots[i] -= seqs[i];
    }

    int fr = 0;
    for (int i = 39; i >= 0; i--) {
        fr += (seqs[i] - seqs[i+1]);
        
        int nd = pots[i+1] + inters[i];
        if (i == 0) nd += pots[0];

        if (nd > fr) return false;
        fr -= nd;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vi pots(42);
    vi inters(42);

    for (int i = 0; i < n; i++) {
        long long t;
        cin >> t;
        if ((t & (t-1)) == 0) {
            pots[__lg(t)]++;
        }
        else {
            inters[__lg(t)]++;
        }
    }

    maxs[0] = pots[0];
    for (int i = 1; i < 40; i++) {
        maxs[i] = min(maxs[i-1], pots[i]);
    }


    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (check(pots, inters, i)) {
            ok = true;
            cout << i << " ";
        }
    }

    if (!ok) cout << -1;
    cout << endl;

    return 0;
}