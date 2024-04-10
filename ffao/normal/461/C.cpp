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
    
    int n,q;
    cin >> n >> q;

    vector<ll> tree(n+10);

    auto get = [&](int x) {
        ll s = 0;
        for (int k = x+1; k > 0; k -= k&-k) s += tree[k];
        return s;
    };

    auto get_single = [&](int x) {
        return get(x) - get(x-1);
    };

    auto upd = [&](int x, ll d) {
        // dbg(x, d);
        for (int k = x+1; k <= n+5; k += k&-k) tree[k] += d;
    };

    for (int i = 0; i < n; i++) upd(i, 1);

    bool rev = false;
    int curw = n;
    int zero = 0;

    for (; q; q--) {
        int t; cin >> t;

        if (t == 1) {
            int w; cin >> w;

            if (w*2 > curw) {
                if (rev) zero = zero - curw + 1;
                else zero = zero + curw - 1;

                rev = !rev;
                w = curw - w;
            }

            for (int i = 0; i < w; i++) {
                ll v = get_single(zero);
                upd(zero, -v);
                
                if (!rev) {
                    // dbg(w,i,zero + 2*w - 1 - i, v);
                    upd(zero + 2*w - 1 - 2*i, +v);
                    zero++;
                }
                else {
                    upd(zero - 2*w + 1 + 2*i, +v);
                    zero--;
                }
                curw--;
            }
        }

        else {
            int l, r; cin >> l >> r;

            int ll = zero + (rev ? -r : l-1);
            int rr = zero + (rev ? -l : r-1);
            // dbg(zero,ll,rr,l,r);
            cout << get(rr) - get(ll) << endl;
        }

    }

    return 0;
}