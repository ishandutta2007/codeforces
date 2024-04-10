#include <bits/stdc++.h>
using namespace std;
int n, a[1010];
int id[1010];
inline int cmp(int a, int b) {
    return ::a[a] == ::a[b] ? a > b : ::a[a] > ::a[b];
}
vector < pair < int, int > > ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = i + 1; j <= n; j++) if (a[j] < a[i]) id[++cnt] = j;
        sort(id + 1, id + 1 + cnt, cmp);
        for (int j = 1; j <= cnt; j++) ans.push_back(make_pair(i, id[j]));
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d %d\n", ans[i].first, ans[i].second);
}