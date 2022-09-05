#include<bits/stdc++.h>

using namespace std;

int N, max_vol[200009], vol[200009], q[200009], t[200009];
bool special[200009], ap[200009];
vector < int > v[200009];
vector < pair < pair < int, int >, int > > ans;

void df1 (int nod, int tata)
{
    vol[nod] = 1;
    for (auto it : v[nod])
        if (it != tata)
            df1 (it, nod), vol[nod] += vol[it], max_vol[nod] = max (max_vol[nod], vol[it]);
}

void add (int x, int y, int z) {ans.push_back ({{x, y}, z});}

void print ()
{
    printf ("%d\n", ans.size ());
    for (auto t : ans)
        printf ("%d %d %d\n", t.first.first, t.first.second, t.second);
    exit (0);
}

void theAlgorithm ()
{
    for (int i=1; i<=N; i++)
        ap[i] = special[i];
    for (int I=1; I<=N; I++)
        if (special[I])
            for (auto J : v[I])
                if (!special[J])
                {
                    int sz = 1;
                    q[1] = J; ap[J] = 1;
                    for (int i=1; i<=sz; i++)
                        for (auto vec : v[q[i]])
                            if (ap[vec] == 0)
                                ap[vec] = 1, q[++sz] = vec, t[vec] = q[i];
                    int oldZ = J;
                    for (int i=sz; i>1; i--)
                        if (t[q[i]] != J)
                            add (I, oldZ, q[i]),
                            oldZ = q[i], add (q[i], t[q[i]], J);
                    add (I, oldZ, J);
                }
    print ();
}

void read ()
{
    scanf ("%d", &N);
    for (int i=1; i<N; i++)
    {
        int x, y;
        scanf ("%d %d", &x, &y);
        v[x].push_back (y);
        v[y].push_back (x);
    }
    df1 (1, -1);
    int CG = 1;
    for (int i=1; i<=N; i++)
    {
        max_vol[i] = max (max_vol[i], N - vol[i]);
        if (max_vol[i] < max_vol[CG])
            CG = i;
    }
    for (int i=1; i<=N; i++)
        special[i] = (max_vol[i] == max_vol[CG]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
theAlgorithm ();

return 0;
}