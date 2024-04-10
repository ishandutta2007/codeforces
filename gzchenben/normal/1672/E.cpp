#include <cstdio>
#include <algorithm>
using namespace std;
int check(int x)
{
    printf("? %d\n", x);
    fflush(stdout);
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}
int n;
int main()
{
    scanf("%d", &n);
    int L = 1, R = 1e7;
    while (L < R)
    {
        int mid = (L + R) / 2;
        if (check(mid) == 1)
            R = mid;
        else
            L = mid + 1;
    }
    int ans = L;
    for (int i = 1; i <= n; i++)
    {
        int Now = check(L / i);
        if (Now != 0)
            ans = min(ans, Now * (L / i));
    }
    printf("! %d\n", ans);
}