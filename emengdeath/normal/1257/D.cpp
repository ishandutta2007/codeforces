#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <unordered_set>
#include <set>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int T;
int n, m;
int a[N];
pair<int, int> b[N];
int d[N];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        int mx = 0;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), mx = max(mx, a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++)
            scanf("%d %d", &b[i].first, &b[i].second);
        sort(b + 1, b + m + 1);
        for (int i = 1; i <= m; i ++)d[i] = b[i].first;
        for (int i = m - 1; i >= 1; i --) {
            b[i].second = max(b[i + 1]. second, b[i].second);
        }
        if (b[m].first < mx) {
            printf("-1\n");
            continue;
        }
        int ans = 0;
        int l = 1;
        while (l <= n) {
            int r = l;
            ++ans;
            int v = a[l];
            while (1) {
                if (r == n) break;
                v = max(v, a[r + 1]);
                int x = lower_bound(d + 1, d + m + 1, v) - d;
                if (b[x].second < r + 1 - l + 1) break;
                r ++;
            }
            l = r + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}