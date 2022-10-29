#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 150000 + 100;
namespace edge{
    vector<int> f[N * 4];
    int edge[N * 30][2];
    bool bz[N * 30];
    int tot = -1;
    int new_edge(int x, int y){
        edge[++tot][0] = x;
        edge[tot][1] = y;
        bz[tot] = 1;
        return tot;
    }
    void add(int l, int r, int s, int ll, int rr, int v) {
        if (r < ll || rr < l) return;
        if (ll <= l && r <= rr) {
            f[s].push_back(v);
            return;
        }
        add(l, (l + r) / 2, s + s, ll, rr, v), add((l + r) / 2 + 1, r, s + s+ 1, ll, rr, v);
    }
    vector<pair<int, int> > get(int l, int r, int s, int ll) {
        vector<pair<int, int> >d;
        while (1) {
            for (auto u:f[s])
                if (bz[u])
                    d.push_back(make_pair(edge[u][0], edge[u][1])), bz[u] = 0;
            f[s].clear();
            if (l == r) break;
            if ((l + r) / 2 >= ll)
                r = (l + r) /2 , s += s;
            else
                l = (l + r) / 2 + 1, s += s + 1;
        }
        return d;
    }
}
namespace subtree_sum{
    struct node{
        int sum;
        long long tag, v;
    }f[N * 4];
    void down(int l, int r, int s) {
        if (f[s].tag) {
            f[s].v += f[s].sum * f[s].tag;
            if (l != r)
                f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
            f[s].tag = 0;
        }
    }
    void add(int l, int r, int s, int ll, int rr, int v) {
        down(l, r, s);
        if (r < ll || rr < l) return;
        if (ll <= l && r <= rr) {
            f[s].tag += v;
            down(l, r, s);
            return;
        }
        add(l, (l +r) / 2, s + s, ll, rr, v);
        add((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
        f[s].v = f[s+s].v + f[s+s+1].v;
    }
    void insert(int l, int r, int s, int ll) {
        while (1) {
            down(l, r, s);
            f[s].sum ++;
            if (l == r) break;
            if ((l + r) / 2 >= ll)
                r = (l + r) / 2, s += s;
            else
                l = (l + r) / 2 + 1, s += s + 1;
        }
    }

    long long get(int l, int r, int s, int ll) {
        while (1) {
            down(l, r, s);
            if (l == r) return f[s].v;
            if ((l + r) / 2 >= ll)
                r = (l + r) / 2, s += s;
            else
                l = (l + r) / 2 + 1, s += s + 1;
        }
    }
}
namespace neighbor{
    int f[N * 4];
    void ins(int l, int r, int s, int ll, int v) {
        while (1) {
            f[s] = max(f[s], v);
            if (l == r) return;
            if ((l + r) / 2 >= ll)
                r = (l + r) / 2, s += s;
            else
                l = (l + r) / 2 + 1, s += s + 1;
        }
    }
    int getleft(int l, int r, int s, int ll, int rr, int v) {
        if (r < ll || rr < l || f[s] <= v) return 0;
        if (l == r) return l;
        int tmp = getleft((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
        if (tmp) return tmp;
        return getleft(l, (l +r ) /2, s+ s, ll, rr, v);
    }
    int getright(int l, int r, int s, int ll, int rr, int v) {
        if (r < ll || rr < l || f[s] <= v) return 0;
        if (l == r) return l;
        int tmp = getright(l, (l + r) / 2, s + s, ll, rr, v);
        if (tmp) return tmp;
        return getright((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
    }
    int getmx(int l, int r, int s, int ll, int rr) {
        if (r < ll || rr < l || ! f[s]) return 0;
        if (ll <= l && r <= rr) return f[s];
        return max(getmx(l, (l + r) / 2, s + s, ll, rr) , getmx((l +r) / 2 + 1, r, s + s + 1, ll, rr));
    }
}
int n;
int a[N], id[N];
void addedge(int x, int y) {
    if (x > y) swap(x, y);
    int w = edge::new_edge(x, y);
    edge::add(1, n, 1, x + 1, y - 1, w);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), id[a[i]] = i;
    for (int i = 1; i <= n; i ++) {
        int x = id[i];
        vector<pair<int, int> > d = edge::get(1, n, 1, x);
        sort(d.begin(), d.end(), [](pair<int, int>x, pair<int, int> y) {
            return max(a[x.first], a[x.second])  < max(a[y.first], a[y.second]);
        });
        for (auto u:d) {
            int y = u.first, z = u.second;
            if (a[y] > a[z]) {
                int yy = neighbor::getright(1, n, 1, y + 1, n, a[y]);
                if (!yy) yy = n + 1;
                long long v = subtree_sum::get(1, n, 1, z);
                subtree_sum::add(1, n, 1, x + 1, yy - 1, -(v - 1));
                if (yy != n + 1) {
                    subtree_sum::add(1, n, 1, x + 1, yy - 1, subtree_sum::get(1, n, 1, yy));
                    addedge(z, yy);
                }
            } else {
                int yy = neighbor::getleft(1, n, 1, 1, z - 1, a[z]);
                long long v = subtree_sum::get(1, n, 1, y);
                subtree_sum::add(1, n, 1, yy + 1, x - 1, -(v - 1));
                if (yy) {
                    subtree_sum::add(1, n, 1, yy + 1, x - 1, subtree_sum::get(1, n, 1, yy));
                    addedge(y, yy);
                }
            }
        }
        subtree_sum::insert(1, n, 1, x);
        subtree_sum::add(1, n, 1, 1, n, 1);
        neighbor::ins(1, n, 1, x, i);
        int lmx = neighbor::getmx(1, n, 1, 1, x - 1), rmx = neighbor::getmx(1, n, 1, x + 1, n);
        if (lmx) {
            addedge(x, id[lmx]);
        }
        if (rmx)
            addedge(x, id[rmx]);
        printf("%lld\n", subtree_sum::f[1].v);
    }
}