#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <map>
using namespace std;
const int N = 2e5 + 10;
int n, m;
struct Revocable_disjoint_set {
    struct node{
        int sz, fa, v;
    };
    vector<node> f;
    stack<pair<int, int> > record;
    void init(int n){
        while (!record.empty()) record.pop();
        f.resize(n + 1);
        for (int i = 1; i <= n ; i ++)
            f[i].sz = 1, f[i].fa = i, f[i].v = 0;
    }
    int root(int x){
        while (f[x].fa!=x) x = f[x].fa;
        return x;
    }
    int getv(int x) {
        int v = 0;
        while (f[x].fa != x) v ^= f[x].v, x = f[x].fa;
        return v;
    }
    bool merge(int x, int y ,int v) {
        int xv = getv(x), yv = getv(y);
        if ((x = root(x)) == (y = root(y))) return 0;
        if (f[x].sz > f[y].sz) swap(x, y), swap(xv, yv);
        f[x].fa = y;
        f[x].v ^= (xv ^ yv ^ v);
        f[y].sz += f[x].sz;
        record.push({x, xv ^ yv ^ v});
        return 1;
    }
    void undo() {
        auto x = record.top();
        record.pop();
        f[f[x.first].fa].sz -= f[x.first].sz;
        f[x.first].fa = x.first;
        f[x.first].v ^= x.second;
    }
    void undo_to_x(int x) {
        while (record.size() > x) undo();
    }
}T;
const int M = 32;
struct LinearBasis{
    typedef unsigned int type;
    type v[M];
    int tot = 0;
    void clear(){
        tot = 0;
        memset(v, 0, sizeof(v));
    }
    void insert(type u) {
        for (int i = tot - 1; i >= 0; i--)
            if ((u ^ v[i]) < u) u ^= v[i];
        v[tot++] = u;
        for (int i = tot - 1; v[i - 1] > v[i]&& i >= 1; i --)
            swap(v[i], v[i - 1]);
    }
    bool can_describe(type x) {
        for (int i = tot - 1; i >= 0; i --)
            if ((x ^ v[i]) < x) x ^= v[i];
        return x == 0;
    }
    type shape(type x) {
        for (int i = tot - 1; i >= 0; i --)
            if ((x ^ v[i]) < x) x ^= v[i];
        return x;
    }
}L;
vector<pair<pair<int, int>, int> > e[N * 4];
vector<pair<int, int> >q[N];
map<pair<int, int>, pair<int, int> > last;
vector<int> ans;
void inse(int l, int r, int s, int ll, int rr, int x, int y, int v) {
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        e[s].push_back({{x, y}, v});
        return ;
    }
    inse(l, (l + r) / 2, s + s, ll, rr, x, y, v);
    inse((l + r) / 2 + 1, r, s + s + 1, ll, rr, x, y, v);
}
void work(int l, int r, int s) {
    int tmp = T.record.size();
    LinearBasis now = L;
    for (auto u:e[s])
        if (!T.merge(u.first.first, u.first.second, u.second)) {
            int v = T.getv(u.first.first) ^ T.getv(u.first.second) ^ u.second;
            if (!L.can_describe(v))
                L.insert(v);
        }
    if (l == r) {
        for (auto u:q[l])
        {
            ans.push_back(L.shape(T.getv(u.first) ^ T.getv(u.second)));
        }
        L = now;
        T.undo_to_x(tmp);
       return;
    }
    work(l, (l + r )/ 2 , s + s);
    work((l + r) / 2 + 1, r, s + s + 1);
    L = now;
    T.undo_to_x(tmp);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        last[{x, y}] = {1, z};
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        switch (x) {
            case 1:
            scanf("%d", &x);
            last[{y, z}] = {i,x};
            break;
            case 2:
            inse(1, m, 1, last[{y, z}].first, i, y, z, last[{y, z}].second);
            last.erase(last.find({y, z}));
            break;
            case 3:
            q[i].push_back({y, z});
            break;
        }
    }
    for (auto u:last)
        inse(1, m, 1, u.second.first, m, u.first.first, u.first.second, u.second.second);
    T.init(n);
    L.clear();
    work(1, m, 1);
    for (auto u:ans)
        printf("%d\n", u);
    return 0;
}