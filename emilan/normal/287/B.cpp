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

    ll n; int k; cin >> n >> k;
    int l = 0, r = k - 1, m;
    ll p;
    while (l < r) {
        m = l + (r - l) / 2;
        p = (ll)(2 * k - m - 1) * m / 2 + 1;
        if (p >= n)
            r = m;
        else
            l = m + 1;
    }
    p = (ll)(2 * k - l - 1) * l / 2 + 1;
    if (p >= n)
        cout << l;
    else
        cout << -1;

    return 0;
}