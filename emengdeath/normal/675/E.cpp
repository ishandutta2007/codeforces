#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
long long f[N];
pair<int, int> d[N];
int n, tot;
int a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n ;  i ++)
        scanf("%d", &a[i]);
    long long ans = 0;
    ++tot;
    d[1].first = n;
    d[1].second = n;
    for (int i = n - 1; i >= 1; i --) {
        int l = 0;
        for (int j = 20; j >= 0; j --)
            if (l + (1 << j) <= tot  && d[l + (1<<j)].first > a[i]) l += (1 << j);
        ++l;
        f[i] = f[d[l].first] + n - i - (a[i] - d[l].first);
        d[++tot].first = i;
        d[tot].second = a[i];
        while (d[tot].second > d[tot - 1].second && tot > 1)
            d[tot - 1] = d[tot], tot --;
        ans += f[i];
    }
    printf("%lld\n", ans);
    return 0;
}