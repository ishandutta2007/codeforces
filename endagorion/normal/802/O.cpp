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

const int maxn = 510000;
i64 a[maxn], b[maxn];
int n;

pi64 solve(i64 lambda) {
    priority_queue<pi64> s;
    i64 v0 = 0, b0 = n;
    forn(i, n) {
        s.push(mp(-a[i], 0));
        v0 += b[i] - lambda;
        s.push(mp(-(lambda - b[i]), 1));
        auto p = s.top();
        s.pop();
        v0 -= p.fi;
        if (p.se) --b0;
    }
    return mp(v0, b0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k;
    cin >> n >> k;
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    i64 L = 0, R = 2e9;
    pi64 lp = solve(0), rp = solve(R);
    rp.fi += rp.se * R;
    while (R - L > 1) {
        i64 M = (L + R) / 2;
        auto p = solve(M);
        p.fi += p.se * M;
//        cerr << M << ' ' << p.fi << ' ' << p.se << '\n';
        if (p.se < k) L = M, lp = p;
        else R = M, rp = p;
    }

//    cerr << lp.fi << ' ' << lp.se << '\n';
//    cerr << rp.fi << ' ' << rp.se << '\n';

    assert((rp.fi - lp.fi) % (rp.se - lp.se) == 0);
    cout << lp.fi + (rp.fi - lp.fi) / (rp.se - lp.se) * (k - lp.se) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}