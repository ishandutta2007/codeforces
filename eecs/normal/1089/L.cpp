#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, a[maxn], b[maxn];
vector<int> cand, V[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), V[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= K; i++) {
        if (V[i].empty()) {
            cnt++;
        } else {
            sort(V[i].begin(), V[i].end(), [&](int x, int y) { return b[x] > b[y]; });
            for (int j = 1; j < V[i].size(); j++) cand.push_back(b[V[i][j]]);
        }
    }
    sort(cand.begin(), cand.end());
    long long ans = 0;
    for (int i = 0; i < cnt; i++) ans += cand[i];
    printf("%lld\n", ans);
    return 0;
}