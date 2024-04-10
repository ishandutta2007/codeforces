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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif
    
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];
    vvi seq;
    bool fl = 0;
    while (!is_sorted(all(a))) {
        vi op;
        if (fl) reverse(all(a));
        int p = 0;
        while (p < n && a[p] == p + 1) ++p, op.pb(1);
        if (p < n) {
            int q = p;
            while (a[q] != p + 1) ++q;
            ++q;
            op.pb(q - p);
            if (q < n) op.pb(n - q);
        }
        if (fl) {
            reverse(all(op));
            reverse(all(a));
        }
        if (op.size() > 1) seq.pb(op);
        vvi parts;
        p = 0;
        for (int x: op) {
            vi part(a.begin() + p, a.begin() + p + x);
            parts.pb(part);
            p += x;
        }
        reverse(all(parts));
        p = 0;
        for (vi v: parts) {
            for (int x: v) a[p++] = x;
        }
//        for (int x: a) cerr << x << ' ';
//        cerr << '\n';
        fl ^= 1;
    }
    assert(seq.size() <= n);
    cout << seq.size() << '\n';
    for (auto w: seq) {
        cout << w.size() << ' ';
        for (int x: w) cout << x << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}