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

int S, D, N, M, NN, t[209], F[209][209], C[209][209], sol[209][209], a[209];
vector < int > v[209];

void add_edge (int x, int y, int cap)
{
    v[x].push_back (y);
    v[y].push_back (x);
    C[x][y] = cap;
}

bool bfs ()
{
    queue < int > cc;
    for (int i=1; i<=NN; i++)
        t[i] = -1;
    cc.push (S), t[S] = 0;
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (F[nod][*it] < C[nod][*it] && t[*it] == -1)
            {
                t[*it] = nod;
                if (*it == D)
                    return 1;
                cc.push (*it);
            }
    }
    return 0;
}

int max_flow ()
{
    int sol = 0;
    while (bfs ())
    {
        for (vector < int > :: iterator it = v[D].begin (); it != v[D].end (); it ++)
            if (F[*it][D] < C[*it][D] && t[*it] != -1)
            {
                int mini = 1<<28;
                t[D] = *it;
                for (int i=D; i != S; i = t[i])
                    if (C[t[i]][i] - F[t[i]][i] < mini)
                        mini = C[t[i]][i] - F[t[i]][i];
                sol += mini;
                for (int i=D; i != S; i = t[i])
                {
                    F[t[i]][i] += mini;
                    F[i][t[i]] -= mini;
                }
            }
    }
    return sol;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
S = 1, D = NN = 2 * N + 2;
int sum1 = 0, sum2 = 0;
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai);
    a[i] = ai;
    sum1 += ai;
    add_edge (S, i + 1, ai);
}
for (int i=1; i<=N; i++)
{
    int ai;
    scanf ("%d", &ai);
    sum2 += ai;
    add_edge (i + N + 1, D, ai);
}
for (int i=1; i<=N; i++)
    add_edge (i + 1, i + N + 1, a[i]);
if (sum1 != sum2)
{
    printf ("NO\n");
    return 0;
}
while (M)
{
    M --;
    int x, y;
    scanf ("%d %d", &x, &y);
    add_edge (x + 1, y + N + 1, 1<<28);
    add_edge (y + 1, x + N + 1, 1<<28);
}
if (max_flow () != sum1)
{
    printf ("NO\n");
    return 0;
}
printf ("YES\n");

for (int i=1; i<=N; i++)
    for (int j=1; j<=N; j++)
        if (F[i+1][j+N+1] > 0)
            sol[i][j] = F[i+1][j+N+1];

for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=N; j++)
        printf ("%d ", sol[i][j]);

return 0;
}