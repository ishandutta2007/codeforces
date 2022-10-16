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

ll count(ll Alow, ll Ahigh, ll Blow, ll Bhigh) {
    ll high = min(Ahigh, Bhigh);
    ll low = max(Alow, Blow);
    if (low > high) return 0;

    // dbg(Alow,Ahigh,Blow,Bhigh);
    return (high-low+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    genluck(0);
    sort(all(lucky));

    int pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;

    ll tot = (pr-pl+1) * 1ll * (vr-vl+1);
    ll my = 0;

    for (int i = 0; i <= sz(lucky) - k; i++) {
        int j = i+k;
        ll p11 = count(pl,pr, (i != 0 ? lucky[i-1]+1 : -1000000001), lucky[i]);
        ll p21 = count(vl,vr, (i != 0 ? lucky[i-1]+1 : -1000000001), lucky[i]);

        ll p12 = count(pl,pr, lucky[j-1], (j != sz(lucky) ? lucky[j]-1 : 1000000001));
        ll p22 = count(vl,vr, lucky[j-1], (j != sz(lucky) ? lucky[j]-1 : 1000000001));

        dbg(lucky[i], lucky[i+k-1], p11*p22,p21*p12);
        my += p11 * p22;
        my += p21 * p12;
    }

    if (k == 1) {
        for (int x : lucky) {
            if (pl <= x && x <= pr && vl <= x && x <= vr) my--;
        }
    }

    cout << fixed << setprecision(15) << (my / (double)tot) << endl;
    return 0;
}