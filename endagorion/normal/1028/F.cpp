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

i64 vnorm(const pii &a) {
    return 1LL * a.fi * a.fi + 1LL * a.se * a.se;
}

const i64 M = 4092939172843LL, B = 2019211;

vector<pi64> buckets[B];
map<i64, vector<pii> > ps;

pi64 &get_entry(pii s) {
    i64 X = M * s.fi / s.se;
    auto &bucket = buckets[X % B];
    for (auto &p: bucket) {
        if (p.fi == X) return p;
    }
    bucket.pb(mp(X, 0));
    return bucket.back();
}

pii operator+(const pii &a, const pii &b) {
    return {a.fi + b.fi, a.se + b.se};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(i, B) buckets[i].reserve(5);

    int q;
    cin >> q;

    int K = 0;

    while (q--) {
        int type;
        pii p;
        cin >> type >> p.fi >> p.se;
        if (type == 1) {
            i64 n = vnorm(p);
            auto &v = ps[n];
            ++get_entry(p).se;
            for (auto q: v) get_entry(p + q).se += 2;
            v.pb(p);
            ++K;
        } else if (type == 2) {
            i64 n = vnorm(p);
            auto &v = ps[n];
            auto it = find(all(v), p);
            v.erase(it);
            --get_entry(p).se;
            for (auto q: v) get_entry(p + q).se -= 2;
            --K;
        } else {
            cout << K - get_entry(p).se << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}