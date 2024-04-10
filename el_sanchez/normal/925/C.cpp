#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAXN = (int)2e5 + 100;

int n;
ll a[MAXN];
int hb[MAXN];

bool read() {
    if (scanf("%d", &n) < 1) {
        return 0;
    }
    forn(i, n) {
        scanf("%lld", &a[i]);
    }
    return 1;
}

int bit(ll x, int k) {
    return (x >> k) & 1;
}

const int B = 60;
vi blocks[B];

vector<ll> solve() {
    forn(i, B) {
        blocks[i].clear();
    }
    forn(i, n) {
        hb[i] = -1;
        forn(j, B) {
            if (bit(a[i], j)) {
                hb[i] = max(hb[i], j);
            }
        }
        blocks[hb[i]].pb(i);
    }

    forn(i, B) {
        //eprintf("sz(%d)=%d\n", i, sz(blocks[i]));
    }
    vi order;
    ford(i, B) {
        if (blocks[i].empty()) {
            continue;
        }

        vi n_order;
        int optr = 0, ptr = 0;
        n_order.pb(blocks[i][ptr++]);
        while (optr < sz(order)) {
            n_order.pb(order[optr++]);
            if (bit(a[n_order.back()], i) && ptr < sz(blocks[i])) {
                n_order.pb(blocks[i][ptr++]);
            }
        }
        if (ptr < sz(blocks[i])) {
            return {};
        }

        order = n_order;
    }

    assert(sz(order) == n);

    vector<ll> ans;
    forn(i, n) {
        ans.pb(a[order[i]]);
    }
    return ans;
}

int main() {

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        auto v = solve();
        if (v.empty()) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
            for (auto x: v) {
                printf("%lld ", x);
            }
            cout << '\n';
        }
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}