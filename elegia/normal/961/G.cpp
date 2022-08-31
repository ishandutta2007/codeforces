#include <cstdio>

using namespace std;

typedef long long ll;

const int N = 200010, P = static_cast<const int>(1e9 + 7);

int fact[N], rev[N], rf[N];

int comb(int n, int k);
int stirling(int n, int k);
int qpow(int x, int k);

int main() {
    int n, k, sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
        if (sum >= P)
            sum -= P;
    }
    fact[0] = rf[0] = fact[1] = rf[1] = 1;
    rev[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fact[i] = fact[i - 1] * (ll)i % P;
        rev[i] = (P - (P / i) * (ll)rev[P % i] % P) % P;
        rf[i] = rf[i - 1] * (ll)rev[i] % P;
    }
    printf("%lld\n", sum * (stirling(n, k) + (ll)(n - 1) * stirling(n - 1, k) % P) % P);
    return 0;
}

int qpow(int x, int k) {
    int ret = 1;
    while (k) {
        if (k & 1)
            ret = (ll)ret * x % P;
        x = (ll)x * x % P;
        k >>= 1;
    }
    return ret;
}

int stirling(int n, int k) {
    int ret = 0;
    for (int i = 0; i <= k; ++i) {
        if ((k + i) & 1)
            ret = (ret - comb(k, i) * (ll)qpow(i, n) % P + P) % P;
        else
            ret = (ret + comb(k, i) * (ll)qpow(i, n)) % P;
    }
    return ret * (ll)rf[k] % P;
}

int comb(int n, int k) {
    return fact[n] * (ll)rf[k] % P * rf[n - k] % P;
}