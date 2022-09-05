#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], b[maxn], c[maxn], ra[maxn], rb[maxn], pos[maxn];

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i]++;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]), b[i]++;
    }
    for (int i = n; i; i--) {
        ra[i] = sum(a[i]), add(a[i], 1);
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i; i--) {
        rb[i] = sum(b[i]), add(b[i], 1);
    }
    for (int i = n; i; i--) {
        pos[i] = (i == n ? 0 : pos[i + 1] / (n - i)) + ra[i] + rb[i];
    }
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        add(i, 1);
    }
    for (int i = 1; i <= n; i++) {
        pos[i] %= n - i + 1;
        int l = 1, r = n, ans;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sum(mid) >= pos[i] + 1) r = (ans = mid) - 1;
            else l = mid + 1;
        }
        add(ans, -1), printf("%d ", ans - 1);
    }
    return 0;
}