#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int P = 998244353;
int n, m, K, ans[36], A[20][1 << 17], B[1 << 17];
ll a[35];

void red(int &x) {
    x += x >> 31 & P;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll x; scanf("%lld", &x);
        for (int j = m - 1; ~j; j--) if (x >> j & 1) {
            if (!a[j]) { a[j] = x, K++; break; }
            x ^= a[j];
        }
    }
    int mid = m / 2;
    function<void(int, ll)> dfs1 = [&](int i, ll x) {
        if (i < mid) {
            ll y = x & ((1 << mid) - 1);
            A[__builtin_popcountll(x ^ y)][y]++; return;
        }
        dfs1(i - 1, x);
        if (a[i]) dfs1(i - 1, x ^ a[i]);
    };
    dfs1(m - 1, 0);
    function<void(int, int)> dfs2 = [&](int i, int x) {
        if (i == mid) { B[x]++; return; }
        dfs2(i + 1, x);
        if (a[i]) dfs2(i + 1, x ^ a[i]);
    };
    dfs2(0, 0);
    auto FWT = [&](int A[1 << 17], int type) {
        for (int i = 1; i < 1 << mid; i <<= 1) {
            for (int j = 0; j < 1 << mid; j += i << 1) {
                for (int k = 0; k < i; k++) {
                    assert(i + j + k < (1 << mid));
                    int p = A[j + k], q = A[i + j + k];
                    red(A[j + k] = p + q - P), red(A[i + j + k] = p - q);
                }
            }
        }
        if (type == -1) {
            int inv = qp(1 << mid, P - 2);
            for (int i = 0; i < 1 << mid; i++) A[i] = 1LL * A[i] * inv % P;
        }
    };
    FWT(B, 1);
    for (int cnt = 0; cnt <= m - mid + 1; cnt++) {
        FWT(A[cnt], 1);
        for (int i = 0; i < 1 << mid; i++) {
            A[cnt][i] = 1LL * A[cnt][i] * B[i] % P;
        }
        FWT(A[cnt], -1);
        for (int i = 0; i < 1 << mid; i++) {
            red(ans[cnt + __builtin_popcount(i)] += A[cnt][i] - P);
        }
    }
    int pw = qp(2, n - K);
    for (int i = 0; i <= m; i++) {
        printf("%lld ", 1LL * pw * ans[i] % P);
    }
    return 0;
}