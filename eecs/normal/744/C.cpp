#include <bits/stdc++.h>
using namespace std;

int n, r[16], b[16], sum[1 << 16], f[1 << 16][150];
char type[16];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> type[i] >> r[i] >> b[i];
    }
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            sum[i] += r[j];
        }
    }
    for (int i = 0; i < 1 << n; i++) {
        int A = 0, B = 0;
        for (int j = 0; j < n; j++) if (i >> j & 1) {
            type[j] == 'R' ? A++ : B++;
        }
        for (int j = 0; j < n; j++) if (!(i >> j & 1)) {
            for (int k = 0; k < 150; k++) if (f[i][k] < 1e9) {
                chk(f[i | (1 << j)][sum[i | (1 << j)] - (sum[i] - k) - max(0, r[j] - A)], f[i][k] + max(0, b[j] - B));
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < 150; i++) {
        chk(ans, max(sum[(1 << n) - 1] - i, f[(1 << n) - 1][i]));
    }
    cout << ans + n << '\n';
    return 0;
}