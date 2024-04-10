// Codeforces Beta Round #23
// Problem C -- Oranges and Apples
#include <cstdio>
#include <algorithm>

#define N 200000

using namespace std;

int t, n, a[N], o[N], s[N];

bool cmp(int i, int j)
{
    return a[i] < a[j];
}

int main()
{
    for(scanf("%d", &t); t; -- t)
    {
        scanf("%d", &n);
        n = 2 * n - 1;
        for(int i = 0; i != n; ++ i)
        {
            scanf("%d%d", a + i, o + i);
            s[i] = i;
        }
        sort(s, s + n, cmp);
        long long c[2];
        c[0] = c[1] = 0;
        for(int i = 0; i != n; ++ i)
            c[i & 1] += o[s[i]];
        int t = c[0] < c[1];
        printf("YES\n");
        for(int i = 0; i != n; ++ i)
            if((i & 1) == t)
                printf("%d ", s[i] + 1);
        if(t)
            printf("%d ", s[n - 1] + 1);
        printf("\n");
    }
    return 0;
}