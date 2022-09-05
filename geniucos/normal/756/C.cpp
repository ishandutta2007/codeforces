#include<bits/stdc++.h>

using namespace std;

int Ans, N, l[280009], min_l[280009], tot_l[280009], a[100009];

void Update (int nod, int st, int dr, int pos)
{
    if (st == dr)
    {
        if (a[st] == 0)
        {
            l[nod] = 0;
            min_l[nod] = -1;
            tot_l[nod] = -1;
        }
        else
        {
            tot_l[nod] = l[nod] = 1;
            min_l[nod] = 0;
        }
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (pos <= mij) Update (f1, st, mij, pos);
    else Update (f2, mij + 1, dr, pos);
    tot_l[nod] = tot_l[f1] + tot_l[f2];
    l[nod] = max (0, l[f1] + min_l[f2]) + l[f2];
    min_l[nod] = min (min_l[f1], tot_l[f1] + min_l[f2]);
}

void getAns (int nod, int st, int dr, int L)
{
    if (st == dr)
    {
        Ans = a[st];
        return ;
    }
    int mij = (st + dr) >> 1, f1 = nod << 1, f2 = f1 | 1;
    if (L <= l[f1] + min_l[f2]) getAns (f1, st, mij, L);
    else getAns (f2, mij + 1, dr, L - max (0, l[f1] + min_l[f2]));
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int pos, tip;
    scanf ("%d %d", &pos, &tip);
    if (tip == 1) scanf ("%d", &a[pos]);
    Update (1, 1, N, pos);
    if (l[1] == 0) Ans = -1;
    else getAns (1, 1, N, l[1]);
    printf ("%d\n", Ans);
}
return 0;
}