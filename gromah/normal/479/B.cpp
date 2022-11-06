#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
typedef pair <Pii, int> PPi;
#define x first
#define y second
#define mp make_pair
#define N 1000 + 5

int n, k, step, A[N];
bool Done[N];
Pii Ans[N];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i);
    bool ok = 1;
    for (int i = 1; i <= k && ok; i ++)
    {
        ok = 0;
        int Max = 0, Min = 1000000, u, v;
        for (int j = 1; j <= n; j ++)
        {
            if (A[j] > Max)
                Max = A[j], u = j;
            if (A[j] < Min)
                Min = A[j], v = j;
        }
        if (Max - Min > 1)
        {
            Ans[++ step] = mp(u, v);
            A[u] --, A[v] ++;
            ok = 1;
        }
    }
    int Max = 0, Min = 1000000, u, v;
    for (int j = 1; j <= n; j ++)
    {
        if (A[j] > Max)
            Max = A[j], u = j;
        if (A[j] < Min)
            Min = A[j], v = j;
    }
    printf("%d %d\n", Max - Min, step);
    for (int i = 1; i <= step; i ++)
        printf("%d %d\n", Ans[i].x, Ans[i].y);
    return 0;
}