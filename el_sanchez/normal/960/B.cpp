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

const int MAXN = 1111;

int n, k[2];
int a[MAXN], b[MAXN];

bool read() {
    if (!(cin >> n >> k[0] >> k[1])) {
        return 0;
    }
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, n) {
        cin >> b[i];
    }
    return 1;
}

ll solve() {
    multiset<ll> squares;
    int K = k[0] + k[1];
    forn(i, n) {
        squares.insert(-abs(a[i] - b[i]));
    }

    forn(i, K) {
        auto ptr = squares.begin();
        ll x = -(*ptr);
        squares.erase(ptr);

        x = abs(x - 1);
        squares.insert(-x);
    }

    ll ans = 0;
    for (auto x: squares) {
        ans += 1ll * x * x;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        cout << solve() << '\n';
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}