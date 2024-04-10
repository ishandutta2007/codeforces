#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4000000 + 2;
int m;
void add(int& x, int y) {
    x += y;
    if (x >= m) x -= m;
}
int sum[maxn], dp, pre;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> m;
    sum[1] = 1;
    sum[2] = m - 1;
    for (int i = 1; i <= n; i += 1) {
        add(sum[i], sum[i - 1]);
        dp = sum[i];
        add(dp, pre);
        if (i == n) cout << dp;
        add(pre, dp);
        for (int j = 2; j * i <= n; j += 1) {
            int L = j * i, R = min({j * i + j - 1, n});
            add(sum[L], dp);
            if (dp) add(sum[R + 1], m - dp);
        }
    }
    return 0;
}