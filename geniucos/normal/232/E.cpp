#include<bits/stdc++.h>

using namespace std;

int nr, nr2, N, M, Q, beg[502][502], id[502][502];
char sir[509][509];

bitset < 502 > dp[2300000];
int code (int st, int dr, int i, int j) {return beg[st][dr] + (i - 1) * (dr - st + 1) + j - st + 1;}

void Build (int st, int dr)
{
    if (st >= dr) return ;
    beg[st][dr] = nr;
    ///now I'm working with (1, st) (N, dr) subrectangle so a position (x, y) will be encode as
    ///nr + (i - 1) * (dr - st + 1) + j - st + 1
    int mij = (st + dr) / 2;
    ///dp for the coloumn itself so that it can be relevant in the reccurence for the right
    for (int i=1; i<=N; i++)
        if (sir[i][mij] == '.')
        {
            for (int j=i; j>=1; j--)
            {
                if (sir[j][mij] != '.') break;
                dp[code (st, dr, i, mij)][j] = 1;
            }
        }
    ///dp for right part
    for (int j=mij + 1; j<=dr; j++)
        for (int i=1; i<=N; i++)
            if (sir[i][j] == '.')
            {
                dp[code (st, dr, i, j)] = dp[code (st, dr, i, j - 1)];
                if (i > 1) dp[code (st, dr, i, j)] |= dp[code (st, dr, i - 1, j)];
            }
    ///dp for the coloumn itself so that it can be relevant in the reccurence for the left part
    for (int i=1; i<=N; i++)
        if (sir[i][mij] == '.')
        {
            dp[code (st, dr, i, mij)].reset ();
            for (int j=i; j<=N; j++)
            {
                if (sir[j][mij] != '.') break;
                dp[code (st, dr, i, mij)][j] = 1;
            }
        }
    ///dp for left part
    for (int j=mij - 1; j>=st; j--)
        for (int i=N; i>=1; i--)
            if (sir[i][j] == '.')
            {
                dp[code (st, dr, i, j)] = dp[code (st, dr, i, j + 1)];
                if (i < N) dp[code (st, dr, i, j)] |= dp[code (st, dr, i + 1, j)];
            }
    nr += (dr - st + 1) * N;
    Build (st, mij - 1);
    Build (mij + 1, dr);
}

bool query (int st, int dr, int a1, int b1, int a2, int b2)
{
    if (b1 == b2)
    {
        if (a1 > a2 || sir[a1][b1] != '.' || sir[a2][b2] != '.' || id[a1][b1] != id[a2][b2]) return 0;
        return 1;
    }
    int mij = (st + dr) >> 1;
    if (b1 <= mij && mij <= b2)
    {
        if (mij < b2) return (dp[code (st, dr, a1, b1)] & dp[code (st, dr, a2, b2)]).any ();
        else return dp[code (st, dr, a1, b1)][a2];
    }
    if (b2 < mij) return query (st, mij - 1, a1, b1, a2, b2);
    return query (mij + 1, dr, a1, b1, a2, b2);
}

/*void PrintDp ()
{
    for (int i=1; i<=nr; i++, printf ("\n"))
        for (int j=1; j<=N; j++)
            if (dp[i][j]) printf ("1");
            else printf ("0");
}*/

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);
Build (1, M);
/*PrintDp ();
return 0;*/
for (int j=1; j<=M; j++)
    for (int i=1; i<=N; i++)
        if (sir[i][j] == '.')
        {
            if (sir[i - 1][j] == '.') id[i][j] = id[i - 1][j];
            else id[i][j] = ++nr2;
        }
scanf ("%d", &Q);
while (Q --)
{
    int a1, b1, a2, b2;
    scanf ("%d %d %d %d", &a1, &b1, &a2, &b2);
    if (query (1, M, a1, b1, a2, b2)) printf ("Yes\n");
    else printf ("No\n");
}
return 0;
}