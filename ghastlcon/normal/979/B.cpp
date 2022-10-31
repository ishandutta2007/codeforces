#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 100020
#define int long long
using namespace std;

int k;
char s[3][N];
int f[3], g[52];

int ID(char c)
{
    return c >= 'A' && c <= 'Z' ? c - 65 : c - 97 + 26;
}

int Solve(char *s)
{
    int n;
    int i, o;

    memset(g, 0, sizeof(g));
    n = strlen(s);

    for(i = 0;i < n;i ++)
        g[ID(s[i])] ++;
    for(i = o = 0;i < 52;i ++)
    {
        if(g[i] + k <= n)
            o = max(o, g[i] + k);
        else
        {
            o = max(o, g[i] == n ? n - (k == 1) : n);
        }
    }

    return o;
}

signed main(void)
{
    int i;

    cin >> k;
    for(i = 0;i < 3;i ++)
    {
        scanf("%s", s[i]);
        f[i] = Solve(s[i]);
    }

    g[0] = f[0];
    g[1] = f[1];
    g[2] = f[2];
    sort(g, g + 3);
    if(g[2] == g[1])
    {
        puts("Draw");
        return 0;
    }

    if(f[0] > f[1] && f[0] > f[2])
        puts("Kuro");
    else if(f[1] > f[0] && f[1] > f[2])
        puts("Shiro");
    else
        puts("Katie");

    return 0;
}