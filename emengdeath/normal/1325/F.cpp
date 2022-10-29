#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
const int N = 1e5 + 10;
int n, m, S;
vector<int>g[N];
int d[N];
bool del[N];
int id[N], q[N];
set<pair<int, int> > w;
void work(int x) {
    if (del[x])
        return;
    del[x] = 1;
    w.erase({d[x], x});
    for (auto u:g[x])
        if (!del[u]) {
            w.erase({d[u], u});
            d[u] --;
            w.insert({d[u], u});
        }
}
int main() {
    scanf("%d %d", &n, &m);
    S = ceil(sqrt(n)) - 1;
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
        d[x]++;
        d[y] ++;
    }
    for (int i = 1; i <= n; i ++)
        w.insert({d[i], i});
    vector<int> ans;
    while (ans.size() <= S) {
        auto u = *w.begin();
        if (u.first >= S) {
            q[0] = 1;
            q[1] = u.second;
            id[u.second] = 1;
            for (int i = 1; i <= q[0]; i ++)
                for (auto w:g[q[i]])
                    if (!del[w] && !id[w]) {
                        q[++q[0]] = w;
                        id[w] = q[0];
                        break;
                    }
            int x = q[0];
            for (auto w:g[q[q[0]]])
                if (!del[w])
                    x = min(x, id[w]);
            puts("2");
            printf("%d\n", q[0] - x + 1);
            for (int i= x; i <= q[0]; i ++)
                printf("%d ", q[i]);
            return 0;
        }
        ans.push_back(u.second);
        work(u.second);
        for (auto v:g[u.second])
            work(v);
    }
    puts("1");
    for (auto u:ans)
        printf("%d ", u);
    return 0;
}