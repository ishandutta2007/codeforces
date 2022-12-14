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
    vector<pair<int, int>> trees(n + 2);
    trees[0] = {-2e9, 0};
    trees[n + 1] = {2147483647, 0};
    vector<vector<int>> c(n + 1, vector<int>(3, -1e9));
    for (int i = 1; i <= n; i++)
        cin >> trees[i].fi >> trees[i].se;

    c[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        c[i][0] = *max_element(all(c[i - 1]));

        if (trees[i - 1].fi < trees[i].fi - trees[i].se)
            c[i][1] = max(c[i - 1][0] + 1, c[i - 1][1] + 1);
        if (trees[i - 1].fi + trees[i - 1].se < trees[i].fi - trees[i].se)
            c[i][1] = max(c[i][1], c[i - 1][2] + 1);
        
        if (trees[i].fi + trees[i].se < trees[i + 1].fi)
            c[i][2] = *max_element(all(c[i - 1])) + 1;
    }

    cout << *max_element(all(c[n]));

    return 0;
}