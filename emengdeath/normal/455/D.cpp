#include <algorithm>
#include <cstdio>
#include <deque>
#include <cmath>
using namespace std;
const int N = 1e5 + 10;
int S;
int f[350][N];
int a[N];
deque<int> g[350];
int n;
int id(int x) {
    return (x - 1) / S;
}
void myrotate(int id, int l, int r) {
    int v = g[id][l];
    for (int i = l + 1; i <= r; i ++)
        g[id][i - 1] = g[id][i];
    g[id][r] = v;
}
int main() {
    scanf("%d", &n);
    S = sqrt(n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++) {
        g[id(i)].push_back(a[i]);
        f[id(i)][a[i]] ++;
    }
    int m;
    scanf("%d", &m);
    int lastans = 0;
    while (m --) {
        int sig, l, r, k;
        scanf("%d %d %d", &sig, &l, &r);
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        swap(l, r);
        l = n - l + 1;
        r = n - r + 1;
        if (l > r) swap(l, r);
        if (sig == 1) {
            int lid = id(l), rid = id(r);
            if (lid == rid) {
                myrotate(lid, (l - 1) % S, (r - 1) % S);
            } else {
                int sv = g[lid + 1][0];
                for (int i = lid + 1; i < rid; i ++) {
                    f[i][g[i][0]]--;
                    g[i].pop_front();
                    g[i].push_back(g[i + 1][0]);
                    f[i][g[i + 1][0]] ++;
                }
                myrotate(lid, (l - 1) % S, g[lid].size() - 1);
                int lv;
                f[lid][lv = *g[lid].rbegin()]--;
                f[lid][*g[lid].rbegin() = sv] ++;
                f[rid][g[rid][0]] --;
                f[rid][g[rid][0] = lv] ++;
                myrotate(rid, 0, (r - 1) % S);
            }
        } else {
            scanf("%d", &k);
            k = (k + lastans - 1) % n + 1;
            lastans = 0;
            int ll = 1;
            sig = 0;
            while (ll <= n) {
                int rr = min(ll + S - 1, n);
                if (l <= ll && rr <= r)
                    lastans += f[sig][k];
                else {
                    for (int i = max(ll, l); i <= min(rr, r); i ++)
                        lastans += (g[sig][i - ll] == k);
                }
                ll = rr + 1;
                ++sig;
            }
            printf("%d\n", lastans);
        }
    }
    return 0;
}