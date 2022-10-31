#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 200020
#define int long long
#pragma GCC optimize("O3")
using namespace std;

int n, a[N];
int f[N];
char s[N];

bool Chunk(int l, int r)
{
    if(l > r)
    {
        swap(l, r);
        r --;
    }
    else
        r --;

    //printf("Check %I64d-%I64d\n",l,r);
    return f[r] - f[l - 1] == r - l + 1;
}

signed main()
{
    int x;
    int i;

    scanf("%I64d", &n);
    for(i = 1;i <= n;i ++)
        scanf("%I64d", &a[i]);

    scanf("%s", s);
    for(i = 1;i < n;i ++)
        f[i] = f[i - 1] + s[i - 1] - 48;

    for(i = 1;i <= n;i ++)
        if(a[i] != i && !Chunk(i, a[i]))
        {
            puts("NO");
            return 0;
        }
    puts("YES");

    return 0;
}