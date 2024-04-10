#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn], ans[maxn], num[60];
int f[maxn][1 << 17], pre[maxn][1 << 17];
bool pr[60];

int main() {
    vector<int> V;
    for (int i = 2; i < 60; i++) if (!pr[i]) {
        V.push_back(i);
        for (int j = i + i; j < 60; j += i) pr[j] = 1;
    }
    for (int i = 1; i < 60; i++) {
        for (int j = 0; j < V.size(); j++) {
            if (!(i % V[j])) num[i] |= 1 << j;
        }
    }
    scanf("%d", &n);
    memset(f, 0x3f, sizeof(f)), f[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < 1 << 17; j++) if (f[i][j] < 1e9) {
            for (int k = 1; k < 60; k++) if (!(j & num[k])) {
                int w = f[i][j] + abs(a[i] - k);
                if (w < f[i + 1][j | num[k]]) f[i + 1][j | num[k]] = w, pre[i + 1][j | num[k]] = k;
            }
        }
    }
    int mn = *min_element(f[n + 1], f[n + 1] + (1 << 17));
    for (int S = 0; S < 1 << 17; S++) if (mn == f[n + 1][S]) {
        for (int i = n; i; i--) {
            ans[i] = pre[i + 1][S], S ^= num[ans[i]];
        }
        break;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}