#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n, m;
int f[N];
pair<int, int> a[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++)
        f[i] = 1e9;
    for (int i = 1; i <= n; i ++)
        scanf("%d %d", &a[i].first, &a[i].second);
    sort(a + 1, a + n + 1);
    for (int i = 1; i<= n; i ++) {
        for (int j = min(a[i].second + a[i].first, m); j <= m || 2 * a[i].first - j > 0; j++) {
            int len = j - a[i].first;
            int len1 = max(j - a[i].first, a[i].second);
            f[min(j, m)] = min(f[max(0, a[i].first - len1 - 1)] + max(len - a[i].second, 0), f[min(j, m)]);
        }
        for (int j = 2; j <= m; j ++)
            f[j] = min(f[j], f[j - 1] + 1);
        for (int j = m - 1;j  >= 1; j --)
            f[j] = min(f[j], f[j + 1]);
    }
    printf("%d\n", f[m]);
    return 0;
}