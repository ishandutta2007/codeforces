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

template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
template<class A, class B> str ts(pair<A,B> p) {return "("+ts(p.first)+", "+ts(p.second)+")"; }
 
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
    
    int n, s;
    cin >> n >> s;

    long long tot = 0;
    long long num_slices = 0;

    multiset< pii > people;

    for (int i = 0; i < n; i++) {
        int ns, a, b;
        cin >> ns >> a >> b;

        tot += a * 1ll * ns;
        if (ns >= 2*s) {
            ll extra = ((ns - s) / s) * s;
            tot += max(0, b-a) * 1ll * extra;
            ns -= extra;
        }
        
        num_slices += ns;
        people.insert({a-b, ns});
    }

    ll num_pizzas = (num_slices + s - 1) / s;
    ll need = ((num_slices+s-1) % s) + 1;
    ll best = tot;

    // dbg(num_slices, num_pizzas, need);

    for (int b_pizzas = 1; b_pizzas <= num_pizzas; b_pizzas++) {
        ll nd = need;
        ll rem = s;
        if (b_pizzas == num_pizzas) rem = need;

        // dbg(b_pizzas, tot);
        while (rem) {
            pii f = *people.begin();
            people.erase(people.begin());
            if (f.second == 0) continue;

            ll take;

            if (f.first >= 0) {
                take = min(nd, (ll)f.second);
                nd -= take;
                tot += take * 1ll * (-f.first);
                if (nd == 0) {
                    // dbg(tot);
                    best = max(best, tot);
                    cout << best << endl;
                    return 0;
                }
            }
            else {
                take = min(rem, (ll)f.second);
                nd = max(0LL, nd-take);
                tot += take * 1ll * (-f.first);
                rem -= take;
            }

            // dbg("take ", take, f.first);
            pii nw = {f.first, f.second - take};
            people.insert(nw);
        }

        best = max(best,tot);
    }

    cout << best << endl;
    return 0;
}