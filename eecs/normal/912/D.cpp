#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, r; ll k, ans;
set<pair<ll, ll> > S;

int main() {
    scanf("%d %d %d %lld", &n, &m, &r, &k);
    if (n > m) swap(n, m);
    ll xx = min(r, n - r + 1), yy = min(r, m - r + 1);
    priority_queue<pair<ll, pair<ll, ll>>> q;
    q.push({xx * yy, {xx, yy}});
    while (k > 0) {
        auto p = q.top(); q.pop();
        ll x = p.second.first, y = p.second.second, z = 0;
        if (x < 1 || x > xx || y < 1 || y > yy) continue;
        if (S.count({x, y})) continue;
        S.insert({x, y}), z = x == xx ? n - x - x + 2 : 2;
        z *= y == yy ? m - y - y + 2 : 2;
        ans += x * y * min((ll)k, z), k -= z;
        q.push({(x - 1) * y, {x - 1, y}});
        q.push({x * (y - 1), {x, y - 1}});
        q.push({(x - 1) * (y + 1), {x - 1, y + 1}});
        q.push({(x + 1) * (y - 1), {x + 1, y - 1}});
    }
    printf("%.10f\n", 1.0 * ans / (n - r + 1) / (m - r + 1));
    return 0;
}