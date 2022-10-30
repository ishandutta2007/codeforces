#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#include <utility>
#define N 120
#define M 60020
using namespace std;

char a[N];
vector<pair<int, int> > x, y;
int f[N][M];

bool CompareA(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

bool CompareB(pair<int, int> a, pair<int, int> b)
{
    return a.first + a.second > b.first + b.second;
}

int main(void)
{
    int n;
    int i, j, s, o;
    pair<int, int> v;

    scanf("%d %d", &n, &s);
    for(i = 0; i < n; i ++)
    {
        scanf("%d %d", &v.second, &v.first);
        if(v.first >= 0)
            x.push_back(v);
        else
            y.push_back(v);
    }

    sort(x.begin(), x.end(), CompareA);
    sort(y.begin(), y.end(), CompareB);
    for(i = o = 0; i < (signed)x.size(); i ++)
    {
        if(s < x[i].second)
            continue;
        s += x[i].first;
        o ++;
    }

    // printf("tot %d\n", o);
    for(i = 0; i < N; i ++)
        fill(f[i], f[i] + M, INT_MIN);
    f[0][s] = o;
    for(i = 0; i < (signed)y.size(); i ++)
        for(j = 0; j < M; j ++)
        {
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
            if(j >= y[i].second && j + y[i].first >= 0)
                f[i + 1][j + y[i].first] = max(f[i + 1][j + y[i].first], f[i][j] + 1);
        }
    printf("%d\n", *max_element(f[y.size()], f[y.size()] + M));

    return 0;
}