#include<bits/stdc++.h>

using namespace std;

int S, nr, mi, ma, N, K, p[1000009], sz[1000009], ap[1000009];
bool dp[1000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
for (int i=1; i<=N; i++)
    if (ap[i] == 0)
    {
        int j = i; nr ++;
        while (ap[j] == 0) ap[j] = 1, sz[nr] ++, j = p[j];
    }
for (int i=1; i<=nr; i++)
    S += sz[i] / 2;
if (S < K)
{
    int old_K = K;
    ma = 2 * S, K -= S;
    for (int i=1; i<=nr; i++)
        if ((sz[i] & 1) && K > 0) ma ++, K --;
    K = old_K;
}
else ma = 2 * K;

for (int i=1; i<=N; i++)
    ap[i] = 0;
for (int i=1; i<=nr; i++)
    ap[sz[i]] ++;
dp[0] = 1;
for (int i=1; i<=N; i++)
    if (ap[i])
    {
        for (int j=N - i; j>=0; j--)
            if (dp[j] == 1)
            {
                for (int k=1; k<=ap[i]; k++)
                    if (dp[j + i * k] == 0) dp[j + i * k] = 1;
                    else break;
            }
    }
if (dp[K] == 1) mi = K;
else mi = K + 1;
printf ("%d %d\n", mi, ma);

return 0;
}