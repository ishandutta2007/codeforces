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


double solve(double k, double Sa, double Sb, double q) {
    if (Sa == 1) return 0;
    double x = (1-Sa)/2;

    auto f = [&](double x) {
        return x * (k-x) + Sb*x + Sa*(k-x) - q;
    };

    auto ff = [&](double x) {
        return k - 2*x + Sb - Sa;
    };

    if (ff(x) == 0) x *= 0.95;

    // cout << x << " " << Sa << " " << f(x) << endl;
    for (int i = 0; i < 100; i++) {
        x -= f(x)/ff(x);
    }

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<double> a(n), b(n);
    vector<double> p(n), q(n);

    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> q[i];

    double Sa = 0, Sb = 0;
    for (int i = n-1; i>= 0; i--) {
        a[i] = solve(p[i]+q[i], Sa, Sb, q[i]);
        b[i] = p[i]+q[i]-a[i];
        Sa += a[i];
        Sb += b[i];
    }

    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(15) << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(15) << b[i] << " ";
    }
    cout << endl;

    return 0;
}