#include<bits/stdc++.h>

using namespace std;

int x, y, N, M, K, mp[4];
char moves[109], sir[59][59];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool works (int mp[])
{
    int i = x, j = y;
    for (int currM = 1; currM<=K; currM++)
    {
        int k = mp[moves[currM]];
        i += dx[k], j += dy[k];
        if (sir[i][j] == 'E') return 1;
        if (sir[i][j] != '.') return 0;
    }
    return 0;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
{
    gets (sir[i] + 1);
    for (int j=1; j<=M; j++)
        if (sir[i][j] == 'S')
        {
            sir[i][j] = '.';
            x = i, y = j;
        }
}
gets (moves + 1), K = strlen (moves + 1);
for (int i=1; i<=K; i++)
    moves[i] -= '0';
for (int i=0; i<4; i++)
    mp[i] = i;
int ans = 0;
do {
    ans += works (mp);
}while (next_permutation (mp, mp + 4));
printf ("%d\n", ans);

return 0;
}