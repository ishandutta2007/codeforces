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
    
    int n; cin >> n;
    string s; cin >> s;

    vector<int> vall(n+1), valr(n+1);
    vector<int> mnsuf(n+1), mnpref(n+1);

    for (int i = 0; i < n; i++) {
        vall[i+1] = vall[i] + (s[i] == '(' ? 1 : -1); 
    }

    mnsuf[n] = vall[n];
    for (int i = n-1; i >= 0; i--) {
        mnsuf[i] = min(mnsuf[i+1], vall[i]);
    }

    for (int i = n-1; i >= 0; i--) {
        valr[i] = valr[i+1] + (s[i] == ')' ? 1 : -1);
    }

    mnpref[0] = valr[0];
    for (int i = 1; i <= n; i++) {
        mnpref[i] = min(mnpref[i-1], valr[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (mnsuf[i+1] >= -2) {
                if (vall[n] == -2) ans++;
            }
        }
        if (vall[i+1] < 0) break;
    }

    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '(') {
            if (mnpref[i] >= -2) {
                // dbg(i);
                if (valr[0] == -2) ans++;
            }
        }
        if (valr[i] < 0) break;
    }

    cout << ans << endl;

    return 0;
}