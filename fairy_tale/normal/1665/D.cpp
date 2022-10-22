#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

void solve()
{
    LL base = 1ULL << 29, x = 0, g;

    for (int i = 0; i < 29; i++) {
        x |= 1ULL << i;
        cout << "? " << x << " " << base + x << endl;
        cout.flush();
        cin >> g;

        if (g < (1ULL << (i + 1))) {
            x ^= 1ULL << i;
        }
    }

    LL u = (1ULL << 30) - x;
    if (u > 1000000000) {
        g = 0;
    } else {
        cout << "? " << u << " " << u * 2 << endl;
        cout.flush();
        cin >> g;
    }

    if (g == u) cout << "! " << u << endl;
    else cout << "! " << u - (1ULL << 29) << endl;
    cout.flush();
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}