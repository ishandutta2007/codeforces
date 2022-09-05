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

int Maxi, N, st[109], dr[109], A[109], B[109], C[109], beg[109];

int INF, S, D, N_flow, M, left[100009], right[100009], C_F[100009], t[100009];
vector < int > v[100009];

void add_edge (int x, int y, int cap)
{
    left[++M] = x, right[M] = y, C_F[M] = cap, v[x].push_back (M);
    left[++M] = y, right[M] = x, C_F[M] = 0, v[y].push_back (M);
}

int opus (int pos)
{
    if (pos & 1)
        return pos + 1;
    return pos - 1;
}

bool bfs ()
{
    queue < int > cc;
    for (int i=1; i<=N_flow; i++)
        t[i] = -1;
    t[S] = 0;
    cc.push (S);
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
            if (C_F[*it] > 0 && t[right[*it]] == -1)
            {
                t[right[*it]] = *it;
                if (right[*it] == D)
                    return 1;
                cc.push (right[*it]);
            }
    }
    return 0;
}

int Max_Flow ()
{
    int sol = 0;
    while (bfs ())
    {
        for (vector < int > :: iterator it = v[D].begin (); it != v[D].end (); it ++)
            if (C_F[opus(*it)] > 0 && t[right[*it]] != -1)
            {
                int mini = INF;
                t[D] = opus (*it);
                for (int i=D; i != S; i = left[t[i]])
                    if (C_F[t[i]] < mini)
                        mini = C_F[t[i]];
                sol += mini;
                for (int i=D; i != S; i = left[t[i]])
                {
                    C_F[t[i]] -= mini;
                    C_F[opus (t[i])] += mini;
                }
            }
    }
    return sol;
}

int f (int i, int x)
{
    return x * x * A[i] + x * B[i] + C[i];
}

int code (int i, int j)
{
    return j - st[i] + 1 + beg[i];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

INF = 1<<30, Maxi = -INF;
int M_init;
scanf ("%d %d", &N, &M_init);
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &A[i], &B[i], &C[i]);

N_flow = D = 2, S = 1;
for (int i=1; i<=N; i++)
{
    scanf ("%d %d", &st[i], &dr[i]);
    beg[i] = N_flow + 1;
    N_flow += dr[i] - st[i] + 2;
    for (int j=st[i]; j<=dr[i]; j++)
        if (f (i, j) > Maxi)
            Maxi = f (i, j);
}

for (int i=1; i<=N; i++)
{
    add_edge (S, beg[i], INF);
    for (int j=st[i]; j<=dr[i]; j++)
        add_edge (code (i, j - 1), code (i, j), Maxi - f (i, j));
    add_edge (code (i, dr[i]), D, INF);
}

while (M_init)
{
    M_init --;
    int l, r, d;
    scanf ("%d %d %d", &l, &r, &d);
    for (int j=st[l]; j<=dr[l]; j++)
        if (j - d >= st[r] && j - d <= dr[r] + 1)
            add_edge (code (l, j - 1), code (r, j - d - 1), INF);
}

printf ("%d\n", Maxi * N - Max_Flow ());

return 0;
}