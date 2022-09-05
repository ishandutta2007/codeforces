#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, c, d, pre[maxn];
vector<array<int, 2>> C, D;

int main() {
    scanf("%d %d %d", &n, &c, &d);
    for (int i = 1, b, p; i <= n; i++) {
        char type[2];
        scanf("%d %d %s", &b, &p, type);
        if (type[0] == 'C') C.push_back({p, b});
        else D.push_back({p, b});
    }
    sort(C.begin(), C.end()), sort(D.begin(), D.end());
    int mx1 = -1e9, mx2 = -1e9;
    for (auto &p : C) {
        if (p[0] <= c) mx1 = max(mx1, p[1]);
    }
    for (auto &p : D) {
        if (p[0] <= d) mx2 = max(mx2, p[1]);
    }
    int ans = max(0, mx1 + mx2);
    for (int i = 0; i < C.size(); i++) {
        pre[i] = max(i ? pre[i - 1] : 0, C[i][1]);
    }
    for (int i = 1; i < C.size(); i++) {
        int j = lower_bound(C.begin(), C.end(), array<int, 2>{c - C[i][0] + 1, 0}) - C.begin() - 1;
        if (j >= 0) ans = max(ans, C[i][1] + pre[min(j, i - 1)]);
    }
    for (int i = 0; i < D.size(); i++) {
        pre[i] = max(i ? pre[i - 1] : 0, D[i][1]);
    }
    for (int i = 1; i < D.size(); i++) {
        int j = lower_bound(D.begin(), D.end(), array<int, 2>{d - D[i][0] + 1, 0}) - D.begin() - 1;
        if (j >= 0) ans = max(ans, D[i][1] + pre[min(j, i - 1)]);
    }
    printf("%d\n", ans);
    return 0;
}