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

const int LVL = 61;

int n;
ll add[LVL], add_f[LVL];

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    return 1;
}

int get_lvl(ll X) {
    int k = 0;
    while ((1ll << k) <= X) {
        k++;
    }
    k--;
    return k;
}

void get(int lvl, ll X) {
    ll len = 1ll << lvl;
    ll val = X - len;
    val = (val + add[lvl]) % len;
    printf("%I64d ", len + val);

    if (lvl == 0) {
        printf("\n");
        return;
    }

    get(lvl - 1, ((X - len + add_f[lvl]) % len + len) / 2);

}

void solve() {
    memset(add, 0, sizeof(add));
    memset(add_f, 0, sizeof(add_f));
    forn(i, n) {
        int t;
        ll X, K;
        scanf("%d %I64d", &t, &X);

        int lvl = get_lvl(X);
        ll len = 1ll << lvl;

        if (t == 3) {
            ll tX = X - len;
            tX += len - add[lvl];
            tX %= len;
            tX += len;

            get(lvl, tX);    
            continue;
        }

        scanf("%I64d", &K);

        K %= len;
        K += len;
        K %= len;
        
        if (t == 1) {
            add[lvl] += len - K;
            add[lvl] %= len;
        } else {
            add_f[lvl] += K;
            add_f[lvl] %= len;
        }
    }
}

int main() {
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