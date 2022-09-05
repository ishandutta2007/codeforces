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

int N, M, mini, d[6][3009], s[4], t[4], l[4];
vector < int > v[3009];
queue < int > cc;

void bfs (int nod, int bst[])
{
    for (int i=1; i<=N; i++)
        bst[i] = 100000;
    bst[nod] = 0;
    cc.push (nod);
    while (!cc.empty ())
    {
        nod = cc.front ();
        cc.pop ();
        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (bst[*it] > bst[nod] + 1)
            {
                bst[*it] = bst[nod] + 1;
                cc.push (*it);
            }
    }
}

void U (int val)
{
    if (val < mini)
        mini = val;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=M; i++)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}

scanf ("%d %d %d", &s[1], &t[1], &l[1]);
scanf ("%d %d %d", &s[2], &t[2], &l[2]);

bfs (s[1], d[1]);
bfs (s[2], d[2]);
bfs (t[1], d[3]);
bfs (t[2], d[4]);

if (d[1][t[1]] > l[1] || d[2][t[2]] > l[2])
{
    printf ("-1\n");
    return 0;
}

mini = d[1][t[1]] + d[2][t[2]];
for (int i=1; i<=N; i++)
{
    bfs (i, d[5]);
    for (int j=1; j<=N; j++)
    {
        if (d[5][j] + d[1][i] + d[3][j] <= l[1] && d[5][j] + d[2][i] + d[4][j] <= l[2])
            U (d[5][j] + d[1][i] + d[3][j] + d[2][i] + d[4][j]);
        if (d[5][j] + d[1][i] + d[3][j] <= l[1] && d[5][j] + d[4][i] + d[2][j] <= l[2])
            U (d[5][j] + d[1][i] + d[3][j] + d[4][i] + d[2][j]);
    }
}
printf ("%d\n", M - mini);

return 0;
}