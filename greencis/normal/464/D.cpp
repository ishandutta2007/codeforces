#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAX_N = 100'000;
ld dp[MAX_N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    int upper = min(n, 100'000'000 / n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= upper; ++j) {
            dp[j] = ((k - 1) * dp[j] + (j * dp[j] + dp[j + 1] + j * ld(j + 3) / 2) / (j + 1)) / k;
        }
    }
    cout << setprecision(17) << fixed << dp[1] * k << endl;
}