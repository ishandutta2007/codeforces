#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &m);
    set<pair<int, int>> S;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a[i], &b[i]), a[i]--, b[i]--;
        if (a[i] > b[i]) swap(a[i], b[i]);
        S.emplace(a[i], b[i]);
    }
    for (int k = 1; k < n; k++) if (!(n % k)) {
        bool flag = 1;
        for (int i = 1; i <= m; i++) {
            int x = (a[i] + k) % n, y = (b[i] + k) % n;
            if (x > y) swap(x, y);
            if (!S.count({x, y})) { flag = 0; break; }
        }
        if (flag) puts("Yes"), exit(0);
    }
    puts("No");
    return 0;
}