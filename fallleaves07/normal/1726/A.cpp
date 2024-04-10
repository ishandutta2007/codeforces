#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[i] - a[0]);
    }
    for (int i = 0; i + 1 < n; i++) {
        ans = max(ans, a[n - 1] - a[i]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, a[i] - a[(i + 1) % n]);
    }
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}