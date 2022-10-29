#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
const ll is_query = 1ll << 62;
struct line{
    ll k, b;
    mutable function<const line *()> succ;
    bool operator<(const line & a) const {
        if (a.b != is_query)  return k < a.k;
        const line *y = succ();
        if (!y) return 0;
        return (__int128)a.k * k + b < (__int128)a.k * y->k + y->b;
    }
};
struct HT:public multiset<line> {
    bool bad(iterator y) {
        if (y == begin())
            return 0;
        auto z = next(y);
        if (z == end())
            return 0;
        auto x = prev(y);
        return (__int128)(x->b - z->b) * (y->k - x->k) <= (__int128)(x->b - y->b) * (z ->k - x->k);
    }
    void insert_line(ll k, ll b) {
        auto y = insert({k, b});
        y -> succ = [=]() {return next(y) == end()? 0: &*next(y);};
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    ll eval(ll x) {
        auto y = *lower_bound((line){x, is_query});
        return y.k * x + y.b;
    }
}*F[N], tmp[N];
int n;
int a[N], b[N];
long long f[N];
int L;
vector<int> g[N];
void merge(HT *a, HT *b) {
    for (auto u:*b)
        a->insert_line(u.k, u.b);
}
void dfs(int x, int fa) {
    for (auto u:g[x])
        if (u != fa) {
            dfs(u, x);
            if (F[x] == NULL)
                F[x] = F[u];
            else {
                if (F[x]->size() > F[u]->size()) {
                    merge(F[x], F[u]);
                } else {
                    merge(F[u], F[x]);
                    F[x] = F[u];
                }
            }
        }
    if (F[x] == NULL)
        f[x] = 0, F[x] = &tmp[L ++];
    else
        f[x] =-F[x]->eval(a[x]);
    F[x]->insert_line(-b[x], -f[x]);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &b[i]);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i= 1; i <= n; i ++)
        printf("%lld%c", f[i], " \n"[i == n]);
    return 0;
}