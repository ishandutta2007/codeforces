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
    
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi ans(q);
    vector< pair<pii, int> > queries;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        int l = 0 + x;
        int r = (n-1) - y;
        queries.push_back({{r, l}, i});
    }
    sort(all(queries));

    vi tree(n+10);
    auto get = [&](int x) {
        int s = 0;
        for (x++; x < n+10; x+=x&-x) s += tree[x];
        return s;
    };
    auto upd = [&](int x, int d) {
        for (x++; x > 0; x -= x&-x) tree[x] += d;
    };


    int curr = 0;
    for (auto q : queries) {
        auto [r, l] = q.first;
        
        for (int ad = curr; ad <= r; ad++) {
            int need = (ad+1) - a[ad];
            if (need < 0) continue;

            int st = 0, ed = ad;
            while (st < ed) {
                int md = (st+ed+1)/2;
                if (get(md) >= need) st = md;
                else ed = md-1;
            }

            if (get(st) >= need) upd(st, 1);
        }
        curr = r+1;

        ans[q.second] = get(l);
    }

    for (int x : ans) cout << x << '\n';
    return 0;
}