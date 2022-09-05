#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, a[maxn];
long long ans = LLONG_MAX, s0, sum[maxn];
vector<int> V[maxn];

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i > 1 && a[i - 1] ^ a[i]) {
            s0 += abs(a[i - 1] - a[i]);
            sum[a[i - 1]] -= abs(a[i - 1] - a[i]);
            sum[a[i]] -= abs(a[i - 1] - a[i]);
            V[a[i - 1]].push_back(a[i]);
            V[a[i]].push_back(a[i - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        long long s = 0;
        sort(V[i].begin(), V[i].end());
        int t = V[i][V[i].size() / 2];
        for (int x : V[i]) s += abs(x - t);
        ans = min(ans, s + sum[i]);
    }
    printf("%lld\n", ans + s0);
    return 0;
}