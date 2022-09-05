#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

char _buf[100000], *_op(_buf), *_ed(_buf);
#define gc (_op == _ed && (_ed = (_op = _buf) + fread(_buf, 1, 100000, stdin), _op == _ed) ? EOF : *_op++)

int read() {
    int x = 0; char ch = gc;
    while (ch < '0' || ch > '9') ch = gc;
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc;
    return x;
}

const int maxn = 100010, P = 998244353;
int n, m, ans, a[maxn], p[maxn], pw[maxn];
bool mark[2 * maxn], mark2[2 * maxn];
unsigned long long s;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        p[i] = read(), mark[p[i]] = mark2[p[i] + n] = 1;
    }
    for (int i = pw[0] = 1; i <= m; i++) {
        pw[i] = 2 * pw[i - 1] % P;
    }
    for (int i = 1, j; i <= n; i++) {
        int rem = m;
        s = 0;
        for (int j = 0; j < 1; j++) {
            if (i - j > 0 && mark[i - j]) rem--;
            if (j && mark[i + j]) rem--;
            s += pw[rem];
        }
        auto it1 = mark + i, it2 = mark2 + i + n;
        if (i - 1 <= n - i) {
            for (j = 1; j < i; j++) {
                s += pw[rem -= *++it1 + *--it2];
            }
            for (j = i; j <= n - i; j++) {
                s += pw[rem -= *++it1];
            }
        } else {
            for (j = 1; j <= n - i; j++) {
                s += pw[rem -= *++it1 + *--it2];
            }
            for (j = n - i + 1; j <= i - 1; j++) {
                s += pw[rem -= *--it2];
            }
        }
        (ans += s % P * a[i] % P) %= P;
        ans = (ans - 1LL * a[i] * max(n - i + 1, i) % P + P) % P;
    }
    ans = 1LL * ans * qp(pw[m] + P - 1, P - 2) % P;
    printf("%d\n", ans);
    return 0;
}