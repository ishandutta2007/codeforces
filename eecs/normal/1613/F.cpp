#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 262144, P = 998244353;
int n, d[maxn], fact[maxn];
int lim, L, r[maxn], w[maxn];
priority_queue<pair<int, poly>, vector<pair<int, poly>>, greater<pair<int, poly>>> Q;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}
 
void init(int n) {
    for (lim = 1, L = 0; lim < n; lim <<= 1) L++;
    for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
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
 
poly operator * (poly A, poly B) {
    int len = A.size() + B.size() - 1;
    init(len), A.resize(lim), B.resize(lim);
    DFT(A.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A.data(), -1), A.resize(len); return A;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        d[u]++, d[v]++;
    }
    for (int i = fact[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    for (int i = 1; i <= n; i++) {
        poly p = {1};
        p.push_back(d[i] - (i > 1));
        Q.emplace(p.size(), p);
    }
    while (Q.size() > 1) {
        auto p = Q.top().second; Q.pop();
        auto q = Q.top().second; Q.pop();
        p = p * q, Q.emplace(p.size(), p);
    }
    auto p = Q.top().second;
    int ans = 0;
    for (int i = 0; i < p.size(); i++) {
        ans = (ans + 1LL * p[i] * fact[n - i] % P * (i & 1 ? P - 1 : 1)) % P;
    }
    printf("%d\n", ans);
    return 0;
}