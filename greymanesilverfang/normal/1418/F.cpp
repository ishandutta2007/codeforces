#include <cstdio>
#include <algorithm>
#include <vector>
const int MAX = 2e5+5;
int n, m, x1, y1, x2, y2, x, d;
long long l, r, l1, r1, l2, r2;
struct Data
{
    int div, val;
    bool operator < (int d) const { return div < d; }
    bool operator < (const Data &d) const { return div < d.div; }
    bool operator == (const Data &d) const { return div == d.div; }
};
struct Node
{
    int l, r;
    std::vector<Data> v;
};
Node node[MAX*4];

void build(int l, int r, int id = 1)
{
    Node &n = node[id];
    n.l = l;
    n.r = r;
    if (l == r)
    {
        int val = l;
        for (int i = 1; i * i <= val; ++i)
            if (val % i == 0)
            {
                n.v.push_back({i, val});
                n.v.push_back({val / i, val});
            }
        std::sort(n.v.begin(), n.v.end());
        return;
    }
    int m = (l + r) / 2;
    int lc = id * 2;
    int rc = lc + 1;
    build(l, m, lc);
    build(m + 1, r, rc);
    const std::vector<Data> &lv = node[lc].v, &rv = node[rc].v;
    n.v.resize(lv.size() + rv.size());
    std::merge(lv.begin(), lv.end(), rv.begin(), rv.end(), n.v.begin());
    n.v.resize(std::unique(n.v.begin(), n.v.end()) - n.v.begin());
}

bool query(int id = 1)
{
    const Node &n = node[id];
    if (r1 < n.l || n.r < l1)
        return false;
    if (l1 <= n.l && n.r <= r1)
    {
        const std::vector<Data> &v = n.v;
        auto it = std::lower_bound(v.begin(), v.end(), l2);
        if (it == v.end())
            return false;
        Data dat = *it;
        if (dat.div > r2 || dat.div > m)
            return false;
        x1 = x;
        y1 = dat.val;
        x2 = x / d * dat.div;
        y2 = dat.val / dat.div * d;
        return true;
    }
    bool res = query(id * 2) || query(id * 2 + 1);
    return res;
}

bool check(int num)
{
    d = num;
    l2 = d + 1;
    r2 = 1LL * d * n / x;
    return query();
}

bool solve(int num)
{
    x = num;
    l1 = (l - 1) / x + 1;
    r1 = r / x;
    for (int i = 1; i * i <= x; ++i)
        if (x % i == 0)
            if (check(i) || check(x / i))
                return true;
    return false;
}

int main()
{
    scanf("%d%d%lld%lld", &n, &m, &l, &r);
    build(1, m);
    for (int i = 1; i <= n; ++i)
        if (solve(i))
            printf("%d %d %d %d\n", x1, y1, x2, y2);
        else 
            printf("-1\n");
}