#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
#define N 200020
using namespace std;

pair<int, int> a[N];
priority_queue<int> f;

int main(void)
{
    int n;
    int i, j, k;
    long long o, s;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i].first );
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i].second);
    a[n].first = 2000000000;
    sort(a, a + n);

    for(i = o = s = 0; i < n; i = j)
    {
        for(j = i; j < n && a[j].first == a[i].first; j ++)
        {
            s += a[j].second;
            f.push(a[j].second);
        }
        for(k = 0; k < a[j].first - a[i].first && !f.empty(); k ++)
        {
            s -= f.top();
            o += s;
            f.pop();
        }
    }
    printf("%I64d\n", o);

    return 0;
}