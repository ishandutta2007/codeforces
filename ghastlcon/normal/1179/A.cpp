#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
#define N 100020
#pragma GCC optimize("O3")
using namespace std;

int a[N];
pair<int, int> o[N];
int q[N << 1];

int main(void)
{
    int n, m, k;
    int i, j, p;
    int l, r;
    long long x;

    scanf("%d %d", &n, &m);
    for(i = k = l = r = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        k = max(k, a[i]);
        q[r ++] = a[i];
    }

    for(i = 0; i < n; i ++)
        if(a[i] == k)
        {
            p = i;
            break;
        }
    // cout << p << endl;
    for(i = 0; i < p; i ++)
    {
        o[i] = make_pair(q[l], q[l + 1]);
        q[r ++] = min(q[l], q[l + 1]);
        q[l + 1] = max(q[l], q[l + 1]);
        l ++;
    }

    while(m --)
    {
        scanf("%I64d", &x);
        x --;
        if(x < p)
            printf("%d %d\n", o[x].first, o[x].second);
        else
        {
            printf("%d %d\n", a[p], q[(x - p) % (n - 1) + l + 1]);
        }
    }

    return 0;
}