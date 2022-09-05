#include<bits/stdc++.h>

using namespace std;

int N, dp[300009], a[2][300009], nxt[3][300009];
long long s[3][300009];
map < long long, int > mp;
vector < pair < pair < int, int >, int > > *nonZero;

void Read ()
{
    scanf ("%d", &N);
    for (int i=0; i<2; i++)
        for (int j=1; j<=N; j++)
            scanf ("%d", &a[i][j]);
    for (int j=1; j<=N; j++)
        s[0][j] = s[0][j - 1] + a[0][j],
        s[1][j] = s[1][j - 1] + a[1][j],
        s[2][j] = s[2][j - 1] + a[0][j] + a[1][j];
    nonZero = new vector < pair < pair < int, int >, int > > [N + 1];
}

void buildNext ()
{
    for (int i=0; i<3; i++)
    {
        mp.clear ();
        for (int j=N; j>=1; j--)
        {
            mp[s[i][j]] = j;
            if (mp.count (s[i][j - 1])) nxt[i][j] = mp[s[i][j - 1]];
        }
    }
}

void update (int i, int j, int curr)
{
    int k = max (i, j), p = min (i, j);
    if (dp[k] < curr) dp[k] = curr;
    nonZero[p].push_back ({{i, j}, curr});
}

void goFurther (int i, int j, int curr)
{
    if (i < N)
    {
        update (i + 1, j, curr);
        if (nxt[0][i + 1] != 0)
            update (nxt[0][i + 1], j, curr + 1);
    }
    if (j < N)
    {
        update (i, j + 1, curr);
        if (nxt[1][j + 1] != 0)
            update (i, nxt[1][j + 1], curr + 1);
    }
    if (i == j && i < N && nxt[2][i + 1] != 0)
        update (nxt[2][i + 1], nxt[2][i + 1], curr + 1);
}

void doDp ()
{
    for (int i=0; i<N; i++)
    {
        goFurther (i, i, dp[i]);
        int lowUp = -1, lowDown = -1;
        for (auto it = nonZero[i].begin (); it != nonZero[i].end (); it ++)
            if (it->second == dp[i] + 1)
            {
                int k = it->first.first, p = it->first.second;
                if (p == i && (lowUp == -1 || lowUp > k))
                    lowUp = k;
                if (k == i && (lowDown == -1 || lowDown > p))
                    lowDown = p;
            }
        if (lowUp != -1)
            goFurther (lowUp, i, dp[i] + 1);
        if (lowDown != -1)
            goFurther (i, lowDown, dp[i] + 1);
    }
    printf ("%d\n", dp[N]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();
buildNext ();
doDp ();

return 0;
}