#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u + 2 <= v)
            ans ++;
    }
    printf("%d\n", ans);
    return 0;
}