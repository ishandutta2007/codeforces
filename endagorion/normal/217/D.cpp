/*

#include <string>
#include <bits/functexcept.h>
#include <iosfwd>
#include <bits/cxxabi_forced.h>
#include <bits/functional_hash.h>

#pragma push_macro("__SIZEOF_LONG__")
#pragma push_macro("__cplusplus")
#define __SIZEOF_LONG__ __SIZEOF_LONG_LONG__
#define unsigned unsigned long
#define __cplusplus 201102L

#define __builtin_popcountl __builtin_popcountll
#define __builtin_ctzl __builtin_ctzll

#include <bitset>

#pragma pop_macro("__cplusplus")
#pragma pop_macro("__SIZEOF_LONG__")
#undef unsigned
#undef __builtin_popcountl
#undef __builtin_ctzl*/

#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef bitset<120> bs;
const int P = 1000000000 + 7;

struct TComp {
    bool operator()(const pair<bs, int> &a, const pair<bs, int> &b) const {
        int i = (a.fi ^ b.fi)._Find_first();
        if (i >= 120) return false;
        return b.fi[i];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, t;
    cin >> n >> m >> t;
    vi64 cnt(m / 2 + 1);
    forn(i, t) {
        int x;
        cin >> x;
        x %= m;
        uin(x, m - x);
        ++cnt[x];
    }
    bs init;
    init[0] = 1;
//    __uint128_t init = 1;
    vector<pair<bs, int> > s = {{init, 1}};
    bs allb;
//    __uint128_t allb = ((__uint128_t)1 << m) - 1;
    forn(i, m) allb[i] = 1;
    for1(l, m / 2) {
        vector<pair<bs, int> > ns;
        if (cnt[l]) for (auto [b, v]: s) {
            if (b[l]) continue;
            ns.pb(mp((b | (b << l) | (b >> (m - l)) | (b >> l) | (b << (m - l))) & allb, v * cnt[l] % P));
        }
        sort(all(ns), TComp());
        //        s.erase(unique(all(s)), s.end());
//        __uint128_t last = -1;
        bs last;
        int sum = 0;
        for (auto [b, x]: ns) {
            if (b != last) {
                if (sum) s.pb(mp(last, sum));
                last = b;
                sum = 0;
            }
            sum += x;
            if (sum >= P) sum -= P;
        }
        if (sum) s.pb(mp(last, sum));
//        cerr << l << ' ' << s.size() << '\n';
    }

    int ans = 0;
    for (auto [b, v]: s) (ans += v) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}