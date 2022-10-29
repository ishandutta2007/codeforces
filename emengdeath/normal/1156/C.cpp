#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 2e5 + 1;
int n, z;
int a[N];
bool check(int v)
{
    int r = v + 1;
    for (int i = 1; i <= v; i  ++)
    {
        while (r<=n && a[r] - a[i] < z) r ++;
        if (r > n) return 0;
        r ++;
    }
    return 1;
}
int main()
{
    scanf("%d %d", &n, &z);
    for (int i = 1; i <= n ; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 0, r = n  / 2, mid, s = 0;
    while (l <= r)
    {
        if (check(mid = (l + r) / 2)) l = mid + 1, s = max(s, mid);
        else
            r = mid - 1;
    }
    printf("%d\n", s);
    return 0;
}