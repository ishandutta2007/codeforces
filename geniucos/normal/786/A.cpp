#include<bits/stdc++.h>

using namespace std;

int N, l[2], v[2][7009], dp[7009][2], alter[7009][2];
queue < pair < int, bool > > cc;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<2; i++)
{
    scanf ("%d", &l[i]);
    for (int j=1; j<=l[i]; j++)
        scanf ("%d", &v[i][j]);
}
for (int i=1; i<=N; i++)
    for (int j=0; j<2; j++)
        dp[i][j] = -1, alter[i][j] = l[j];
dp[1][0] = dp[1][1] = 0;
cc.push ({1, 0}), cc.push ({1, 1});
while (!cc.empty ())
{
    pair < int, int > curr = cc.front ();
    cc.pop ();
    int nod = curr.first, type = curr.second;
    if (dp[nod][type] == 0)
    {
        for (int j=1; j<=l[type ^ 1]; j++)
        {
            int prv = nod - v[type ^ 1][j];
            if (prv <= 0) prv += N;
            if (dp[prv][type ^ 1] == -1)
                dp[prv][type ^ 1] = 1, cc.push ({prv, type ^ 1});
        }
    }
    else
    {
        for (int j=1; j<=l[type ^ 1]; j++)
        {
            int prv = nod - v[type ^ 1][j];
            if (prv <= 0) prv += N;
            alter[prv][type ^ 1] --;
            if (alter[prv][type ^ 1] == 0 && dp[prv][type ^ 1] == -1)
                dp[prv][type ^ 1] = 0, cc.push ({prv, type ^ 1});
        }
    }
}
for (int i=0; i<2; i++, printf ("\n"))
    for (int j=2; j<=N; j++)
        if (dp[j][i] == -1) printf ("Loop ");
        else
        if (dp[j][i] == 1) printf ("Win ");
        else printf ("Lose ");
return 0;
}