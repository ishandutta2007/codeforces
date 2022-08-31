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

const int maxn = 210000;
i64 a[maxn], pa[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        cin >> a[i];
        pa[i + 1] = pa[i] + a[i];
    }

    vector<pi64> ch;
    set<int> mins;
    multiset<int> dist = {0};
    set<pi64> evs;
    pa[n] -= 1e18;
    
    forn(i, n) {
        mins.insert(i);
        dist.insert(1);
        evs.insert({pa[i + 1] - pa[i] - 1, i + 1});
//        cerr << i + 1 << ' ' << pa[i + 1] - pa[i] - 1 << '\n';
    }
    mins.insert(n);

    ch = {{(i64)1e9, *dist.rbegin()}};
    while (!evs.empty()) {
        auto p = *evs.rbegin();
        if (p.fi < 0) break;
//        cerr << p.fi << ' ' << p.se << '\n';
        int i = p.se;
        mins.erase(i);
        auto it = mins.lower_bound(i);
        int prv, nxt;
        if (it == mins.begin()) prv = -1;
        else {
            prv = *--it;
            ++it;
        }
        if (it == mins.end()) nxt = n + 1;
        else nxt = *it;

        if (prv != -1) {
            dist.erase(dist.find(i - prv));
            evs.erase({(pa[i] - pa[prv] - 1) / (i - prv), i});
        }
        if (nxt != n + 1) {
            dist.erase(dist.find(nxt - i));
            evs.erase({(pa[nxt] - pa[i] - 1) / (nxt - i), nxt});
        }
        if (prv != -1 && nxt != n + 1) {
            dist.insert(nxt - prv);
            evs.insert(mp((pa[nxt] - pa[prv] - 1) / (nxt - prv), nxt));
        }
        ch.pb({p.fi, *dist.rbegin()});
    }
//    for (auto [x, y]: ch) cerr << x << ' ' << y << '\n';

    vi qs(m);
    forn(i, m) cin >> qs[i];
    reverse(all(qs));
    vi ans(m);
    int ptr = -1;
    forn(i, m) {
        while (ptr + 1 < ch.size() && ch[ptr + 1].fi >= qs[i]) ++ptr;
        ans[i] = ch[ptr].se;
    }

    reverse(all(ans));
    for (int x: ans) cout << x - 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}