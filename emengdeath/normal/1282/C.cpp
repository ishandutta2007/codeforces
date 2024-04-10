#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int T;
int n, t, a, b;
pair<int, int> d[N];
int sum[N][2], all[2];
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
bool check(int x, int y) {
    long long allt = 1ll * x * a + 1ll * y * b;
    if (allt > t) return 0;
    int sig = upper_bound(d + 1, d + n + 1, make_pair(allt, 2), cmp) - d - 1;
    return sum[sig][0] <= x && sum[sig][1] <= y;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d %d %d", &n, &t, &a, &b);
        all[0] = all[1] = 0;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &d[i].second), all[d[i].second]++;
        for (int i = 1; i <= n; i ++)
            scanf("%d", &d[i].first);
        sort(d + 1, d + n + 1);
        sum[n + 1][0] = sum[n + 1][1] = 0;
        for (int i = n; i >= 1; i --) {
            sum[i][0] = sum[i + 1][0];
            sum[i][1] = sum[i + 1][1];
            sum[i][d[i].second] ++;
        }
        if (1ll * a * all[0]+ 1ll * b * all[1] <= t) {
            printf("%d\n", n);
            continue;
        }
        int cnt = 0;
        int ans = 0;
        for (int i = 1; i <= n && cnt <= t; i ++) {
            if (cnt < d[i].first) {
                int release = d[i].first - cnt - 1;
                int a1 = min(release / a, sum[i][0]);
                release -= a * a1;
                int b1 = min(release / b, sum[i][1]);
                ans = max(ans, i  - 1 + a1 + b1);
            }
            if (d[i].second)
                cnt += b;
            else
                cnt += a;
        }
        printf("%d\n", ans);
    }
    return 0;
}