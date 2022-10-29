#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n;
int a[N];
long long sum[2];
long long ans;
int main() {
    int T = 1;
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), a[i + n] = a[i];
        ans = 0;
        sum[0] = sum[1] = 0;
        int r = 0;
        for (int i = 1; i <= n; i ++) {
            swap(sum[0], sum[1]);
            while (r <= i + n - 1) {
                ++r;
                sum[(r - i) & 1] += a[r];
            }
            ans = max(ans, sum[0]);
            sum[0] -= a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}