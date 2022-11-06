#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 300000 + 5

int n, k, Next[N];

int main()
{
    scanf("%d%d", &n, &k);
    int u = 1;
    bool ok = 0;
    for (int i = 1; !ok && i < n; i ++)
    {
        scanf("%d", Next + i);
        Next[i] += i;
        u = u == i ? Next[i] : u;
        if (u == k) ok = 1;
    }
    puts(ok ? "YES" : "NO");
    return 0;
}