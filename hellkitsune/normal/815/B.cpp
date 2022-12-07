#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int sgn = -1;
int n = 25;
int a[200005], b[200005];
int f[200005], rf[200005];

int binPow(LL x, int p) {
    LL ret = 1;
    while (p) {
        if (p & 1) ret = ret * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)ret;
}

int c(int n, int k) {
    return (LL)f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

void nor(int &x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
}

int main() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < 200005; ++i) {
        f[i] = (LL)f[i - 1] * i % MOD;
        rf[i] = binPow(f[i], MOD - 2);
    }
    scanf("%d", &n);
    if (n % 4 == 2 || n % 4 == 3) {
        sgn = 1;
    } else {
        sgn = -1;
    }
    int m = n;
    if (n < 4) {
        m = 1;
        a[0] = 1;
    } else {
        m = n;
        while (m % 4 != 2) {
            --m;
        }
        int coef = (m - 2) / 2;
        for (int i = 0; i < m; i += 2) {
            a[i] = c(coef, i / 2);
            if (sgn == 1) {
                a[i + 1] = a[i];
            } else {
                a[i + 1] = (MOD - a[i]) % MOD;
            }
        }
        sgn *= -1;
    }
    while (m < n) {
        int i = m + 1;
        memset(b, 0, sizeof b);
        for (int j = i - 2; j >= 0; --j) {
            b[j] += a[j];
            nor(b[j]);
            b[j + 1] += a[j] * sgn;
            nor(b[j + 1]);
            sgn *= -1;
        }
        forn(j, i) {
            a[j] = b[j];
        }
        m = i;
    }
    int sum = 0;
    forn(i, n) {
        scanf("%d", &b[i]);
        sum = (sum + (LL)a[i] * b[i]) % MOD;
    }
    cout << sum << endl;
    return 0;
}