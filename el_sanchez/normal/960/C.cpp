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

ll X;
int n;

bool read() {
    if (!(cin >> X >> n)) {
        return 0;
    }
    return 1;
}

void solve() {
    vector<ll> a;
    ll last = 1; 
    while (X > 0) {
        int k = 0;
        while ((1ll << k) - 1 <= X) {
            k++;
        }
        k--;
        assert(k >= 1);

        forn(i, k) {
            a.pb(last);
        }
        last += n + 2;

        X -= (1ll << k) - 1;
        assert(X >= 0);
    }

    cout << sz(a) << '\n';
    for (auto x: a) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        solve();
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}