#include<bits/stdc++.h>

using namespace std;

int N, INF, V[100], K[100], lib[100], nxtLib[80], nxtK[80], nxtV[80], id[80], A[80][80][80], B[80][80][80];
char sir[109];

int calc (int i, int j, int k, int newPos)
{
    if (i - j - k > lib[0]) return INF;
    int ans = 0;
    ans = (nxtLib[newPos + 1] <= i - j - k ? i - j - k - nxtLib[newPos + 1] + 1 : 0);
    ans += (nxtV[newPos + 1] <= j ? j - nxtV[newPos + 1] + 1 : 0);
    ans += (nxtK[newPos + 1] <= k ? k - nxtK[newPos + 1] + 1 : 0);
    return ans;
}

void U (int &x, int y) {if (y < x) x = y;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N), INF = N * N * N;
gets (sir + 1);
for (int i=1; i<=N; i++)
    if (sir[i] == 'V') V[++V[0]] = i, id[i] = V[0];
    else
    if (sir[i] == 'K') K[++K[0]] = i, id[i] = K[0];
    else lib[++lib[0]] = i, id[i] = lib[0];
nxtLib[N + 1] = nxtV[N + 1] = nxtK[N + 1] = N + 1;
for (int i=N; i>=1; i--)
{
    nxtLib[i] = nxtLib[i + 1];
    nxtV[i] = nxtV[i + 1];
    nxtK[i] = nxtK[i + 1];
    if (sir[i] == 'V') nxtV[i] = id[i];
    else
    if (sir[i] == 'K') nxtK[i] = id[i];
    else nxtLib[i] = id[i];
}
for (int j=0; j<=V[0]; j++)
    for (int k=0; k<=K[0]; k++)
        A[0][j][k] = B[0][j][k] = INF;
A[0][0][0] = 0; ///A se termina in diferit de V
///B se termina fix in V
for (int i=1; i<=N; i++)
    for (int j=0; j<=V[0]; j++)
        for (int k=0; k<=K[0]; k++)
        {
            A[i][j][k] = INF;
            if (j + k < i && i - j - k <= lib[0])
                U (A[i][j][k], min (A[i - 1][j][k], B[i - 1][j][k]) + calc (i - 1, j, k, lib[i - j - k]));
            if (k > 0)
                U (A[i][j][k], A[i - 1][j][k - 1] + calc (i - 1, j, k - 1, K[k]));

            B[i][j][k] = INF;
            if (j > 0)
                U (B[i][j][k], min (A[i - 1][j - 1][k], B[i - 1][j - 1][k]) + calc (i - 1, j - 1, k, V[j]));
        }
printf ("%d\n", min (A[N][V[0]][K[0]], B[N][V[0]][K[0]]));
return 0;
}