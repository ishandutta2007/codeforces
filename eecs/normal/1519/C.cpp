#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, u[maxn], s[maxn];
vector<int> V[maxn];
long long pre[maxn], ans[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            V[i].clear(), ans[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &u[i]), V[u[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
        }
        for (int i = 1; i <= n; i++) {
            sort(V[i].begin(), V[i].end(), [&](int x, int y) { return s[x] > s[y]; });
            for (int j = 0; j < V[i].size(); j++) {
                pre[j] = (j ? pre[j - 1] : 0) + s[V[i][j]];
            }
            for (int j = 1; j <= V[i].size(); j++) {
                ans[j] += pre[V[i].size() / j * j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%lld%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}