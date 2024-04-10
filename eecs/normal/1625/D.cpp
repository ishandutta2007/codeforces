#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, K, f[maxn], pre[maxn];
int tot = 1, ch[maxn * 32][2], mx[maxn * 32], from[maxn * 32];
array<int, 2> a[maxn];

int main() {
    scanf("%d %d", &n, &K), K--;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i][0]), a[i][1] = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        // (a[j][0] ^ a[i][0]) > k
        if (K < 0) {
            if (mx[1] > f[i]) f[i] = mx[1], pre[i] = from[1];
        } else {
            for (int j = 29, cur = 1; ~j; j--) {
                int c = a[i][0] >> j & 1;
                if (K >> j & 1) {
                    cur = ch[cur][!c];
                } else {
                    if (mx[ch[cur][!c]] > f[i]) f[i] = mx[ch[cur][!c]], pre[i] = from[ch[cur][!c]];
                    cur = ch[cur][c];
                }
            }
        }
        f[i]++;
        int cur = 1;
        if (f[i] > mx[cur]) mx[cur] = f[i], from[cur] = i;
        for (int j = 29; ~j; j--) {
            int c = a[i][0] >> j & 1;
            if (!ch[cur][c]) ch[cur][c] = ++tot;
            cur = ch[cur][c];
            if (f[i] > mx[cur]) mx[cur] = f[i], from[cur] = i;
        }
    }
    int k = max_element(f + 1, f + n + 1) - f;
    if (f[k] == 1) puts("-1"), exit(0);
    printf("%d\n", f[k]);
    for (int i = k; i; i = pre[i]) {
        printf("%d ", a[i][1]);
    }
    return 0;
}