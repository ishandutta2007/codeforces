#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, A[N], Ord[N];

inline bool cmp(int u, int v)
{
    return A[u] < A[v];
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        Ord[i] = i;
        scanf("%d", A + i);
    }
    sort(Ord + 1, Ord + n + 1, cmp);
    int cnt = 1, ans = 1;
    for (int i = 1; i <= n + 1 && ans < 3; i ++)
        if (A[Ord[i]] != A[Ord[i - 1]])
            ans *= cnt, cnt = 1;
        else cnt ++;
    if (ans < 3) puts("NO");
    else
    {
        puts("YES");
        for (int i = 1; i <= n; i ++)
            printf("%d%c", Ord[i], i == n ? '\n' : ' ');
        cnt = 2;
        for (int i = 2; i <= n && cnt; i ++)
            if (A[Ord[i]] == A[Ord[i - 1]])
            {
                cnt --;
                for (int j = 1; j < i - 1; j ++)
                    printf("%d ", Ord[j]);
                printf("%d %d ", Ord[i], Ord[i - 1]);
                for (int j = i + 1; j <= n; j ++)
                    printf("%d ", Ord[j]);
                printf("\n");
            }
    }
    return 0;
}