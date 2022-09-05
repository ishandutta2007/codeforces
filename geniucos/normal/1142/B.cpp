#include<bits/stdc++.h>

using namespace std;

int N, M, Q, prv[400009], nxt[400009], ap[400009], a[400009], p[400009], pos[400009];
vector < int > v[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &Q);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]), pos[p[i]] = i;
for (int i=1; i<=M; i++)
    scanf ("%d", &a[i]), v[a[i]].push_back (i);
for (int i=1; i<=M; i++)
{
    int q = pos[a[i]];
    if (q == 1) prv[i] = i;
    else
    if (ap[p[q - 1]] == 0) prv[i] = 0;
    else prv[i] = prv[ap[p[q - 1]]];
    ap[a[i]] = i;
}
for (int i=1; i<=N; i++)
    ap[i] = 0;
for (int i=M; i>=1; i--)
{
    int q = pos[a[i]];
    if (q == N) nxt[i] = i;
    else
    if (ap[p[q + 1]] == 0) nxt[i] = M + 1;
    else nxt[i] = nxt[ap[p[q + 1]]];
    ap[a[i]] = i;
}
for (int i=1; i<=M; i++)
    if (nxt[i] != M + 1 && a[i] != p[1])
    {
        int lin = p[pos[a[i]] - 1];
        if (v[lin].empty ()) nxt[i] = M + 1;
        else
        {
            int l = 0, r = v[lin].size () - 1, ras = -1;
            while (l <= r)
            {
                int mid = (l + r) >> 1, q = v[lin][mid];
                if (prv[q] > nxt[i]) ras = q, r = mid - 1;
                else l = mid + 1;
            }
            if (ras != -1) nxt[i] = ras;
            else nxt[i] = M + 1;
        }
    }
for (int i=M - 1; i>=1; i--)
    if (nxt[i + 1] < nxt[i])
        nxt[i] = nxt[i + 1];
while (Q --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    printf ("%d", (nxt[x] <= y));
}
printf ("\n");
return 0;
}