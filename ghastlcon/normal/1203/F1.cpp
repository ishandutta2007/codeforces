#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define N 120
using namespace std;

char a[N];
vector<pair<int, int> > x, y;

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
    int i, s;
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
    for(i = 0; i < (signed)x.size(); i ++)
    {
        if(s < x[i].second)
        {
            printf("NO\n");

            return 0;
        }
        s += x[i].first;
    }
    for(i = 0; i < (signed)y.size(); i ++)
    {
        if(s < y[i].second)
        {
            printf("NO\n");

            return 0;
        }
        s += y[i].first;
    }
    printf("%s\n", s < 0 ? "NO" : "YES");

    return 0;
}