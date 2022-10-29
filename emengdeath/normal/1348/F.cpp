#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 2e5 + 10;
int n;
int l[N], r[N];
int v[N], loc[N];
vector<pair<int, int> > w[N];
int f[N*4];
void ins(int l, int r, int s, int ll, int v) {
    while (1) {
        f[s] = v;
        if (l == r) return;
        if ((l + r) / 2 >= ll) r = (l + r ) / 2, s += s;
        else
            l = (l + r) / 2 + 1, s += s + 1;
    }
}
int get(int l, int r, int s, int ll, int rr) {
    if (!f[s] || r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) return f[s];
    int x = get(l, (l + r) / 2, s + s, ll, rr);
    return x ? x : get((l + r) / 2 +1, r, s + s + 1, ll, rr);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d %d",&l[i], &r[i]);
        w[l[i]].push_back({r[i], i});
    }
    priority_queue<pair<int, int> > h;
    for (int i = 1; i <= n; i ++) {
        for (auto u:w[i])
            h.push({-u.first, u.second});
        loc[v[i] = h.top().second] = i;
        h.pop();
    }
    for (int i = 1; i <= n; i ++)
        w[i].clear();
    for (int i = 1; i <= n; i ++)
        w[r[i]].push_back({loc[i], i});
    for (int i = n; i >= 1; i --) {
        for (auto u:w[i])
            ins(1, n, 1, u.first, u.second);
        int x = get(1, n, 1, l[v[i]], i - 1);
        if (x) {
            puts("NO");
            for (int i = 1; i <= n; i ++)
                printf("%d%c", loc[i], " \n"[i == n]);
            swap(loc[v[i]], loc[x]);
            for (int i = 1; i <= n; i ++)
                printf("%d%c", loc[i], " \n"[i == n]);
            return 0;
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i ++)
        printf("%d%c", loc[i], " \n"[i == n]);
    return 0;
}