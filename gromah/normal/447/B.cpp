#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5
int k, ans = 0, W[30], maxn = 0;
char s[N];

void begin()
{
    scanf("%s%d", s, &k);
    for (int i = 0; i < 26; i ++)
    {
        scanf("%d", W + i);
        maxn = max(W[i], maxn);
    }
}

void work()
{
    int len = strlen(s);
    for (int i = 0; i < len; i ++)
        ans += (i + 1) * W[s[i] - 'a'];
    for (int i = len + 1, j = 1; j <= k; i ++, j ++)
        ans += maxn * i;
}

void end()
{
    printf("%d\n", ans);
}

int main()
{
    begin();
    work();
    end();
    return 0;
}