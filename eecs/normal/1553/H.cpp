#include <bits/stdc++.h>
using namespace std;

int n, K, a[1 << 19], f[1 << 19], ans[20][1 << 19], tmp[1 << 19];
int tot = 1, ch[11000000][2];
vector<int> zero[19][1 << 19], one[19][1 << 19];

void ins(int K, int x) {
    int cur = 1;
    for (int i = K - 1; ~i; i--) {
        int c = x >> i & 1;
        if (!ch[cur][c]) ch[cur][c] = ++tot;
        cur = ch[cur][c];
    }
}

int qmin(int K, int x) {
    int ans = 0, cur = 1;
    for (int i = K - 1; ~i; i--) {
        int c = x >> i & 1;
        if (ch[cur][c]) cur = ch[cur][c];
        else cur = ch[cur][c ^ 1], ans |= 1 << i;
    }
    return ans;
}

int qmax(int K, int x) {
    int ans = 0, cur = 1;
    for (int i = K - 1; ~i; i--) {
        int c = x >> i & 1;
        if (ch[cur][c ^ 1]) cur = ch[cur][c ^ 1], ans |= 1 << i;
        else cur = ch[cur][c];
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        int x = 0;
        for (int j = K - 1; ~j; j--) {
            if (!(a[i] >> j & 1)) {
                zero[j][x].push_back(a[i]);
            } else {
                one[j][x].push_back(a[i]), x |= 1 << j;
            }
        }
    }
    memset(ans, 0x3f, sizeof(ans));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 1 << K; j++) {
            if (zero[i][j].empty() || one[i][j].empty()) continue;
            for (int k = 1; k <= tot; k++) ch[k][0] = ch[k][1] = 0;
            tot = 1;
            for (int x : one[i][j]) ins(i + 1, x);
            for (int k = 0; k < 1 << (i + 1); k++) {
                if (k < (1 << i)) { // (x ^ k) < (y ^ k)
                    tmp[k] = qmin(i + 1, k);
                } else { // (x ^ k) > (y ^ k)
                    tmp[k] = -qmax(i + 1, k);
                }
            }
            for (int k = 1; k <= tot; k++) ch[k][0] = ch[k][1] = 0;
            tot = 1;
            for (int x : zero[i][j]) ins(i + 1, x);
            for (int k = 0; k < 1 << (i + 1); k++) {
                if (k < (1 << i)) { // (x ^ k) < (y ^ k)
                    tmp[k] -= qmax(i + 1, k);
                } else { // (x ^ k) > (y ^ k)
                    tmp[k] += qmin(i + 1, k);
                }
            }
            for (int k = 0; k < 1 << (i + 1); k++) {
                ans[i + 1][k] = min(ans[i + 1][k], tmp[k]);
            }
        }
    }
    for (int i = 0; i < 1 << K; i++) {
        int mn = INT_MAX;
        for (int j = 1; j <= K; j++) {
            mn = min(mn, ans[j][i % (1 << j)]);
        }
        printf("%d ", mn);
    }
    return 0;
}
// assume x < y
// (x ^ i) < (y ^ i) <=> i mod (2^(hb + 1)) < 2^hb