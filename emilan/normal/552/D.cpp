#include <iostream>

using namespace std;

__attribute__((target("avx2"))) void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((a[j] - a[i]) * (b[k] - b[i])
                    - (a[k] - a[i]) * (b[j] - b[i])) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}