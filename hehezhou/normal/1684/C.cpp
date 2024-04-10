#include <bits/stdc++.h>
using namespace std;
vector < vector <int> > a;
long long sum[200010];
int id[200010];
void rmain() {
    int n, m;
    scanf("%d%d", &n, &m);
    a.resize(n + 1);
    for (int i = 1; i <= m; i++) sum[i] = 0, id[i] = i;
    for (int i = 1; i <= n; i++) {
        a[i].resize(m + 1);
        for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]), sum[j] += a[i][j];
    }
    sort(id + 1, id + 1 + m, [](int x, int y) {
        return sum[x] == sum[y] ? x < y : sum[x] < sum[y];
    });
    int pos1 = -1, pos2 = -1;
    for (int l = 1, r; l <= m; l = r + 1) {
        for (r = l; r < m && sum[id[r + 1]] == sum[id[l]]; r++);
        for (int i = l; i <= r; i++) if (id[i] < l || id[i] > r) {
            if (pos1 == -1) pos1 = id[i];
            else if (pos2 == -1) pos2 = id[i];
            else return puts("-1"), void();
        }
    }
    if (pos1 == -1) pos1 = 1;
    if (pos2 == -1) pos2 = pos1;
    for (int i = 1; i <= n; i++) swap(a[i][pos1], a[i][pos2]);
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++) if (a[i][j] < a[i][j - 1]) return puts("-1"), void();
    printf("%d %d\n", pos1, pos2);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}