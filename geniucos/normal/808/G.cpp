#include<bits/stdc++.h>

using namespace std;

int N, M, *dp[100009], phi[100009], nxt[100009][26];
char A[100009], B[100009];

void U (int &x, int y) {if (y > x) x = y;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s\n%s", A + 1, B + 1), N = strlen (A + 1), M = strlen (B + 1);
for (int i=1; i<=N; i++)
    if (A[i] != '?') A[i] -= 'a';
    else A[i] = -1;
for (int i=1; i<=M; i++)
    B[i] -= 'a';
int k = 0;
for (int i=2; i<=M; i++)
{
    while (k != 0 && B[k + 1] != B[i]) k = phi[k];
    k += (B[k + 1] == B[i]), phi[i] = k;
}
nxt[0][B[1]] = 1;
for (int i=1; i<=M; i++)
    for (int j=0; j<26; j++)
        if (i < M && B[i + 1] == j) nxt[i][j] = i + 1;
        else nxt[i][j] = nxt[phi[i]][j];
for (int i=0; i<=N; i++)
    dp[i] = new int[M + 1] ();
for (int i=0; i<=N; i++)
    for (int j=0; j<=M; j++)
        dp[i][j] = -2 * N;
dp[0][0] = 0;
for (int i=0; i<N; i++)
    for (int j=0; j<=M; j++)
        if (dp[i][j] >= 0)
        {
            if (A[i + 1] != -1)
            {
                int k = A[i + 1];
                U (dp[i + 1][nxt[j][k]], dp[i][j] + (nxt[j][k] == M));
            }
            else
            {
                for (int k=0; k<26; k++)
                    U (dp[i + 1][nxt[j][k]], dp[i][j] + (nxt[j][k] == M));
            }
        }
int ans = -1;
for (int j=0; j<=M; j++)
    if (dp[N][j] > ans)
        ans = dp[N][j];
printf ("%d\n", ans);
return 0;
}