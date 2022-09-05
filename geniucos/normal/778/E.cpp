#include<bits/stdc++.h>

using namespace std;

int cost[12], N, M, INF = 1e9 + 10, oldDp[1009], dp[1009], cif[1009][1009], cuT[1009], faraT[1009], l[1009], oldPos[1009], ap[1009][11];
char sir[1009], curr[1009];
pair < int, int > ord[1009], old[1009];

bool mtch (int i, int j)
{
    if (sir[i] == '?')
    {
        if (j == 0 && i == M) return 0;
        return 1;
    }
    return (sir[i] - '0' == j);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), M = strlen (sir + 1);
reverse (sir + 1, sir + M + 1);
scanf ("%d\n", &N);
for (int i=1; i<=N; i++)
{
    gets (curr + 1), l[i] = strlen (curr + 1);
    for (int j=1; j<=l[i]; j++)
        cif[i][j] = curr[l[i] + 1 - j] - '0';
}
for (int i=0; i<10; i++)
    scanf ("%d", &cost[i]);
for (int i=1; i<=N; i++)
{
    faraT[i] = 0;
    for (int j=M + 1; j<=l[i]; j++)
        faraT[i] += cost[cif[i][j]];
    cuT[i] = 0;
    int t = 1;
    if (l[i] >= M + 1)
    {
        for (int j=M + 1; j<=l[i]; j++)
        {
            int curr = (cif[i][j] + t) % 10;
            cuT[i] += cost[curr];
            t = (cif[i][j] + t) / 10;
        }
    }
    if (t) cuT[i] += cost[1];
}
for (int j=1; j<=N; j++)
    ord[j].first = 0, ord[j].second = j;
for (int i=0; i<=N; i++)
    dp[i] = -INF;
dp[N] = 0;///primele atatea n-au transport
for (int i=1; i<=M; i++)
{
    for (int j=1; j<=N; j++)
        old[j] = ord[j];
    int curr_nr = 0;
    for (int j=0; j<10; j++)
        for (int k=1; k<=N; k++)
            if (cif[old[k].second][i] == j)
                ord[++curr_nr] = make_pair (old[k].first + j, old[k].second);
/*    for (int j=1; j<=N; j++)
        printf ("(%d, %d) ", ord[j].first, ord[j].second);
    printf ("\n");*/
    memcpy (oldDp, dp, sizeof (dp));
    for (int j=0; j<=N; j++)
        dp[j] = -INF;
    for (int j=1; j<=N; j++)
    {
        oldPos[old[j].second] = j;
        for (int k=0; k<10; k++)
            ap[j][k] = ap[j - 1][k];
        ap[j][cif[old[j].second][i]] ++;
    }
    for (int state = 0; state <= N; state ++)
        if (oldDp[state] >= 0)
            for (int Cif = 0; Cif < 10; Cif ++)
            if (mtch (i, Cif))
            {
                int p = 1, u = N, mij, ras = 0;
                while (p <= u)
                {
                    mij = (p + u) >> 1;
                    int ind = ord[mij].second;
                    if ((oldPos[ind] > state) + Cif + cif[ind][i] < 10) ras = mij, p = mij + 1;
                    else u = mij - 1;
                }
                ///newState = ras
                int curr = oldDp[state];
                for (int k=0; k<10; k++)
                {
                    int fara = ap[state][k], cu = ap[N][k] - ap[state][k];
                    curr += cost[(k + 1 + Cif) % 10] * cu;
                    curr += cost[(k + Cif) % 10] * fara;
                    if (dp[ras] < curr) dp[ras] = curr;
                }
                //printf ("%d -> %d through %d\n", state, ras, Cif);
            }
/*    for (int j=0; j<=N; j++)
        printf ("%d ", dp[j]);
    printf ("\n\n");*/
}
///acum sunt sortate si vreau sa vad stiind care ce trasnporturi au cat mai e costu
/*for (int i=1; i<=N; i++)
    printf ("%d %d\n", faraT[i], cuT[i]);*/
int curr = 0;
for (int i=1; i<=N; i++)
    curr += faraT[i];
int ans = 0;
for (int i=N; i>=0; i--)
{
    if (curr + dp[i] > ans) ans = curr + dp[i];
    curr -= faraT[ord[i].second];
    curr += cuT[ord[i].second];
}
printf ("%d\n", ans);
return 0;
}