#include <cstdio>
#include <algorithm>
const int MAX = 3e5;
long long a[MAX];

bool check(int n, long long a[]) {
    for (int i = 2; i <= n; i += 2)
        if (a[i] != a[i - 1])
            return false;
    long long sum, cur, diff;
    sum = cur = 0;
    for (int i = 3; i <= n; i += 2) {
        long long diff = a[i] - a[i - 1];
        if (!diff || diff % (i - 1))
            return false;
        sum += cur += diff / (i - 1);
    }
    diff = a[1] - sum * 2;
    if (diff <= 0 || diff % n)
        return false;
    return true;
}

void solve() {
    int n; scanf("%d", &n); n *= 2;
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    std::sort(a + 1, a + n + 1);
    printf("%s\n", check(n, a) ? "YES" : "NO");
}

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve();
}