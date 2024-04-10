#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, K, mx[maxn], from[maxn];
bool mark[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    vector<int> len;
    function<void(int, int)> dfs1 = [&](int u, int fa) {
        mx[u] = 1, from[u] = u;
        for (int v : G[u]) if (v ^ fa) {
            dfs1(v, u);
            if (mx[v] + 1 > mx[u]) mx[u] = mx[v] + 1, from[u] = from[v];
        }
    };
    function<void(int, int)> dfs2 = [&](int u, int fa) {
        if (!mark[from[u]]) len.push_back(mx[u]), mark[from[u]] = 1;
        for (int v : G[u]) if (v ^ fa) dfs2(v, u);
    };
    dfs1(1, 0), dfs2(1, 0);
    sort(len.begin(), len.end(), greater<int>());
    long long ans = LLONG_MIN;
    if (len.size() > K) {
        int num = accumulate(len.begin(), len.begin() + K, 0);
        ans = LLONG_MAX;
        for (int b = 0; b <= n - num; b++) {
            ans = min(ans, 1LL * (num - K + n - num - b) * (K - b));
        }
    } else {
        for (int i = len.size(); i <= K; i++) {
            ans = max(ans, 1LL * (n - i) * i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}