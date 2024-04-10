#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e5+ 10;
const int S = 334;
struct node{
    int l, r, x;
    node(int l = 0, int r = 0, int x = 0):l(l), r(r), x(x){}
};
long long ans[N];
int n, k;
long long a[N];
int id[N], idkl[N], idkr[N];
map<long long, int> f;
int fl[N * 4], fr[N * 4];
int tot = 0;
void update(long long x) {
    if (!f[x])
        f[x] = ++tot;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%lld", &a[i]), a[i] = 1 - (a[i] - 1) * 2;
    for (int i= 1; i <= n; i ++){
        int x;
        scanf("%d", &x);
        a[i] *= x;
        a[i] += a[i - 1];
    }
    for (int i = 0; i <= n; i ++) {
        update(a[i]);
        update(a[i] + k);
        update(a[i] - k);
        id[i] = f[a[i]];
        idkl[i] = f[a[i] - k];
        idkr[i] = f[a[i] + k];
    }
    int q;
    scanf("%d", &q);
    vector<node>g;
    for (int i= 1; i<= q; i ++) {
        int l, r;
        scanf("%d %d", &l, &r);
        g.push_back(node{l, r, i});
    }
    sort(g.begin(),g.end(), [](const node&a, const node& b) {
        if (a.l / S == b.l / S) {
            if (a.l / S & 1)
                return a.r < b.r;
            else
                return a.r > b.r;
        } else
            return a.l < b.l;
    });
    int l = 1, r = 0;
    long long v = 0;
    for (auto u:g) {
        while (l > u.l) {
            --l;
            fr[id[l]] ++;
            fl[id[l - 1]] ++;
            v += fr[idkr[l - 1]];
        }
        while (r < u.r) {
            ++r;
            fr[id[r]] ++;
            fl[id[r - 1]] ++;
            v += fl[idkl[r]];
        }
        while (l < u.l) {
            v -= fr[idkr[l - 1]];
            fr[id[l]] --;
            fl[id[l - 1]] --;
            l ++;
        }
        while (r > u.r) {
            v -= fl[idkl[r]];
            fr[id[r]] --;
            fl[id[r - 1]] --;
            r --;
        }
        ans[u.x] = v;
    }
    for (int i= 1; i <= q; i ++)
        printf("%lld\n", ans[i]);
    return 0;
}