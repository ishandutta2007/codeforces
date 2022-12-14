#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
    freopen("io\\err.txt", "w", stderr);
#endif
}

using   ll        = long long;
#define debug(x)    cerr << #x << ": <" << (x) << ">\n"
#define dotc()      int tcs; if (cin >> tcs) for (int tc = 0; tc < tcs; tc++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second
#define mod         1000000007

int main() {
    ioThings();

    cout << setprecision(6) << fixed;

    int n, k; cin >> n >> k;
    double len = 0;
    int px, py;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        if (!i)
            px = x, py = y;
        len += hypot(x - px, y - py);
        px = x, py = y;
    }

    cout << len * k / 50;

    return 0;
}