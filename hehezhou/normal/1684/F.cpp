#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200010], b[200010];
int L[200010], R[200010];
vector <int> pos[200010];
vector <int> mdf[200010];
void rmain() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    for (int i = 1; i <= n; i++) R[i] = i, L[i] = i, mdf[i].clear(), pos[i].clear();
    for (int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        L[r] = min(L[r], l);
        R[l] = max(R[l], r);
    }
    for (int i = n; i > 1; i--) L[i - 1] = min(L[i - 1], L[i]);
    for (int i = 1; i < n; i++) R[i + 1] = max(R[i + 1], R[i]);
    for (int i = 1; i <= n; i++) pos[a[i]].push_back(i);
    multiset <int> ms;
    int stpos = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = 0;
        for (int j = 0; j < pos[i].size(); j++) {
            int cur = pos[i][j];
            while (pos[i][l] < L[cur]) l++;
            while (r + 1 < pos[i].size() && pos[i][r + 1] <= R[cur]) r++;
            if (j != 0 && j != pos[i].size() - 1 && R[pos[i][j - 1]] >= pos[i][j + 1]) {
                stpos = max(stpos, cur);
                ms.insert(cur);
            }
            if (l != j) {
                stpos = max(stpos, pos[i][l]);
                ms.insert(pos[i][l]);
                mdf[cur].push_back(pos[i][l]);
            }
            if (r != j) {
                stpos = max(stpos, cur);
                ms.insert(cur);
                mdf[pos[i][r]].push_back(cur);
            }
        }
    }
    if (stpos == 0) return puts("0"), void();
    for (int i = 1; i < stpos; i++) for (auto j : mdf[i]) ms.erase(ms.lower_bound(j)), ms.insert(i);
    int ans = n;
    for (int i = stpos; i <= n; i++) {
        for (auto j : mdf[i]) ms.erase(ms.lower_bound(j)), ms.insert(i);
        ans = min(ans, i - *ms.begin() + 1);
    }
    printf("%d\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}