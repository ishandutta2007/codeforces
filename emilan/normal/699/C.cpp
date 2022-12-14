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

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> c(n + 1, vector<int>(3, 1e9));
    c[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        c[i][0] = min({c[i - 1][0], c[i - 1][1], c[i - 1][2]}) + 1;
        if (a[i] & 1)
            c[i][1] = min(c[i - 1][0], c[i - 1][2]);
        if (a[i] & 2)
            c[i][2] = min(c[i - 1][0], c[i - 1][1]);
    }
    cout << min({c[n][0], c[n][1], c[n][2]});

    return 0;
}