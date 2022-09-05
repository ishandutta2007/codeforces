#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
const int maxn = 100010;
int n, w;
ll ans;
array<ll, 2> a[maxn];
tree<pair<ll, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> T;

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 1, x, v; i <= n; i++) {
        scanf("%d %d", &x, &v), x = -x;
        long double l = (long double)x / (v - w);
        long double r = (long double)x / (v + w);
        a[i][0] = floor(l * 1e13), a[i][1] = floor(r * 1e13);
    }
    sort(a + 1, a + n + 1, [&](array<ll, 2> p, array<ll, 2> q) {
        return p[0] ^ q[0] ? p[0] < q[0] : p[1] > q[1];
    });
    map<ll, int> mp;
    for (int i = 1; i <= n; i++) {
        pair<ll, int> p(a[i][1], --mp[a[i][1]]);
        ans += i - 1 - T.order_of_key(p);
        T.insert(p);
    }
    printf("%lld\n", ans);
    return 0;
}