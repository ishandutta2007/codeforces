#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 35, P = 1000000007;
ll n;
unsigned long long pw[100];
int K;

struct mat {
    int a[maxn][maxn];
    mat() {
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) a[i][j] = 0;
        }
    }

    mat operator * (const mat &o) const {
        mat ans;
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) if (a[i][j]) {
                for (int k = 0; k <= K; k++) {
                    ans.a[i][k] = (ans.a[i][k] + 1LL * a[i][j] * o.a[j][k]) % P;
                }
            }
        }
        return ans;
    }
} f[100][maxn];

int main() {
    scanf("%lld %d", &n, &K);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j <= K; j++) if (i ^ j) f[0][i].a[j][j] = 1;
        f[0][i].a[K][i]++;
        f[0][i].a[i][K] = P - 1, f[0][i].a[K][K]++;
    }
    int num = 0;
    ll m = n;
    while (m) num++, m /= K;
    for (int i = pw[0] = 1; i <= num; i++) {
        pw[i] = pw[i - 1] * K;
        f[i][0] = f[i - 1][0];
        for (int j = 1; j < K; j++) {
            f[i][0] = f[i][0] * f[i - 1][j];
        }
        for (int j = 1; j < K; j++) {
            for (int a = 0; a <= K; a++) {
                for (int b = 0; b <= K; b++) {
                    int c = a < K ? (a + j) % K : a;
                    int d = b < K ? (b + j) % K : b;
                    f[i][j].a[c][d] = f[i][0].a[a][b];
                }
            }
        }
    }
    mat A; A.a[0][K] = 1;
    int cur = 0;
    for (int i = num; ~i; i--) while (n >= pw[i]) {
        A = A * f[i][++cur %= K], n -= pw[i];
    }
    printf("%d\n", A.a[0][K]);
    return 0;
}