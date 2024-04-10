#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL g(int i, int j) {
    if ((i & 1) == (j & 1))
        if ((i & 2) == (j & 2))
            return 0;
    return 1;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    LL c[4]{};
    for (int i = 0; i < n; i += 1) {
        cin >> x[i] >> y[i];
        x[i] /= 2;
        y[i] /= 2;
        c[((x[i] & 1) << 1) | (y[i] & 1)] += 1;
    }
    LL ans = 0;
    for (int i = 0; i < 4; i += 1)
        for (int j = 0; j < 4; j += 1)
            for (int k = 0; k < 4; k += 1)
                if ((g(i, j) + g(j, k) + g(i, k)) % 2 == 0) {
                    ans += c[i] * (c[j] - (i == j)) * (c[k] - (i == k) - (j == k));
                }
    cout << ans / 6;
    return 0;
}