#include<bits/stdc++.h>

using namespace std;

int N;
double bst, P[20][20], dp[1 << 20][20], old[20];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
        scanf ("%lf", &P[i][j]);
///daca incep cu i si ii mai am pe aia din msk
for (int msk = 0; msk < (1 << N) - 1; msk ++)
    for (int i=0; i<N; i++)
    {
        if (msk == 0) dp[msk][i] = (i == 0);
        else
        {
            for (int j=0; j<N; j++)
                if (i != j && ((msk >> j) & 1))
                {
                    double curr = dp[msk ^ (1 << j)][i] * P[i][j] + dp[msk ^ (1 << j)][j] * P[j][i];
                    if (curr > dp[msk][i])
                        dp[msk][i] = curr;
                }
        }
    }
double ans = 0.0;
for (int i=0; i<N; i++)
    if (dp[((1 << N) - 1) ^ (1 << i)][i] > ans)
        ans = dp[((1 << N) - 1) ^ (1 << i)][i];
printf ("%.10f\n", ans);

return 0;
}