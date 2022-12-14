#include <bits/stdc++.h>

using namespace std;

using i64 = uint64_t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    i64 num = 0;
    i64 denom = n;

    i64 dist_sum = 0;
    for (i64 i = 0; i < n; i++) {
        num += a[i] + 2 * (i * a[i] - dist_sum);
        dist_sum += a[i];
    }

    i64 g = gcd(num, denom);
    num /= g;
    denom /= g;

    cout << num << ' ' << denom << '\n';
}