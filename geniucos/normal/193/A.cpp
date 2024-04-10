#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int L, N, M, ap[59][59];
char sir[59][59];

void fill (int i, int j)
{
    if (sir[i][j] != '#' || ap[i][j])
        return ;
    ap[i][j] = 1;
    fill (i-1, j), fill (i+1, j);
    fill (i, j-1), fill (i, j+1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    gets (sir[i] + 1);

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '#')
            L ++;

if (L <= 2)
{
    printf ("-1\n");
    return 0;
}

for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    if (sir[i][j] == '#')
    {
        for (int x=1; x<=N; x++)
            for (int y=1; y<=M; y++)
                ap[x][y] = 0;
        sir[i][j] = '.';
        int comp = 0;
        for (int x=1; x<=N; x++)
            for (int y=1; y<=M; y++)
                if (sir[x][y] == '#' && ap[x][y] == 0)
                    fill (x, y), comp ++;
        if (comp >= 2)
        {
            printf ("1\n");
            return 0;
        }
        sir[i][j] = '#';
    }
printf ("2\n");

return 0;
}