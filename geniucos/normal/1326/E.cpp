#include<bits/stdc++.h>

using namespace std;

int N, s[1200009], mi[1200009], p[300009];

void rfrsh (int nod, int st, int dr, int mij, int f1, int f2)
{
    s[nod] = s[f1] + s[f2];
    mi[nod] = min (mi[f1], s[f1] + mi[f2]);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        s[nod] += val;
        mi[nod] = min (s[nod], 0);
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos, val);
    else Update (f2, mij + 1, dr, pos, val);
    rfrsh (nod, st, dr, mij, f1, f2);
}

void upd (int pos, int val)
{
    Update (1, 1, N, pos, val);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x;
    scanf ("%d", &x), p[x] = i;
}
printf ("%d", N);
int ans = N;
for (int currStep = 1; currStep < N; currStep ++)
{
    int x;
    scanf ("%d", &x);
    upd (N - x + 1, +1);
    while (1)
    {
        upd (N - p[ans] + 1, -1);
        if (mi[1] < 0)
        {
            upd (N - p[ans] + 1, +1);
            break;
        }
        ans --;
    }
    printf (" %d", ans);
}
printf ("\n");
return 0;
}