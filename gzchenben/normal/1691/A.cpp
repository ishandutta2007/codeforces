#include <cstdio>
#include <algorithm>
using namespace std;
int n, t, a[100005], cnt[2];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cnt[0] = cnt[1] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            cnt[a[i] % 2]++;
        }
        printf("%d\n", min(cnt[0], cnt[1]));
    }
}