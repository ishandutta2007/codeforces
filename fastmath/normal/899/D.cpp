#include <bits/stdc++.h>

using namespace std;

#define int long long

bool check(int want, int n) {
    return want <= 2 * n - 1;    
}

int get(int want, int n) {
    if (2 * n - 1 < want) return 0;
    if (want <= n) return want / 2;
    int l = want - n;
    return (n - l + 1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int want = 0;
    while (check(want * 10 + 9, n)) want = want * 10 + 9;

    if (n < 5) {
        cout << n * (n - 1) / 2 << '\n';
        exit(0);
    }

    int f = 1;
    for (int i = 0; i < to_string(want).size(); ++i) f *= 10;

    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans += get(i * f + want, n);    
    }

    cout << ans << '\n';
    return 0;
}