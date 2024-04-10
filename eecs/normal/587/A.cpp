#include <bits/stdc++.h>
using namespace std;

const int maxn = 1100000;
int n, w[maxn], cnt[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]), cnt[w[i]]++;
    }
    for (int i = 0; i < maxn; i++) if (cnt[i]) {
        int o = cnt[i] / 2;
        cnt[i] -= o * 2, cnt[i + 1] += o;
    }
    printf("%d\n", accumulate(cnt, cnt + maxn, 0));
    return 0;
}