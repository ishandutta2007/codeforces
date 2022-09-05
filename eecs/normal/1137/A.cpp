#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, a[maxn][maxn];
vector<int> tmp, r[maxn], c[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]), r[i].push_back(a[i][j]), c[j].push_back(a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(r[i].begin(), r[i].end()), tmp.clear();
        int lst = INT_MIN;
        for (int j : r[i]) if (j ^ lst) tmp.push_back(j), lst = j;
        r[i] = tmp;
    }
    for (int i = 1; i <= m; i++) {
        sort(c[i].begin(), c[i].end()), tmp.clear();
        int lst = INT_MIN;
        for (int j : c[i]) if (j ^ lst) tmp.push_back(j), lst = j;
        c[i] = tmp;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int c1 = max(lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin(), lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin());
            int c2 = max(r[i].end() - upper_bound(r[i].begin(), r[i].end(), a[i][j]), c[j].end() - upper_bound(c[j].begin(), c[j].end(), a[i][j]));
            printf("%d ", c1 + c2 + 1);
        }
        printf("\n");
    }
    return 0;
}