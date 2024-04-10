#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <functional>
#define N 1020
using namespace std;

int a[N], b[N], c[N];
bool o[N][N];
vector<vector<bool> > v;

int Compare(int x, int y)
{
    return a[x] > a[y];
}

int main(void)
{
    int n, m;
    int i, j;

    scanf("%d", &n);
    m = n + 1;
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        b[i] = i;
    }
    sort(b, b + n, Compare);
    for(i = 0; i < n; i ++)
        c[b[i]] = i;
    sort(a, a + n, greater<int>());
    for(i = 0; i < n; i ++)
        for(j = 0; j < a[i]; j ++)
            o[(i + j) % m][i] = true;

    for(i = 0; i < n + 1; i ++)
    {
        for(j = 0; j < n; j ++)
            if(o[i][j])
                break;
        if(j != n)
        {
            v.push_back(vector<bool>());
            for(j = 0; j < n; j ++)
                v.back().push_back(o[i][j]);
        }
    }
    printf("%d\n", (signed)v.size());
    for(i = 0; i < (signed)v.size(); i ++)
    {
        for(j = 0; j < n; j ++)
            printf("%d", (int)v[i][c[j]]);
        printf("\n");
    }

    return 0;
}