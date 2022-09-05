#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, logn, a[maxn], L[20][maxn], R[20][maxn];

struct SEG {
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
    int mn[maxn << 2], mx[maxn << 2];

    void build(int k, int l, int r, int *v1, int *v2) {
        if (l == r) { mn[k] = v1[l], mx[k] = v2[l]; return; }
        build(ls, l, mid, v1, v2), build(rs, mid + 1, r, v1, v2);
        mn[k] = min(mn[ls], mn[rs]), mx[k] = max(mx[ls], mx[rs]);
    }

    int qmin(int k, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) return mn[k];
        int ans = INT_MAX;
        if (mid >= ql) ans = qmin(ls, l, mid, ql, qr);
        if (mid < qr) ans = min(ans, qmin(rs, mid + 1, r, ql, qr));
        return ans;
    }

    int qmax(int k, int l, int r, int ql, int qr) {
        if (l >= ql && r <= qr) return mx[k];
        int ans = INT_MIN;
        if (mid >= ql) ans = qmax(ls, l, mid, ql, qr);
        if (mid < qr) ans = max(ans, qmax(rs, mid + 1, r, ql, qr));
        return ans;
    }
} T[20];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i + n] = a[i + n + n] = a[i];
    }
    for (int i = 1; i <= 3 * n; i++) {
        L[0][i] = i - a[i], R[0][i] = i + a[i];
    }
    T[0].build(1, 1, 3 * n, L[0], R[0]);
    for (int k = logn = 1; 1 << k <= n; k++, logn++) {
        for (int i = 1; i <= 3 * n; i++) {
            L[k][i] = T[k - 1].qmin(1, 1, 3 * n, L[k - 1][i], R[k - 1][i]);
            R[k][i] = T[k - 1].qmax(1, 1, 3 * n, L[k - 1][i], R[k - 1][i]);
        }
        T[k].build(1, 1, 3 * n, L[k], R[k]);
    }
    for (int i = 1; i <= n; i++) {
        int l = i + n, r = i + n, ans = 0;
        for (int k = logn - 1; ~k; k--) if (r - l + (1 << (k + 1)) < n) {
            int vl = T[k].qmin(1, 1, 3 * n, l, r);
            int vr = T[k].qmax(1, 1, 3 * n, l, r);
            if (vr - vl + 1 < n) l = vl, r = vr, ans |= 1 << k;
        }
        printf("%d ", ans + (n > 1));
    }
    return 0;
}