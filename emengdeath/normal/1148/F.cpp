#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e5 + 19;
pair<long long, int> a[N];
int n;
int main() {
    scanf("%d", &n);
    long long all = 0;
    for (int i = 1; i <= n; i ++)
        scanf("%d %lld", &a[i].second, &a[i].first), all += a[i].second;
    sort(a + 1, a + n + 1);
    long long ans = 0;
    int l = 1;
    for (int i = 1; i <= 62; i ++) {
        long long now_all = 0;
        while (l <= n && a[l].first < (((long long) 1) << i)) {
            if (__builtin_popcountll(a[l].first & ans) & 1)
                now_all -= a[l].second;
            else
                now_all += a[l].second;
             ++ l;
        }
        if (!now_all) continue;
        if ((now_all < 0) == (all < 0)) ans |= (((long long)1) << (i -1));
    }
    printf("%lld", ans);
    return 0;
}