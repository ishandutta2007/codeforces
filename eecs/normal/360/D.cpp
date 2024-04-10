#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, P, ans, a[maxn], b[maxn], c[maxn], f[maxn];
bool mark[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int g = P - 1;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]), g = __gcd(g, b[i]);
    }
    auto fact = [&](int x) {
        vector<int> V;
        for (int i = 2; i * i <= x; i++) {
            while (!(x % i)) V.push_back(i), x /= i;
        }
        if (x > 1) V.push_back(x);
        return V;
    };
    auto V = fact(P - 1);
    for (int i = 1; i <= n; i++) {
        int x = qp(a[i], g);
        c[i] = 1;
        for (int p : V) {
            if (qp(x, (P - 1) / c[i] / p) == 1) c[i] *= p;
        }
    }
    vector<int> cand;
    for (int i = 1; i * i <= P - 1; i++) if (!((P - 1) % i)) {
        cand.push_back(i);
        if (i * i < P - 1) cand.push_back((P - 1) / i);
    }
    sort(cand.begin(), cand.end());
    for (int i = 0; i < cand.size(); i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!(cand[i] % c[j])) cnt++;
        }
        f[i] = cnt > 0;
        for (int j = 0; j < i; j++) if (!(cand[i] % cand[j])) {
            f[i] = (f[i] - f[j] + P) % P;
        }
        ans = (ans + 1LL * (P - 1) / cand[i] * f[i]) % P;
    }
    printf("%d\n", ans);
    return 0;
}