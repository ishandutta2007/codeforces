#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int P, n, all, sum, a[maxn], inv[maxn];
vector<int> cand;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &P, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), inv[i] = qp(i, P - 2);
        (sum += a[i]) %= P;
    }
    if (n == P) puts("0 1"), exit(0);
    if (n == 1) printf("%d 0", a[1]), exit(0);
    sort(a + 1, a + n + 1);
    auto find = [&](int x) {
        return binary_search(a + 1, a + n + 1, x);
    };
    sum = 1LL * sum * inv[n] % P;
    for (int i = 1; i <= n; i++) {
        int d = 2LL * (sum - a[i] + P) * inv[n - 1] % P;
        if (!find((a[i] - d + P) % P)) cand.push_back(d);
    }
    int cnt = 0;
    for (int d : cand) {
        int fir = (sum + P - 1LL * (n - 1) * inv[2] % P * d % P) % P;
        int l = 0;
        while (l < n && find((fir + 1LL * l * d) % P)) l++;
        if (l == n) printf("%d %d\n", fir, d), exit(0);
    }
    puts("-1");
    return 0;
}