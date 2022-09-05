#include<bits/stdc++.h>

using namespace std;

int N, Q, a[1000009], t[1000009], lev[1000009], fin[1000009];
long long sumA, maxD;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Q);
for (int i=0; i<N; i++)
    scanf ("%d", &a[i]),
    sumA += a[i];
while (Q --)
{
    scanf ("%I64d", &maxD);
    if (maxD >= sumA)
    {
        printf ("1\n");
        continue;
    }
    int j = 0, ans = N + 1;
    long long currS = 0;
    bool complete = 0;
    for (int i=0; i<N; i++)
    {
        while (currS + a[j] <= maxD)
        {
            currS += a[j], j ++;
            if (j == N)
                complete = 1, j = 0;
        }
        if (!complete) t[i] = j;
        else t[i] = -1, lev[i] = 1, fin[i] = j;
        currS -= a[i];
    }
    for (int i=N - 1; i>=0; i--)
        if (t[i] != -1)
            lev[i] = lev[t[i]] + 1, fin[i] = fin[t[i]];
    for (int i=0; i<N; i++)
        if (fin[i] >= i && lev[i] < ans)
            ans = lev[i];
    printf ("%d\n", ans);
}
return 0;
}