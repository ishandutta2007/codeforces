#include<bits/stdc++.h>

using namespace std;

const int INF = 1 << 25;

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
                int mini = INF;
                t[D] = opus (*it);
                for (int i=D; i != S; i = X[t[i]])
                    if (C[t[i]] - F[t[i]] < mini)
                        mini = C[t[i]] - F[t[i]];
                ans += mini;
                for (int i=D; i != S; i = X[t[i]])
                    F[t[i]] += mini, F[opus (t[i])] -= mini;
            }
        }
/*        for (int i=1; i<=N; i++)
            if (t[i] != -1)
                printf ("%d ", i);
        printf ("\n");*/
        return ans;
    }
private:
    int M = 0, t[1000009], X[1000009], Y[1000009], C[1000009], F[1000009];
    vector < int > v[100009];

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

int N, H, M, code[100][100];
int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &H, &M);
net.S = 1, net.D = net.N = 2;
for (int i=1; i<=N; i++)
{
    net.add_edge (net.S, ++net.N, INF);
    int curr = net.N;
//    printf ("code for %d: %d\n", i, net.N);
    for (int j=1; j<=H; j++)
    {
        code[i][j] = ++net.N;
  //      printf ("(%d, %d) -> %d\n", i, j, code[i][j]);
        net.add_edge (curr, net.N, j * j - (j - 1) * (j - 1));
    }
}
for (int i=1; i<=M; i++)
{
    int l, r, x, c;
    scanf ("%d %d %d %d", &l, &r, &x, &c);
    net.add_edge (++net.N, net.D, c);
    for (int j=l; j<=r; j++)
        for (int k=x + 1; k<=H; k++)
            net.add_edge (code[j][k], net.N, INF);
}
printf ("%d\n", H * H * N - net.max_flow ());
return 0;
}