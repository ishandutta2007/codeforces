#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 5e5 + 7;
const int INF = 1e18 + 7;

int a[MAXN];
int prefmin[MAXN], postmin[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    prefmin[0] = INF;
    for (int i = 0; i < n; ++i) {
        prefmin[i + 1] = min(prefmin[i], a[i]);
    }
    
    postmin[n] = INF;
    for (int i = n - 1; i >= 0; --i) {
        postmin[i] = min(postmin[i + 1], a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += abs(a[i]);
    }

    if (n == 1) {
        cout << a[0] << '\n';
        exit(0);
    }

    int ans = -INF;
    for (int i = 1; i < n - 1; ++i) {
        ans = max(ans, sum - abs(a[i]) + a[i] - abs(prefmin[i]) - abs(postmin[i + 1]) - prefmin[i] - postmin[i + 1]);
    }
    ans = max(ans, sum - abs(a[0]) + a[0] - abs(postmin[1]) - postmin[1]);
    ans = max(ans, sum - abs(a[n - 1]) + a[n - 1] - abs(prefmin[n - 1]) - prefmin[n - 1]);

    cout << ans << '\n';
    return 0;
}