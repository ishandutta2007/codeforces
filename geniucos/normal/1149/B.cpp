#include<bits/stdc++.h>

using namespace std;

int N, Q, sz[4], dp[259][259][259], nxt[100009][26];
char s[4][1009], sir[100009];

void updateDp (int &dp, int oldDp, int c)
{
    if (oldDp <= N && nxt[oldDp + 1][c] < dp)
        dp = nxt[oldDp + 1][c];
}

void update (int i, int j, int k)
{
    assert (i + j + k > 0);
    dp[i][j][k] = N + 1;
    if (i > 0)
        updateDp (dp[i][j][k], dp[i - 1][j][k], s[1][i]);
    if (j > 0)
        updateDp (dp[i][j][k], dp[i][j - 1][k], s[2][j]);
    if (k > 0)
        updateDp (dp[i][j][k], dp[i][j][k - 1], s[3][k]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &Q);
scanf ("%s\n", sir + 1);
for (int i=1; i<=N; i++)
    sir[i] -= 'a';
for (int j=0; j<26; j++)
    nxt[N + 1][j] = N + 1;
for (int i=N; i>=1; i--)
{
    for (int j=0; j<26; j++)
        nxt[i][j] = nxt[i + 1][j];
    nxt[i][sir[i]] = i;
}
dp[0][0][0] = 0;
sz[1] = sz[2] = sz[3] = 0;
while (Q --)
{
    char type, c;
    int id;
    scanf ("%c %d", &type, &id);
    if (type == '+') scanf (" %c\n", &c);
    else scanf ("\n");
    if (type == '-') sz[id] --;
    else
    {
        s[id][++sz[id]] = c - 'a';
        int a1 = 0, b1 = sz[1], a2 = 0, b2 = sz[2], a3 = 0, b3 = sz[3];
        if (id == 1) a1 = b1;
        else
        if (id == 2) a2 = b2;
        else a3 = b3;
        for (int i=a1; i<=b1; i++)
            for (int j=a2; j<=b2; j++)
                for (int k=a3; k<=b3; k++)
                    update (i, j, k);
    }
    if (dp[sz[1]][sz[2]][sz[3]] <= N) printf ("YES\n");
    else printf ("NO\n");
}
return 0;
}