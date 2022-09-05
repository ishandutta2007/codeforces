#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int n, m, p[maxn], c[maxn];
long long ans = LLONG_MAX;
vector<int> V[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i], &c[i]);
        V[p[i]].emplace_back(c[i]);
    }
    for (int i = 1; i <= m; i++) {
        sort(V[i].begin(), V[i].end());
    }
    for (int i = V[1].size(); i <= n; i++) {
        long long sum = 0;
        int cur = V[1].size();
        vector<int> T;
        for (int j = 2; j <= m; j++) if (!V[j].empty()) {
            for (int k = 0; k <= (int)V[j].size() - i; k++) {
                sum += V[j][k], cur++;
            }
            for (int k = max(0, (int)V[j].size() - i + 1); k < V[j].size(); k++) {
                T.push_back(V[j][k]);
            }
        }
        if (cur > i) continue;
        sort(T.begin(), T.end());
        int p = 0;
        while (cur < i) cur++, sum += T[p++];
        ans = min(ans, sum);
    }
    printf("%lld\n", ans);
    return 0;
}