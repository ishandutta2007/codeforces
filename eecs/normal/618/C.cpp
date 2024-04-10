#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, id[maxn];
ll x[maxn], y[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld %lld", &x[i], &y[i]), id[i] = i;
    }
    sort(id + 2, id + n + 1, [&](int i, int j) {
        pair<long double, ll> p1 = make_pair(atan2((long double)y[i] - y[id[1]], (long double)x[i] - x[id[1]]),
            (x[i] - x[id[1]]) * (x[i] - x[id[1]]) + (y[i] - y[id[1]]) * (y[i] - y[id[1]]));
        pair<long double, ll> p2 = make_pair(atan2((long double)y[j] - y[id[1]], (long double)x[j] - x[id[1]]),
            (x[j] - x[id[1]]) * (x[j] - x[id[1]]) + (y[j] - y[id[1]]) * (y[j] - y[id[1]]));
        return abs(p1.first - p2.first) > 1e-12 ? p1.first < p2.first : p1.second < p2.second;
    });
    int pos = 3;
    long double tmp = atan2((long double)y[id[2]] - y[id[1]], (long double)x[id[2]] - x[id[1]]);
    while ((x[id[2]] - x[id[1]]) * (y[id[pos]] - y[id[1]]) == (x[id[pos]] - x[id[1]]) * (y[id[2]] - y[id[1]])) pos++;
    printf("%d %d %d\n", id[1], id[2], id[pos]);
    return 0;
}