#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans = 0;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int t;
        scanf("%d", &t);
        ans = max(ans, t);
    }
    printf("%d\n", ans);
    return 0;
}