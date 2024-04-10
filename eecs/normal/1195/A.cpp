#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, k, ans, cnt[maxn];

int main() {
    scanf("%d %d", &n, &k);
    while (n--) {
        int x; scanf("%d", &x), cnt[x]++;
    }
    int t = 0;
    for (int i = 1; i <= k; i++) {
        ans += cnt[i] - (cnt[i] % 2);
        if (cnt[i] % 2) t++;
    }
    printf("%d\n", ans + (int)ceil(1.0 * t / 2));
    return 0;
}