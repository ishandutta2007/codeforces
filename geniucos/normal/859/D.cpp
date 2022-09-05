#include<bits/stdc++.h>

using namespace std;

int N, M, pp[100][100];
double dp[400][100], win[400][100], P[100][100];

void build (int nod, int st, int dr, int pr)
{
    if (st == dr)
    {
        for (int i=1; i<=M; i++)
            win[nod][i] = 1.0 * (i == st);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    build (f1, st, mij, pr / 2);
    build (f2, mij + 1, dr, pr / 2);
    for (int j=st; j<=mij; j++)
        for (int k=mij + 1; k<=dr; k++)
            win[nod][j] += 1.0 * P[j][k] * win[f1][j] * win[f2][k],
            win[nod][k] += 1.0 * P[k][j] * win[f1][j] * win[f2][k];
    for (int i=st; i<=dr; i++)
    {
        if (i <= mij)
        {
            for (int j=mij + 1; j<=dr; j++)
            {
                double curr = win[nod][i] * pr + dp[f1][i] + dp[f2][j];
                if (curr > dp[nod][i])
                    dp[nod][i] = curr;
            }
        }
        else
        {
            for (int j=st; j<=mij; j++)
            {
                double curr = win[nod][i] * pr + dp[f1][j] + dp[f2][i];
                if (curr > dp[nod][i])
                    dp[nod][i] = curr;
            }
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), M = 1 << N;
for (int i=1; i<=M; i++)
    for (int j=1; j<=M; j++)
        scanf ("%d", &pp[i][j]), P[i][j] = (double) pp[i][j] / 100.0;
build (1, 1, M, M / 2);
double maxi = 0;
for (int i=1; i<=M; i++)
    if (dp[1][i] > maxi)
        maxi = dp[1][i];
printf ("%.10f\n", maxi);
return 0;
}