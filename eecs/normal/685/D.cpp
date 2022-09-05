#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, x[maxn], y[maxn], q[maxn], cnt[maxn * 300], pre[maxn * 300];
long long ans[maxn];
vector<tuple<int, int, int, int>> V;

int main() {
    scanf("%d %d", &n, &K);
    vector<int> p;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        p.push_back(y[i]);
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for (int i = 0, j = 0; i < p.size(); i++) {
        q[i] = j;
        if (i < p.size() - 1) j += min(K, p[i + 1] - p[i]);
    }
    for (int i = 1; i <= n; i++) {
        int t = q[lower_bound(p.begin(), p.end(), y[i]) - p.begin()];
        V.emplace_back(x[i], t, t + K - 1, 1);
        V.emplace_back(x[i] + K, t, t + K - 1, -1);
    }
    sort(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++) {
        for (int j = get<1>(V[i]); j <= get<2>(V[i]); j++) {
            if (cnt[j]) ans[cnt[j]] += get<0>(V[i]) - pre[j];
            cnt[j] += get<3>(V[i]), pre[j] = get<0>(V[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
    return 0;
}