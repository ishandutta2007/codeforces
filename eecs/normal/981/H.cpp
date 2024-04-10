#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
typedef unsigned long long ull;
const int maxn = 131072, P = 998244353;
int n, K, ans, fact[maxn], sz[maxn], coef[maxn];
int lim, L, r[maxn], w[maxn], sum[maxn];
vector<int> G[maxn];
map<pair<int, int>, int> f;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void red(int &x) {
    x += x >> 31 & P;
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

poly operator + (poly A, poly B) {
    if (A.size() < B.size()) swap(A, B);
    for (int i = 0; i < B.size(); i++) red(A[i] += B[i] - P);
    return A;
}

poly operator * (poly A, poly B) {
    int len = A.size() + B.size() - 1;
    if (min(A.size(), B.size()) < 30) {
        poly C(len);
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                C[i + j] = (C[i + j] + 1LL * A[i] * B[j]) % P;
            }
        }
        return C;
    }
    init(len), A.resize(lim), B.resize(lim);
    DFT(A.data(), 1), DFT(B.data(), 1);
    for (int i = 0; i < lim; i++) A[i] = 1LL * A[i] * B[i] % P;
    DFT(A.data(), -1), A.resize(len);
    return A;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    if (n == 1) puts("0"), exit(0);
    if (K == 1) printf("%lld\n", 1LL * n * (n - 1) / 2 % P), exit(0);
    for (int i = fact[0] = 1; i <= K; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
    }
    for (int i = 0; i <= K; i++) {
        coef[i] = 1LL * fact[K] * qp(fact[K - i], P - 2) % P;
    }
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        sz[u] = 1;
        vector<int> A;
        for (int v : G[u]) if (v ^ fa) {
            dfs1(v, u), sz[u] += sz[v];
            A.push_back(sz[v]);
        }
        if (fa) A.push_back(n - sz[u]);
        function<poly(int, int)> solve = [&](int l, int r) {
            if (l == r) return poly{1, A[l]};
            int mid = (l + r) / 2;
            return solve(l, mid) * solve(mid + 1, r);
        };
        poly B = solve(0, A.size() - 1);
        map<int, int> mp;
        auto calc = [&](int ban) {
            if (mp.count(ban)) return mp[ban];
            poly C = B;
            for (int i = 0; i + 1 < C.size(); i++) {
                C[i + 1] = (C[i + 1] - 1LL * C[i] * ban % P + P) % P;
            }
            int ans = 0;
            for (int i = 0; i < C.size(); i++) {
                ans = (ans + 1LL * C[i] * coef[i]) % P;
            }
            return mp[ban] = ans;
        };
        for (int v : G[u]) if (v ^ fa) {
            f[{u, v}] = calc(sz[v]);
        }
        if (fa) f[{u, fa}] = calc(n - sz[u]);
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        sum[u] = fa ? f[{u, fa}] : 0;
        for (int v : G[u]) if (v ^ fa) {
            dfs2(v, u), red(sum[u] += sum[v] - P);
        }
    };
    function<void(int, int)> dfs3 = [&](int u, int fa) {
        for (int v : G[u]) {
            ans = (ans + 1LL * f[{u, v}] * sum[v]) % P;
        }
        for (int v : G[u]) if (v ^ fa) {
            red(sum[u] -= sum[v]);
            red(sum[u] += f[{u, v}] - P), red(sum[v] -= f[{v, u}]);
            red(sum[v] += sum[u] - P);
            dfs3(v, u);
            red(sum[v] -= sum[u]);
            red(sum[u] -= f[{u, v}]), red(sum[v] += f[{v, u}] - P);
            red(sum[u] += sum[v] - P);
        }
    };
    dfs1(1, 0), dfs2(1, 0), dfs3(1, 0);
    printf("%lld\n", 1LL * (P + 1) / 2 * ans % P);
    return 0;
}