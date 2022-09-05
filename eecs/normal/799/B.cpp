#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, p[maxn], a[maxn], b[maxn];
multiset<int> S[3][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        S[--a[i]][--b[i]].insert(p[i]);
    }
    scanf("%d", &m);
    while (m--) {
        int c, mn = INT_MAX;
        scanf("%d", &c), c--;
        for (int i : {0, 1, 2}) for (int j : {0, 1, 2}) if (i == c || j == c) {
            if (!S[i][j].empty()) mn = min(mn, *S[i][j].begin());
        }
        printf("%d ", mn == INT_MAX ? -1 : mn);
        for (int i : {0, 1, 2}) for (int j : {0, 1, 2})  if (i == c || j == c) {
            if (!S[i][j].empty() && mn == *S[i][j].begin()) {
                S[i][j].erase(S[i][j].begin());
            }
        }
    }
    return 0;
}