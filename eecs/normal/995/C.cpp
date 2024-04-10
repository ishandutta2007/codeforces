#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
const int maxn = 100010;
int n, c[maxn], tag[maxn], id[maxn];
ll x[maxn], y[maxn];
mt19937 rnd(time(0));

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }
    while (1) {
        memset(tag, 0, sizeof(tag));
        iota(id + 1, id + n + 1, 1);
        shuffle(id + 1, id + n + 1, rnd);
        ll sx = 0, sy = 0;
        for (int $ = 1; $ <= n; $++) {
            int i = id[$];
            ll mn = LLONG_MAX;
            for (int p : {-1, 1}) for (int q : {-1, 1}) {
                ll nx = sx * p + x[i] * q;
                ll ny = sy * p + y[i] * q;
                mn = min(mn, nx * nx + ny * ny);
            }
            bool flag = 0;
            for (int p : {-1, 1}) for (int q : {-1, 1}) {
                ll nx = sx * p + x[i] * q;
                ll ny = sy * p + y[i] * q;
                if (nx * nx + ny * ny == mn && !flag) {
                    if (!~p) tag[i - 1] ^= 1;
                    c[i] = q, flag = 1;
                    sx = nx, sy = ny;
                }
            }
        }
        if (sx * sx + sy * sy <= 1500000LL * 1500000) break;
    }
    for (int i = n; i; i--) {
        tag[i] ^= tag[i + 1];
        if (tag[i]) c[id[i]] *= -1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", c[i]);
    }
    return 0;
}