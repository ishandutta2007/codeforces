#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100020
#define int long long
#pragma GCC optimize("O3")
using namespace std;

int a[N], p[N];
vector<int> e[N];
int d[N];

void DFS(int x)
{
    int i;

    for(i = 0; i < (signed)e[x].size(); i ++)
    {
        d[e[x].at(i)] = d[x] + 1;
        DFS(e[x].at(i));
    }

    return;
}

void Calc(int x)
{
    int i, k;

    if(d[x] % 2)
    {
        k = 2000000000;
        for(i = 0; i < (signed)e[x].size(); i ++)
            k = min(k, a[e[x].at(i)]);
        if(k == 2000000000)
            a[x] = a[p[x]];
        else
            a[x] = k;
    }
    for(i = 0; i < (signed)e[x].size(); i ++)
        Calc(e[x].at(i));

    return;
}

signed main(void)
{
    int n;
    int i, o;

    scanf("%I64d", &n);
    for(i = 1; i < n; i ++)
    {
        scanf("%I64d", &p[i]);
        e[-- p[i]].push_back(i);
    }
    for(i = 0; i < n; i ++)
        scanf("%I64d", &a[i]);
    DFS(0);

    for(i = 0; i < n; i ++)
        if((a[i] == -1 && d[i] % 2 == 0) || (a[i] >= 0 && d[i] % 2 == 1))
        {
            printf("-1\n");

            return 0;
        }
    Calc(0);

    // for(i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;

    for(i = o = 0; i < n; i ++)
        if(i && a[i] < a[p[i]])
        {
            printf("-1\n");

            return 0;
        }
        else
        {
            // printf("%I64d,%I64d:%I64d\n",i,p[i],a[i]-a[p[i]]);
            o += !i ? a[i] : a[i] - a[p[i]];
        }
    printf("%I64d\n", o);

    return 0;
}