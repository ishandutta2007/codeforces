#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 55, P = 998244353;
int n, ans, finv[maxn], b[maxn];
ll a[maxn];
pair<ll, ll> f[maxn][maxn], g[maxn * maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

pair<ll, ll> operator + (pair<ll, ll> a, pair<ll, ll> b) {
    if (a.first ^ b.first) return max(a, b);
    return {a.first, (a.second + b.second) % P};
}

pair<ll, ll> operator * (pair<ll, ll> a, pair<ll, ll> b) {
    return {a.first + b.first, a.second * b.second % P};
}

int main() {
    scanf("%d %*d", &n);
    for (int i = finv[0] = 1; i <= n; i++) {
        scanf("%lld", &a[i]), a[i] += a[i - 1];
        finv[i] = 1LL * finv[i - 1] * qp(i, P - 2) % P;
    }
    vector<ll> V(a, a + n + 1);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    for (int i = 0; i <= n; i++) {
        b[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
    }
    auto binom = [&](ll x, int y) {
        int res = finv[y];
        for (int i = 1; i <= y; i++) res = (x - i + 1) % P * res % P;
        return res;
    };
    for (int i = 0; i + 1 < V.size(); i++) {
        for (int j = 0; j <= n; j++) {
            ll res = 0, m = V[i + 1] - V[i];
            for (int k = 0; k <= j; k++) {
                res = (res + 1LL * binom(j, k) * binom(m + k - 1, j)) % P;
            }
            f[i][j] = {m, res};
        }
    }
    vector<ll> dist = {b[0]};
    for (int i = 1; i <= n; i++) {
        int l = b[i - 1], r = b[i];
        while (l < r) dist.push_back(++l);
        while (l > r) dist.push_back(--l);
    }
    fill(g, g + dist.size(), pair<ll, ll>{1, 1});
    for (int i = 0; i < dist.size(); i++) {
        for (int j = i - 1, k = 0; ~j; j--) {
            if (dist[j] >= dist[i] && dist[j + 1] < dist[i]) k++;
            if (dist[i] == dist[j] + 1) g[i] = g[i] + g[j] * f[dist[j]][k];
        }
    }
    pair<ll, ll> ans{0, 0};
    for (int i = 0; i < dist.size(); i++) {
        ans = ans + g[i];
    }
    if (ans.first == 1) ans.second = (V.back() - V[0] + 1) % P;
    printf("%lld %lld\n", ans.first, ans.second);
    return 0;
}