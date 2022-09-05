#include<bits/stdc++.h>

using namespace std;

int N, A, B;
double INF = 1 << 30, p[2017], u[2017], eps = 1e-7;

class flow_network
{
public:

    int N, M, S, D;
    int X[240009], Y[240009], C[240009], F[240009], t[120009], in_q[120009];
    double bani[240009], bell[120009];
    vector < int > v[12009];

    void add_edge (int a, int b, int cap, double ban)
    {
        X[++M] = a, Y[M] = b, C[M] = cap, bani[M] = ban, v[a].push_back (M);
        X[++M] = b, Y[M] = a, C[M] = 0, bani[M] = -ban, v[b].push_back (M);
    }

    int opus (int edge)
    {
        if (edge & 1) return edge + 1;
        return edge - 1;
    }

    bool bellman ()
    {
        queue < int > cc;
        for (int i=1; i<=N; i++)
            t[i] = -1, in_q[i] = 0, bell[i] = INF;
        cc.push (S), t[S] = 0, in_q[S] = 1, bell[S] = 0;
        while (!cc.empty ())
        {
            int nod = cc.front ();
            cc.pop ();
            in_q[nod] = 0;
            for (vector < int > :: iterator it = v[nod].begin (); it != v[nod].end (); it ++)
                if (F[*it] < C[*it] && bell[Y[*it]] > bell[nod] + bani[*it] + eps)
                {
                    bell[Y[*it]] = bell[nod] + bani[*it];
                    t[Y[*it]] = *it;
                    if (in_q[Y[*it]] == 0)
                    {
                        in_q[Y[*it]] = 1;
                        cc.push (Y[*it]);
                    }
                }
        }
        return (bell[D] != INF);
    }

    pair < int , double > Max_Flow ()
    {
        int flow = 0;
        double cost = 0;
        while (bellman ())
        {
            int mini = 1 << 25;
            for (int i=D; i != S; i = X[t[i]])
                if (C[t[i]] - F[t[i]] < mini)
                    mini = C[t[i]] - F[t[i]];
            flow += mini, cost += 1.0 * mini * bell[D];
            for (int i=D; i != S; i = X[t[i]])
                F[t[i]] += mini, F[opus (t[i])] -= mini;
        }
        return make_pair (flow, cost);
    }

    void Clear ()
    {
        for (int i=1; i<=M; i++)
            X[i] = Y[i] = C[i] = F[i] = bani[i] = 0;
        for (int i=1; i<=N; i++)
            v[i].clear (), t[i] = in_q[i] = bell[i] = 0;
        M = 0;
    }
}net;

void add_edge (int a, int b, int cap, double ban) {net.add_edge (a, b, cap, ban);}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &A, &B);
net.S = 1, net.D = 2, net.N = 4;
add_edge (1, 3, A, 0), add_edge (1, 4, B, 0);
for (int i=1; i<=N; i++)
    scanf ("%lf", &p[i]);
for (int i=1; i<=N; i++)
    scanf ("%lf", &u[i]);
for (int i=1; i<=N; i++)
{
    int x = ++net.N, y = ++net.N, z = ++net.N;
    add_edge (3, x, 1, 0), add_edge (4, y, 1, 0);
    add_edge (x, z, 1, -p[i]), add_edge (y, z, 1, -u[i]);
    add_edge (z, 2, 1, 0.0);
    add_edge (z, 2, 1, 1.0 * p[i] * u[i]);
}
printf ("%.10f\n", -net.Max_Flow ().second);
return 0;
}