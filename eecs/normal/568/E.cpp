#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, len, a[maxn], b[maxn], c[maxn], in[maxn], foo[255][100010];
int f[maxn], from[maxn], pre[maxn], num[maxn], pos[maxn];
bool used[maxn];
vector<int> V;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (!~a[i]) in[i] = V.size(), V.push_back(i);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    sort(b + 1, b + m + 1);
    auto run = [&](int l, int r) {
        memset(f, 0x3f, sizeof(f)), f[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (~a[i]) {
                int t = lower_bound(f, f + n + 1, a[i]) - f - 1;
                f[t + 1] = a[i], from[t + 1] = i, pre[i] = from[t];
            } else {
                for (int j = 1, k = 0; j <= m; j++) {
                    while (f[k + 1] < b[j]) k++;
                    pos[j] = k;
                }
                for (int j = m; j; j--) {
                    int k = pos[j];
                    f[k + 1] = b[j], from[k + 1] = i;
                    if (in[i] >= l && in[i] <= r) foo[in[i] - l][j] = from[k];
                }
            }
        }
    };
    int l = (int)V.size() - 250, r = V.size();
    run(l, r);
    for (int i = n; i; i--) if (f[i] <= 1000000000) {
        memcpy(c, a, sizeof(a));
        int lst = INT_MAX;
        for (int j = from[i], k = m; j; ) {
            if (!~a[j]) {
                while (b[k] >= lst) k--;
                used[k] = 1, lst = c[j] = b[k];
                while (in[j] < l) l -= 250, r -= 250, run(l, r);
                j = foo[in[j] - l][k--];
            } else {
                lst = a[j], j = pre[j];
            }
        }
        for (int i = 1, j = 1; i <= n; i++) {
            if (!~c[i]) {
                while (used[j]) j++;
                c[i] = b[j++];
            }
            printf("%d ", c[i]);
        }
        break;
    }
    return 0;
}