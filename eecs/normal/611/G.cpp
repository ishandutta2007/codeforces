#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010, P = 1000000007;
int n;
ll x[maxn], y[maxn], s1[maxn], s2[maxn];
__int128 pre[maxn];

int main() {
    scanf("%d", &n);
    ll all = 0, ans = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        x[i + n] = x[i], y[i + n] = y[i];
        all += (x[i] - x[1]) * (y[i - 1] - y[1]) - (x[i - 1] - x[1]) * (y[i] - y[1]);
    }
    for (int i = 1; i <= n << 1; i++) {
        pre[i] = pre[i - 1] + x[i + 1] * y[i] - x[i] * y[i + 1];
        s1[i] = (s1[i - 1] + x[i]) % P;
        s2[i] = (s2[i - 1] + y[i]) % P;
    }
    auto calc = [&](int i, int j) {
        return pre[j - 1] - pre[i - 1] + x[i] * y[j] - y[i] * x[j];
    };
    for (int i = 1, j = 2; i <= n; i++) {
        if (i > 1) {
            cur -= (pre[i - 1] - pre[i - 2]) % P * (j - i + 1) % P;
            cur += (x[i] - x[i - 1]) * (s2[j] - s2[i - 1]) % P;
            cur -= (y[i] - y[i - 1]) * (s1[j] - s1[i - 1]) % P;
            cur = (cur % P + P) % P;
        }
        j = max(j, i + 1);
        while (j < i + n && calc(i, j + 1) * 2 <= all) {
            if (calc(i, j + 1) * 2 == all && j > n) break;
            (cur += calc(i, ++j)) %= P;
        }
        if (calc(i, j) * 2 == all && j > n) {
            ans = (ans - calc(i, j) % P + P) % P;
        }
        (ans += cur) %= P;
    }
    all = 1LL * n * (n - 3) / 2 % P * (all % P) % P;
    all = (all - ans * 2) % P;
    printf("%lld\n", (all + P) % P);
    return 0;
}