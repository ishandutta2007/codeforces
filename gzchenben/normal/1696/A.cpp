#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, a[200005], z;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &z);
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            ans = max(ans, a[i] | z);
        }
        printf("%d\n", ans);
    }
}