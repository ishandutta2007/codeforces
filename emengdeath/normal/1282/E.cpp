#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e6;
int T;
int n;
int l[N], r[N], du[N], e[N][3];
vector<pair<int, pair<int, int> > > g[N];
priority_queue<pair<int, int> > h;
int ans[N];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) l[i] = r[i] = 0, du[i] = 0;
        for (int i = 1; i <= n - 2; i ++ ) {
            int x ,y ,z;
            scanf("%d %d %d", &x, &y, &z);
            e[i][0] = x, e[i][1] = y, e[i][2] = z;
            du[x]++;
            du[y] ++;
            du[z] ++;
            g[x].push_back(make_pair(i, make_pair(y, z)));
            g[y].push_back(make_pair(i, make_pair(x, z)));
            g[z].push_back(make_pair(i, make_pair(y, x)));
        }
        for (int i = 1; i <= n; i ++)
            h.push(make_pair(-du[i], i));
        ans[0] =0;
        while (!h.empty()) {
            auto v = h.top();
            h.pop();
            if (-v.first != du[v.second] || v.first >= 0) continue;
            v.first = -v.first;
            du[v.second] = -1;
            for (auto ww:g[v.second]) {
                if (du[ww.second.second] > 0 && du[ww.second.first] > 0) {
                    du[ww.second.second] --;
                    du[ww.second.first] --;
                    h.push(make_pair(-du[ww.second.second], ww.second.second));
                    h.push(make_pair(-du[ww.second.first], ww.second.first));
                    ans[++ans[0]] = ww.first;
                    break;
                }
            }
        }
        for (int i = 1; i <= n ; i ++ )
            du[i] = 0;
        for (int i = ans[0]; i; i --) {
            int x = e[ans[i]][0], y = e[ans[i]][1], z = e[ans[i]][2];
            if (!du[x] && !du[y] && !du[z]) {
                l[x] = y;
                r[x] = z;
                r[y] = x;
                l[y] = z;
                l[z] = x;
                r[z] = y;
                du[x] ++;
                du[y] ++;
                du[z] ++;
                continue;
            }
            if (!du[y]) swap(x, y);
            if (!du[z]) swap(x, z);
            if (r[z] == y) swap(y, z);
            r[y] = x;
            l[x] = y;
            l[z] = x;
            r[x] = z;
            du[x] ++;
            du[y] ++;
            du[z] ++;
        }
        int x = 1;
        for (int i = 1; i <= n; i ++, x = r[x])
            printf("%d%c", x, " \n"[i == n]);
        for (int i = 1; i <= n - 2; i ++)
            printf("%d%c", ans[i], " \n"[i == n - 2]);
        for (int i = 1; i <= n; i ++)g[i].clear();
    }
    return 0;
}