#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define N 200020
using namespace std;

int a[N];
vector<int> b[N];
int c[N], d[N];

int main(void)
{
    int n, m;
    int i, j;
    long long o;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i ++)
        c[i] = d[i] = i;
    for(i = 1; i <= m; i ++)
        scanf("%d", &a[i]);
    for(i = 1, o = 0; i < m; i ++)
    {
        o += abs(a[i] - a[i + 1]);
        b[a[i]].push_back(a[i + 1]);
        b[a[i + 1]].push_back(a[i]);
    }

    printf("%I64d", o);
    for(i = 2; i <= n; i ++)
    {
        for(j = 0; j < (signed)b[c[1]].size(); j ++)
        {
            // printf("at %d : 1 connect %d\n", i, d[b[c[1]].at(j)]);
            o -= abs(1 - d[b[c[1]].at(j)]);
            swap(d[c[1]], d[c[i]]);
            o += abs(i - d[b[c[1]].at(j)]);
            swap(d[c[1]], d[c[i]]);
        }
        for(j = 0; j < (signed)b[c[i]].size(); j ++)
        {
            // printf("at %d : %d connect %d\n", i, c[i], d[b[c[i]].at(j)]);
            o -= abs(i - d[b[c[i]].at(j)]);
            swap(d[c[1]], d[c[i]]);
            o += abs(1 - d[b[c[i]].at(j)]);
            swap(d[c[1]], d[c[i]]);
        }
        swap(d[c[1]], d[c[i]]);
        swap(c[1], c[i]);
        printf(" %I64d", o);
    }
    printf("\n");

    return 0;
}