#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, t;
char s[100005];
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        int tmp = -2e9;
        for (int i = n; i >= 1; i--)
        {
            if (s[i] == '1')
            {
                tmp = i;
                break;
            }
        }
        if (n - tmp <= k)
        {
            k -= (n - tmp);
            swap(s[tmp], s[n]);
        }
        tmp = 2e9;
        for (int i = 1; i <= n - 1; i++)
        {
            if (s[i] == '1')
            {
                tmp = i;
                break;
            }
        }
        if (tmp - 1 <= k)
        {
            swap(s[1], s[tmp]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                ans += 10 * (s[i] - '0');
            else if (i == n)
                ans += 1 * (s[i] - '0');
            else
                ans += 11 * (s[i] - '0');
        }
        printf("%d\n", ans);
    }
}