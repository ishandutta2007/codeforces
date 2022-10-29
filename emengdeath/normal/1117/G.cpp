#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6 + 10;
struct node {
    int sum;
    long long all;
}f[N * 4],v;
pair<int, int> b[N];
long long ans[N];
int l[N], r[N], id[N];
int d[N], a[N];
int n, m;
vector<int>g[N];
void ins(int l, int r, int s, int ll, int lll) {
    f[s].sum ++, f[s].all += lll;
    if (l == r) return;
    if ((l + r) / 2 >= ll) ins(l, (l + r) / 2, s + s, ll, lll);
    else
        ins((l + r) /2 + 1, r, s + s + 1, ll, lll);
}
void get(int l, int r, int s, int ll, int rr) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        if (ll == l) v = f[s];
        else
            v.sum += f[s].sum, v.all += f[s].all;
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) / 2 + 1, r, s+ s+ 1, ll, rr);
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <=n; i ++) {
        scanf("%d", &a[i]);
        while (d[0] && a[d[d[0]]] < a[i]) d[0] --;
        if (d[0])
            l[i] = d[d[0]];
        else
            l[i] = 0;
        d[++d[0]] = i;
    }
    d[0] = 0;
    for (int i = n; i >= 1; i --) {
        while (d[0] && a[d[d[0]]] < a[i]) d[0] --;
        if (d[0])
            r[i] = d[d[0]];
        else
            r[i] = n + 1;
        d[++d[0]] = i;
    }
    for (int i = 1; i <= m; i ++)
        scanf("%d", &b[i].first), id[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i].second);
    sort(id +1, id + m + 1, [](int x, int y){
        return b[x].first > b[y].first;
    });
    for (int i = 1; i <= n; i ++)
        g[i].clear();
    for (int i = 1; i <= n; i ++)
        g[l[i]].push_back(i);
    int st = n;
    for (int i= 1; i <= m; i ++) {
        int x= id[i];
        while (st >= b[x].first) {
            for (auto u:g[st])
                ins(1, n, 1, u, l[u]);
            st --;
        }
        get(1, n, 1, b[x].first, b[x].second);
        ans[x] -=  v.all + 1ll * (b[x].second - b[x].first + 1 - v.sum) * (b[x].first - 1);
    }



    sort(id +1, id + m + 1, [](int x, int y){
        return b[x].second < b[y].second;
    });
    for (int i = 1; i <= n; i ++)
        g[i].clear();
    for (int i =1; i <= 4 * n; i ++)
        f[i].all = f[i].sum = 0;
    for (int i = 1; i <= n; i ++)
        g[r[i]].push_back(i);
    st = 1;
    for (int i= 1; i <= m; i ++) {
        int x= id[i];
        while (st <= b[x].second) {
            for (auto u:g[st])
                ins(1, n, 1, u, r[u]);
            st ++;
        }
        get(1, n, 1, b[x].first, b[x].second);
        ans[x] +=  v.all + 1ll * (b[x].second - b[x].first + 1 - v.sum) * (b[x].second + 1);
    }
    for (int i =1; i <= m; i ++)
        printf("%lld ", ans[i] - (b[i].second - b[i].first + 1));
    return 0;
}