#include<bits/stdc++.h>

using namespace std;

class flow_network
{
public:
    int N, M, S, D;
    int X[10009], Y[10009], C[10009], F[10009], t[10009];
    vector < int > v[10009];

    void add_edge (int a, int b, int cap)
    {
        X[++M] = a, Y[M] = b, C[M] = cap, v[a].push_back (M);
        X[++M] = b, Y[M] = a, C[M] = 0, v[b].push_back (M);
    }

    int opus (int edge)
    {
        if (edge & 1) return edge + 1;
        return edge - 1;
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
                if (F[*it] < C[*it] && t[Y[*it]] == -1)
                {
                    t[Y[*it]] = *it;
                    if (Y[*it] == D) return 1;
                    cc.push (Y[*it]);
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
                if (F[opus (*it)] < C[opus (*it)] && t[Y[*it]] != -1)
                {
                    int mini = 1e8 + 1000;
                    t[D] = opus (*it);
                    for (int i=D; i != S; i = X[t[i]])
                        if (C[t[i]] - F[t[i]] < mini)
                            mini = C[t[i]] - F[t[i]];
                    sol += mini;
                    for (int i=D; i != S; i = X[t[i]])
                        F[t[i]] += mini, F[opus (t[i])] -= mini;
                }
        }
        return sol;
    }

    void Clear ()
    {
        for (int i=1; i<=M; i++)
            v[i].clear (), X[i] = Y[i] = C[i] = F[i] = 0;
        for (int i=1; i<=N; i++)
            t[i] = 0;
        M = N = S = D = 0;
    }
}net;

int N, minP, p[109], l[109], c[109], id[109];
bool cr[200009];
bool ok (int level)
{
    net.Clear ();
    int maxi = 0, how = -1, sum = 0;
    net.S = 1, net.D = net.N = 2;
    for (int i=1; i<=N; i++)
        id[i] = -1;
    for (int i=1; i<=N; i++)
        if (l[i] <= level)
        {
            if (c[i] == 1)
            {
                if (p[i] > maxi) maxi = p[i], how = i;
                continue;
            }
            sum += p[i];
            if (c[i] & 1) net.add_edge (net.S, ++net.N, p[i]);
            else net.add_edge (++net.N, net.D, p[i]);
            id[i] = net.N;
        }
    if (how != -1)
        sum += maxi, id[how] = ++net.N, net.add_edge (net.S, id[how], p[how]);
    for (int i=1; i<=N; i++)
        if (id[i] != -1 && c[i] % 2 == 1)
            for (int j=1; j<=N; j++)
                if (id[j] != -1 && c[j] % 2 == 0)
                    if (cr[c[i] + c[j]] == 0)
                        net.add_edge (id[i], id[j], 1e8 + 100);
    sum -= net.Max_Flow ();
    return (sum >= minP);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &minP);
for (int i=1; i<=N; i++)
    scanf ("%d %d %d", &p[i], &c[i], &l[i]);
for (int i=2; i<=200000; i++)
    if (cr[i] == 0)
        for (int j=i + i; j<=200000; j+=i)
            cr[j] = 1;
int p = 1, u = 101, mij, ras = -1;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);

return 0;
}