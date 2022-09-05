#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 1048576, P = 998244353;
int T, n, cnt[maxn];
int lim, l, r[maxn], w[maxn], A[maxn], B[maxn];
char s[maxn];
vector<int> ans;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void init() {
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    w[lim >> 1] = 1;
    int t = qp(3, (P - 1) / lim);
    for (int i = (lim >> 1) + 1; i < lim; i++) w[i] = 1LL * w[i - 1] * t % P;
    for (int i = (lim >> 1) - 1; i > 0; i--) w[i] = w[i << 1];
}

void DFT(int *a, int type) {
    static ull c[maxn];
    copy(a, a + lim, c);
    for (int i = 0; i < lim; i++) if (i < r[i]) swap(c[i], c[r[i]]);
    for (int i = 1; i < lim; i <<= 1) {
        for (int j = 0; j < lim; j += i << 1) {
            for (int k = 0; k < i; k++) {
                ull t = c[i + j + k] * w[i + k] % P;
                c[i + j + k] = c[j + k] + P - t, c[j + k] += t;
            }
        }
    }
    if (!~type) {
        reverse(c + 1, c + lim);
        for (int i = 0, t = qp(lim, P - 2); i < lim; i++) c[i] = c[i] % P * t % P;
    }
    for (int i = 0; i < lim; i++) a[i] = c[i] % P;
}

void mul() {
    DFT(A, 1), DFT(B, 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A, -1);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1), ans.clear();
        fill(cnt, cnt + n + 1, 0);
        if (n <= 100) {
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (s[j - i] == 'V' && s[j] == 'K') cnt[i]++;
                    if (s[j - i] == 'K' && s[j] == 'V') cnt[i]++;
                }
            }
        } else {
            for (lim = 1, l = 0; lim <= n + n; lim <<= 1) l++;
            fill(A, A + lim, 0), fill(B, B + lim, 0), init();
            for (int i = 1; i <= n; i++) {
                if (s[i] == 'V') A[n - i + 1]++;
                if (s[i] == 'K') B[i]++;
            }
            mul();
            for (int i = 1; i <= n; i++) {
                cnt[i] += A[n - i + 1];
            }
            fill(A, A + lim, 0), fill(B, B + lim, 0);
            for (int i = 1; i <= n; i++) {
                if (s[i] == 'K') A[n - i + 1]++;
                if (s[i] == 'V') B[i]++;
            }
            mul();
            for (int i = 1; i <= n; i++) {
                cnt[i] += A[n - i + 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            bool flag = 1;
            for (int j = i; j <= n; j += i) {
                if (cnt[j]) { flag = 0; break; }
            }
            if (flag) ans.push_back(i);
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}