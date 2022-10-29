#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
int n, m, k, t;
int a[200001];
struct node{
    int r, d;
};
vector<node>g[200001];
int f[200001];
bool check(int x) {
    memset(f, 0, sizeof(f));
    int T = t;
    for (int i = 1; i <= n; i ++) {
        int mx = i - 1;
        for (auto u:g[i])
            if (u.d > a[x]) mx = max(mx, u.r);
        f[i] ++;
        f[mx + 1] --;
    }
    for (int i = 1; i <= n; i ++)
        if ((f[i] += f[i - 1]) > 0) T -= 2;
    return T >= 0;
}
int main() {
    scanf("%d %d %d %d", &m, &n, &k, &t);
    t -= n + 1;
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k; i ++) {
        node tmp;
        int x;
        scanf("%d %d %d", &x, &tmp.r, &tmp.d);
        g[x].push_back(tmp);
    }
    sort(a + 1, a + m  + 1);
    int l = 1, r = m, s = m + 1, mid;
    while (l <= r) {
        if (check(mid = (l + r) / 2)) r = mid - 1, s = min(s, mid);
        else
            l = mid + 1;
    }
    printf("%d\n", m - s + 1);
    return 0;
}