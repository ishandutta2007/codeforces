#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, a[maxn], b[maxn], c[maxn], st1[20][maxn], st2[20][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        st1[0][i] = b[i] = min(a[i], max(a[i - 1], a[i + 1]));
        c[i] = max(a[i], min(a[i - 1], a[i + 1]));
    }
    for (int i = 1; i <= n; i++) {
        st2[0][i] = max(c[i], c[i + 1]);
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
            st2[i][j] = max(st2[i - 1][j], st2[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int k = 0; k < n; k++) {
        if (k >= n - 2) {
            printf("%d ", *max_element(a + 1, a + n + 1));
        } else if ((n - k) & 1) {
            int l = (1 + n - k) / 2, r = (k + 1 + n) / 2;
            int k = log2(r - l + 1);
            printf("%d ", max(st1[k][l], st1[k][r - (1 << k) + 1]));
        } else {
            int l = (1 + n - k) / 2, r = (k + 1 + n) / 2;
            int k = log2(r - l + 1);
            printf("%d ", max(st2[k][l], st2[k][r - (1 << k) + 1]));
        }
    }
    return 0;
}