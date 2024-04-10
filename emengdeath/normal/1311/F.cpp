#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
long long f[N];
int sum[N], b[N];
int n;
pair<int, int> a[N];
void ins(int x, int v) {
    while (x <= n) {
        f[x] += v;
        sum[x] ++;
        x += x & -x;
    }
}
pair<long long , int > get(int x) {
    pair<long long, int> w(0, 0);
    while (x) {
        w.first += f[x];
        w.second += sum[x];
        x -= x & -x;
    }
    return w;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i].first);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i].second), b[i] = a[i].second;
    sort(b + 1, b + n + 1);
    sort(a +1, a + n + 1);
    long long ans = 0;
    for (int i= 1; i <= n; i ++) {
        int v = lower_bound(b+1, b + n + 1, a[i].second) - b;
        auto u = get(v);
        ans += 1ll * u.second * a[i].first - u.first;
        ins(v, a[i].first);
    }
    printf("%lld\n", ans);
    return 0;
}