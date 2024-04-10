#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int N = 4e5 + 10;
int n, m, q;
struct node{
    int l, r;
    bool sig;
}f[N * 4];
set<int> gl[N], gr[N];
void upd(int s) {
    f[s].l = min(f[s + s].l, f[s + s + 1].l);
    f[s].r = max(f[s + s].r, f[s + s + 1].r);
    f[s].sig = (f[s+s].sig || f[s+s+1].sig || (f[s+s].l <= f[s+s+1].r));
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].l = *gl[l].begin();
        f[s].r = *gr[l].rbegin();
        f[s].sig = f[s].l <= f[s].r;
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s+ 1);
    upd(s);
}
void change(int l, int r, int s, int ll) {
    if (l == r) {
        f[s].l = *gl[l].begin();
        f[s].r = *gr[l].rbegin();
        f[s].sig = f[s].l <= f[s].r;
        return;
    }
    if ((l + r) / 2 >= ll)
        change(l, (l + r) / 2, s + s, ll);
    else
        change((l + r) / 2 + 1, r, s + s+ 1, ll);
    upd(s);
}
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n;i ++)
        gl[i].insert(m +1), gr[i].insert(0);
    build(1, n, 1);
    while (q --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int xx = (x + 1) / 2;
        int yy = (y + 1) / 2;
        if (x & 1) {
            auto u = gl[xx].find(yy);
            if (u == gl[xx].end())
                gl[xx].insert(yy);
            else
                gl[xx].erase(u);
        } else {
            auto u = gr[xx].find(yy);
            if (u == gr[xx].end())
                gr[xx].insert(yy);
            else
                gr[xx].erase(u);
        }
        change(1, n, 1, xx);
        f[1].sig?puts("NO"):puts("YES");
    }
    return 0;
}