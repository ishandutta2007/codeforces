#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, a[maxn][5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i ^ j) {
            for (int k = j + 1; k <= n; k++) if (i ^ k) {
                int s = 0;
                for (int l = 0; l < 5; l++) {
                    s += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
                }
                if (s > 1e-9) goto nxt;
            }
        }
        ans.push_back(i); nxt:;
    }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}