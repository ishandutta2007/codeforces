#include<bits/stdc++.h>

using namespace std;

int R, C, N, M, codeX[209], codeY[209], ap[209][209], a1[209], b1[209], a2[209], b2[209], rowCost[209], columnCost[209];

void setEdge (int i, int j) {ap[i][j] = 1;}

void readAndBuildGraph ()
{
    vector < int > vx, vy;
    scanf ("%d %d", &N, &M);
    if (M == 0)
    {
        printf ("0\n");
        exit (0);
    }
    for (int i=1; i<=M; i++)
    {
        scanf ("%d %d %d %d", &a1[i], &b1[i], &a2[i], &b2[i]);
        vx.push_back (a1[i]), vx.push_back (a2[i] + 1);
        vy.push_back (b1[i]), vy.push_back (b2[i] + 1);
    }
    sort (vx.begin (), vx.end ()), vx.erase (unique (vx.begin (), vx.end ()), vx.end ()), R = vx.size () - 1;
    sort (vy.begin (), vy.end ()), vy.erase (unique (vy.begin (), vy.end ()), vy.end ()), C = vy.size () - 1;
    for (int i=0; i<R; i++)
        rowCost[i + 1] = vx[i + 1] - vx[i];
    for (int i=0; i<C; i++)
        columnCost[i + 1] = vy[i + 1] - vy[i];
    for (int i=1; i<=M; i++)
        for (int j=0; j<R; j++)
            if (a1[i] <= vx[j] && vx[j + 1] <= a2[i] + 1)
                for (int k=0; k<C; k++)
                    if (b1[i] <= vy[k] && vy[k + 1] <= b2[i] + 1)
                        setEdge (j + 1, k + 1);
}


class graph
{
public:
    int N, S, D;
    void add_edge (int x, int y, int c)
    {
        X[++M] = x, Y[M] = y, C[M] = c, v[x].push_back (M);
        X[++M] = y, Y[M] = x, C[M] = 0, v[y].push_back (M);
    }

    int max_flow ()
    {
        int ans = 0;
        while (bfs ())
        {
            for (vector < int > :: iterator it = v[D].begin (); it != v[D].end (); it ++)
            if (t[Y[*it]] != -1 && F[opus (*it)] < C[opus (*it)])
            {
                int mini = 1e9;
                t[D] = opus (*it);
                for (int i=D; i != S; i = X[t[i]])
                    if (C[t[i]] - F[t[i]] < mini)
                        mini = C[t[i]] - F[t[i]];
                ans += mini;
                for (int i=D; i != S; i = X[t[i]])
                    F[t[i]] += mini, F[opus (t[i])] -= mini;
            }
        }
        return ans;
    }
private:
    int M = 0, t[400009], X[400009], Y[400009], C[400009], F[400009];
    vector < int > v[2019];

    int opus (int M)
    {
        if (M & 1) return M + 1;
        return M - 1;
    }

    bool bfs ()
    {
        queue < int > cc;
        for (int i=1; i<=N; i++)
            t[i] = -1;
        cc.push (S), t[S] = 0;
        while (!cc.empty ())
        {
            int nod = cc.front ();
            cc.pop ();
            for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
                if (t[Y[*it]] == -1 && C[*it] > F[*it])
                {
                    cc.push (Y[*it]), t[Y[*it]] = *it;
                    if (Y[*it] == D) return 1;
                }
        }
        return 0;
    }
}net;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

readAndBuildGraph ();
/*for (int i=1; i<=R; i++)
    printf ("row(%d) = %d\n", i, rowCost[i]);
for (int i=1; i<=C; i++)
    printf ("column(%d) = %d\n", i, columnCost[i]);
for (int i=1; i<=R; i++)
    for (int j=1; j<=C; j++)
        if (ap[i][j])
            printf ("%d %d\n", i, j);*/
net.N = R + C + 2, net.S = 1, net.D = 2;
for (int i=1; i<=R; i++)
    codeX[i] = ++net.N, net.add_edge (net.S, codeX[i], rowCost[i]);
for (int i=1; i<=C;i ++)
    codeY[i] = ++net.N, net.add_edge (codeY[i], net.D, columnCost[i]);
for (int i=1; i<=R; i++)
    for (int j=1; j<=C; j++)
        if (ap[i][j])
            net.add_edge (codeX[i], codeY[j], 1e9);
printf ("%d\n", net.max_flow ());
return 0;
}