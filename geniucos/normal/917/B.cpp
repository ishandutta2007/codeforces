#include<bits/stdc++.h>

using namespace std;

int N, M, dp[109][109][26];
vector < pair < int, char > > v[109];

void solve (int i, int j, int k)
{
    if (dp[i][j][k] != -1) return ;
    dp[i][j][k] = 0;
//    if (i == 4 && j == 4 && k == 1)
  //      i = 4;
    for (auto e : v[i])
        if (e.second >= k)
        {
            solve (j, e.first, e.second);
            if (dp[j][e.first][e.second] == 0)
            {
                dp[i][j][k] = 1;
                break;
            }
        }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    char c;
    scanf ("%d %d %c\n", &x, &y, &c), c -= 'a';
    v[x].push_back ({y, c});
}
for (int k=25; k>=0; k--)
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            dp[i][j][k] = -1;
for (int k=25; k>=0; k--)
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            solve (i, j, k);
for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=N; j++)
    {
        bool win = 0;
        for (auto e : v[i])
            if (dp[j][e.first][e.second] == 0)
            {
                win = 1;
                break;
            }
        if (win) printf ("A");
        else printf ("B");
    }
return 0;
}