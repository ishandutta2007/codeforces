#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 300101;
long long d[N], c[N];
long long q[N][2];
int n, a;
long long ans;
int l, r;
int main() {
    scanf("%d %d", &n, &a);
    for (int  i = 1; i <= n ; i ++) {
        scanf("%lld %lld", &d[i], &c[i]);
        ans = max(ans, a - c[i]);
    }
    for (int i = 1; i <= n; i ++) {
        c[i] = c[i - 1] - c[i] + a;
    }
    l = N - 1;
    r = N - 2;
    for (int i = 2; i <= n; i ++) {
        long long v = c[i - 2];
        long long vv = (d[i - 1] - d[i]) * (d[i - 1] - d[i]);
        while (l <= r && q[l][1] <= vv) {
            v = min(v, q[l++][0]);
        }
        if (l>r || q[l][1] + q[l][0] > v + vv)
            q[--l][0] = v, q[l][1] = vv;
        ans = max(ans, c[i]-q[l][0]-q[l][1]);
    }
    printf("%lld\n", ans);
    return 0;
}