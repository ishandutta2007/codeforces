#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010;
int n, v[maxn], d[maxn], p[maxn];
bool vis[maxn];
vector<int> ans;

void run(int i) {
    if (vis[i]) return;
    vis[i] = 1;
    for (int j = i + 1; j <= n; j++) if (p[j] >= 0) {
        p[j] -= d[i];
        if (p[j] < 0) run(j);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &v[i], &d[i], &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (p[i] >= 0) {
            ans.push_back(i);
            int k = v[i];
            for (int j = i + 1, k = v[i]; j <= n; j++) {
                if (p[j] >= 0) p[j] -= max(0, k--);
            }
            for (int j = i + 1; j <= n; j++) {
                if (p[j] < 0) run(j);
            }
        }
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}