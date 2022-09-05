#include<bits/stdc++.h>

using namespace std;

int nr, N, M, id[409], D[409][409];
double best, bst[409], sum[409], P2[409];
vector < int > v[409], h[409][409];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    v[x].push_back (y);
    v[y].push_back (x);
}

for (int i=1; i<=N; i++)
{
    for (int j=1; j<=N; j++)
        D[i][j] = N + 3;
    D[i][i] = 0;
    queue < int > cc;
    cc.push (i);
    while (!cc.empty ())
    {
        int nod = cc.front ();
        cc.pop ();
        for (auto it = v[nod].begin (); it != v[nod].end (); it ++)
            if (D[i][*it] > D[i][nod] + 1)
            {
                D[i][*it] = D[i][nod] + 1;
                cc.push (*it);
            }
    }
    for (int j=1; j<=N; j++)
        h[i][D[i][j]].push_back (j);
}

for (int fir = 1; fir <= N; fir ++)
{
    double curr_p = 0;
    for (int d = 0; d <= N; d ++)
    if (!h[fir][d].empty ())
    {
        double curr = 1.0 / (double) (h[fir][d].size ());
        for (int i=1; i<=N; i++)
            P2[i] = 0.0;
        for (auto it = h[fir][d].begin (); it != h[fir][d].end (); it ++)
            for (auto it2 = v[*it].begin (); it2 != v[*it].end (); it2 ++)
                P2[*it2] += (double) 1.0 / (double) (v[*it].size () * h[fir][d].size ());
        nr = 0;
        for (int i=1; i<=N; i++)
            if (P2[i] > 1e-6) id[++nr] = i;
        for (int sec = 1; sec <= N; sec ++)
        {
            double curr2 = 0;
            for (int i=1; i<=nr; i++)
                if (P2[id[i]] > bst[D[sec][id[i]]])
                    curr2 += P2[id[i]] - bst[D[sec][id[i]]], bst[D[sec][id[i]]] = P2[id[i]];
            for (int i=1; i<=nr; i++)
                bst[D[sec][id[i]]] = 0.0;
            if (curr2 > curr) curr = curr2;
        }
        //printf ("(%d, %d) -> %.10f\n", fir, d, (double) curr * (double) (h[fir][d].size ()) / (double) N);
        curr_p += curr * (double) (h[fir][d].size ()) / (double) N;
    }
    if (curr_p > best)
        best = curr_p;
}
printf ("%.10f\n", best);

return 0;
}