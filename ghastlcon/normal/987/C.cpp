#include <iostream>
#include <algorithm>
#include <cstdio>
#include <climits>
#include <vector>
#define N 3020
using namespace std;

int n;
int a[N], b[N];
vector<int> v;
int f[N];

int Lowbit(int x)
{
    return x & -x;
}

void SetFenwick(int p, int v)
{
    for(;p <= n;p += Lowbit(p))
        f[p] = min(f[p], v);

    return;
}

int MinFenwick(int p)
{
    int o;

    for(o = INT_MAX;p;p -= Lowbit(p))
        o = min(o, f[p]);

    return o;
}

int main(void)
{
    int i, j, t, o;

    scanf("%d", &n);
    for(i = 0;i < n;i ++)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(i = 0;i < n;i ++)
    {
        scanf("%d", &b[i]);
        a[i] = n - (lower_bound(v.begin(), v.end(), a[i]) - v.begin());
    }

    // for(i=0;i<n;i++)printf("%d %d\n",a[i],b[i]);
    for(i = 0, o = INT_MAX;i < n - 2;i ++)
    {
        for(j = 0;j < N;j ++)
            f[j] = INT_MAX;
        SetFenwick(a[n - 1], b[n - 1]);

        for(j = n - 2;j > i;j --)
        {
            if(a[i] > a[j])
                if((t = MinFenwick(a[j] - 1)) != INT_MAX)
                    o = min(o, b[i] + b[j] + t);
            SetFenwick(a[j], b[j]);
        }
    }
    printf("%d\n", o == INT_MAX ? -1 : o);

    return 0;
}