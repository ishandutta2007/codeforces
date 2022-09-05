#include<bits/stdc++.h>

using namespace std;

int N, I, a[400009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &I);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
sort (a + 1, a + N + 1);
int M = (8 * I) / N;
if (M > 30) M = N;
else M = min (N, 1 << M);
int j = 0, df = 1, ans = 2 * N + 10;
a[0] = a[1] - 1;
for (int i=1; i<=N; i++)
    if (a[i] != a[i - 1])
    {
        df --;
        while (j < N && df + (a[j + 1] != a[j]) <= M)
            df += (a[j + 1] != a[j]), j ++;
        if (i - 1 + N - j < ans)
            ans = i - 1 + N - j;
    }
printf ("%d\n", ans);
return 0;
}