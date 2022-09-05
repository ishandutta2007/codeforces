#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, pre_mn[400010], pre_mx[400010], suf_mn[400010], suf_mx[400010];
long long ans;

void chk_min(int &x, int y) {
    if (x > y) x = y;
}

void chk_max(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d", &n);
    memset(pre_mn, 0x3f, sizeof(pre_mn));
    memset(suf_mn, 0x3f, sizeof(suf_mn));
    memset(pre_mx, -0x3f, sizeof(pre_mx));
    memset(suf_mx, -0x3f, sizeof(suf_mx));
    for (int i = 1, p, q; i <= n; i++) {
        scanf("%d %d", &p, &q);
        chk_min(pre_mn[p + q + 200005], p - q);
        chk_max(pre_mx[p + q + 200005], p - q);
        chk_min(suf_mn[p + q + 200005], p - q);
        chk_max(suf_mx[p + q + 200005], p - q);
    }
    for (int i = 2; i < 400010; i++) {
        chk_min(pre_mn[i], pre_mn[i - 2]);
        chk_max(pre_mx[i], pre_mx[i - 2]);
    }
    for (int i = 400010 - 3; ~i; i--) {
        chk_min(suf_mn[i], suf_mn[i + 2]);
        chk_max(suf_mx[i], suf_mx[i + 2]);
    }
    for (int i = 1; i < 400010 - 3; i++) {
        ans += max(0, min(pre_mx[i - 1], suf_mx[i + 1]) - max(pre_mn[i - 1], suf_mn[i + 1]));
    }
    printf("%lld\n", ans / 2);
    return 0;
}