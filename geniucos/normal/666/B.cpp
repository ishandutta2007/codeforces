#include<bits/stdc++.h>

using namespace std;

int nr, N, M, maxi, a, b, c, d, dist[3009][3009], q[3009], bg[3009][10], nd[3009][10];
vector < int > v[3009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
}

for (int i=1; i<=N; i++)
{
    for (int j=1; j<=N; j++)
        dist[i][j] = -1;
    nr = 1, q[1] = i, dist[i][i] = 0;
    for (int j=1; j<=nr; j++)
    {
        int nod = q[j];
        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (dist[i][*it] == -1)
                dist[i][*it] = dist[i][nod] + 1, q[++nr] = *it;
    }
    for (int p=nr; p>=nr - 2 && p >= 1; p--)
        if (q[p] != i) bg[i][++bg[i][0]] = q[p];
}

for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (i != j && dist[i][j] != -1)
        {
            if (nd[j][0] <= 2) nd[j][++nd[j][0]] = i;
            else
            if (dist[i][j] > dist[nd[j][1]][j]) nd[j][3] = nd[j][2], nd[j][2] = nd[j][1], nd[j][1] = i;
            else
            if (dist[i][j] > dist[nd[j][2]][j]) nd[j][3] = nd[j][2], nd[j][2] = i;
            else
            if (dist[i][j] > dist[nd[j][3]][j]) nd[j][3] = i;
        }

for (int x2=1; x2<=N; x2++)
    for (int x3=1; x3<=N; x3++)
        if (x2 != x3 && dist[x2][x3] != -1)
        {
            for (int k=1; k<=bg[x3][0]; k++)
                for (int p=1; p<=nd[x2][0]; p++)
                {
                    int x1 = nd[x2][p], x4 = bg[x3][k];
                    if (x1 != x4 && x1 != x3 && x4 != x2 && dist[x1][x2] + dist[x2][x3] + dist[x3][x4] > maxi)
                        maxi = dist[x1][x2] + dist[x2][x3] + dist[x3][x4], a = x1, b = x2, c = x3, d = x4;
                }
        }
printf ("%d %d %d %d\n", a, b, c, d);
return 0;
}