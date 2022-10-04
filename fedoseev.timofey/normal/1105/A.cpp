#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1e9;
    int who = -1;
    for (int t = 0; t <= 200; ++t) {
        int cur = 0;
        for (int i = 0; i < n; ++i) cur += min(abs(a[i] - (t - 1)), min(abs(a[i] - t), abs(a[i] - (t + 1))));
        ans = min(ans, cur);
        if (ans == cur) who = t;
    }
    cout << who << ' ' << ans << '\n';
}