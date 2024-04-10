#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int a[100010], ans[100010];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 0;
    for (int i = 2; i <= n; i += 2)
        ans[i] = a[++l];
    for (int i = 1; i <= n; i += 2)
        ans[i] = a[++l];
    int ans1 = 0;
    for (int i = 2; i + 1 <= n; i += 2)
        ans1 += (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]);
    printf("%d\n", ans1);
    for (int i = 1; i <= n;i ++)
        printf("%d%c", ans[i], " \n"[i ==n]);
    return 0;
}