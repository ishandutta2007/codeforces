#include<bits/stdc++.h>

using namespace std;

int N, M, lin[2020], col[2020], minI[2020], minJ[2020], maxI[2020], maxJ[2020];
bool ap[2020][2020];
char sir[2020][2020];
queue < pair < int, int > > cc;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void fail ()
{
    printf ("-1\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
for (int i=1; i<=N; i++)
    minJ[i] = M + 1, maxJ[i] = -1;
for (int j=1; j<=M; j++)
    minI[j] = N + 1, maxI[j] = -1;
for (int i=1; i<=N; i++)
{
    scanf ("%s", sir[i] + 1);
    for (int j=1; j<=M; j++)
        if (sir[i][j] == '#')
            minI[j] = min (minI[j], i),
            minJ[i] = min (minJ[i], j),
            maxI[j] = max (maxI[j], i),
            maxJ[i] = max (maxJ[i], j);
}
for (int i=1; i<=N; i++)
    for (int j=minJ[i]; j<=maxJ[i]; j++)
        if (sir[i][j] != '#')
            fail ();
for (int j=1; j<=M; j++)
    for (int i=minI[j]; i<=maxI[j]; i++)
        if (sir[i][j] != '#')
            fail ();
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
    {
        bool canSouth = 1;
        if (sir[i][j] == '.' && (maxI[j] != -1 || maxJ[i] != -1)) canSouth = 0;
        lin[i] |= canSouth, col[j] |= canSouth;
    }
for (int i=1; i<=N; i++)
    if (!lin[i])
        fail ();
for (int j=1; j<=M; j++)
    if (!col[j])
        fail ();
int ans = 0;
for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
        if (ap[i][j] == 0 && sir[i][j] == '#')
        {
            cc.push ({i, j}), ans ++;
            while (!cc.empty ())
            {
                auto curr = cc.front ();
                cc.pop ();
                for (int k=0; k<4; k++)
                {
                    int x = curr.first + dx[k], y = curr.second + dy[k];
                    if (ap[x][y] == 0 && sir[x][y] == '#')
                        cc.push ({x, y}),
                        ap[x][y] = 1;
                }
            }
        }
printf ("%d\n", ans);
return 0;
}