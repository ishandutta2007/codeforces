#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 3e5 + 1;
vector<int>a[N];
int n;
int ans;
int getl(int x, vector<int>&g) {
    if (g.size() == 0||g[0] >=x) return -1;
    return g[lower_bound(g.begin(), g.end(), x) - g.begin() - 1];
}
int getr(int x, vector<int>&g) {
    if (g.size() == 0 || g[g.size() - 1] <= x) return n + 1;
    return g[upper_bound(g.begin(), g.end(), x) - g.begin()];
}
void work(int l, int r, int x, int ll, int rr, int y) {
    if (rr > r || ll < l) return;
    if (rr - ll  + 1 == y + 1) {
        ans ++;
    }
    ++y;
    int lv = getl(x, a[y]);
    int rv = getr(x, a[y]);
    if (lv > 0)
    work(l, min(r, rv - 1), x, min(ll, lv), rr, y);
    if (rv <= n)
    work(max(l, lv + 1), r, x, ll, max(rr, rv), y);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d", &x);
        a[x-1].push_back(i);
    }
    for (auto u:a[0])
        work(getl(u, a[0]) + 1, getr(u, a[0]) - 1, u, u, u, 0);
    printf("%d\n", ans);
    return 0;
}