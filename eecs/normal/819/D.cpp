#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, ans[maxn];
long long s, a[maxn];
map<int, vector<int>> mp;

void exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) { x = 1, y = 0; return; }
    exgcd(b, a % b, y, x), y -= a / b * x;
}

long long inv(long long a, long long P) {
    long long x, y; exgcd(a, P, x, y);
    return (x + P) % P;
}

int main() {
    scanf("%d %d", &T, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), s += a[i];
        if (i > 1) a[i] = a[i - 1] + a[i];
        else a[i] = 0;
    }
    long long g = __gcd((long long)T, s);
    for (int i = 1; i <= n; i++) {
        mp[a[i] % g].push_back(i);
    }
    for (auto &p : mp) {
        vector<int> V = p.second;
        for (int i : V) {
            a[i] = 1LL * (a[i] - p.first) / g % (T / g) * inv(s / g % (T / g), T / g) % (T / g);
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return make_pair(a[x], -x) < make_pair(a[y], -y); });
        int rem = T / g;
        for (int i = 0; i + 1 < V.size(); i++) {
            int tmp = a[V[i + 1]] - a[V[i]];
            ans[V[i]] += tmp, rem -= tmp;
        }
        ans[V.back()] += rem;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}