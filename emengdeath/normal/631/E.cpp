#include <algorithm>
#include <cstdio>
#include <set>
#include <functional>
using namespace std;
typedef long long ll;
const int N = 1e6;
const ll is_query = 1ll << 62;
struct line{
    ll k, b;
    mutable function<const line *()> succ;
    bool operator<(const line & a) const {
        if (a.b != is_query)  return k < a.k;
        const line *y = succ();
        if (!y) return 0;//querylower_boundthisquery
        return a.k * k + b < a.k * y->k + y->b;
    }
};
struct HullDynamic:public multiset<line> {//xydp 
    bool bad(iterator y) {
        if (y == begin())
            return 0;
        auto z = next(y);
        auto x = prev(y);
        if (z == end())
            return 0;
        return (x->b - z->b) * (y->k - x->k) <= (x->b - y->b) * (z ->k - x->k);
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
};
int n;
int a[N];
int x[N];
ll f[N];
ll work() {
    HullDynamic h;
    h.clear();
    ll v = 0;
    for (int i = 1; i <= n; i ++) {
        f[i] = f[i - 1] + a[i];
        h.insert_line(x[i], -f[i - 1]);
        ll now = h.eval(a[i]) + f[i - 1] - 1ll * a[i] *x[i];
        v = max(v, now);
    }
    return v;
}
int main() {
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        ans += 1ll * i * a[i];
        x[i] = i;
    }
    ll w= work();
    reverse(a + 1, a + n + 1);
    reverse(x + 1, x + n + 1);
    for (int i = 1; i <= n; i ++)
        x[i] *=-1, a[i] *= -1;
    ans += max(work(), w);
    printf("%lld\n", ans);
    return 0;
}