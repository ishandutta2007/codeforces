#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, s, ans = -1;

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u < s || (u == s && v == 0))
            ans = max(ans, (100 - v) % 100);
    }
    printf("%d\n", ans);
    return 0;
}