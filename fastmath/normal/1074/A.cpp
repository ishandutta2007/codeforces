#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

int a[MAXN];
vector <int> v;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int MX = 1000 * 1000 * 1000;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int add = 0;
    for (int i = 0; i < m; ++i) {
        int l, r, y;
        cin >> l >> r >> y;
        if (l != 1) continue;
        if (r == MX) ++add;
        else v.push_back(r);
    }

    sort(v.begin(), v.end());

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int newans = i + (int)v.size() - (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
        ans = min(ans, newans);      
    }   
    ans = min(ans, n);

    cout << ans + add << '\n';

    return 0;
}