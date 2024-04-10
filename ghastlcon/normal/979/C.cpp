#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 300020
#define int long long
using namespace std;

int x, y;
vector<int> e[N];
int s[N], f[N];

int DFS(int x, int p)
{
    int i;

    for(i = 0, s[x] = 1;i < (signed)e[x].size();i ++)
        if(e[x].at(i) != p)
        {
            f[x] |= DFS(e[x].at(i), x);
            s[x] += s[e[x].at(i)];
        }

    return f[x] |= (x == y);
}

signed main(void)
{
    int n, u, v;
    int i;

    scanf("%I64d %I64d %I64d", &n, &x, &y);
    x --;
    y --;
    for(i = 1;i < n;i ++)
    {
        scanf("%I64d %I64d", &u, &v);
        e[-- u].push_back(-- v);
        e[   v].push_back(   u);
    }

    DFS(x, x);
    for(i = u = 0;i < (signed)e[x].size();i ++)
        if(f[e[x].at(i)])
        {
            u = s[e[x].at(i)];
            break;
        }
    cout << n * (n - 1) - (n - u) * s[y] << endl;

    return 0;
}