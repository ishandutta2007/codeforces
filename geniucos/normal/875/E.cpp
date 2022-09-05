#include<bits/stdc++.h>

using namespace std;

int N, x[100009], mi[17][100009], ma[17][100009], lg[100009], nxt[100009];
pair < int, int > getMiMa (int i, int j)
{
    int p = lg[j - i + 1];
    return {min (mi[p][i], mi[p][j - (1 << p) + 1]), max (ma[p][i], ma[p][j - (1 << p) + 1])};
}

bool ok (int D)
{
    for (int i=1; i<=N + 2; i++)
    {
        int p = i + 1, u = N + 2, mij, ras = i;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            pair < int, int > curr = getMiMa (i, mij);
            if (x[i] - D <= curr.first && curr.second <= x[i] + D) ras = mij, p = mij + 1;
            else u = mij - 1;
        }
        nxt[i] = ras;
    }
    int lst = nxt[1];
    for (int i=1; i<=lst; i++)
        lst = max (lst, nxt[i]);
    return (lst == N + 2);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N + 2; i++)
    scanf ("%d", &x[i]), mi[0][i] = ma[0][i] = x[i];
for (int i=1; i<=N + 2; i++)
{
    lg[i] = lg[i - 1];
    if ((2 << lg[i]) <= i) lg[i] ++;
}
for (int i=1; i<=lg[N + 2]; i++)
    for (int j=1; j + (1 << i) - 1 <= N + 2; j++)
        mi[i][j] = min (mi[i - 1][j], mi[i - 1][j + (1 << (i - 1))]),
        ma[i][j] = max (ma[i - 1][j], ma[i - 1][j + (1 << (i - 1))]);
int p = 0, u = 1e9, mij, ras;
while (p <= u)
{
    mij = (p + u) >> 1;
    if (ok (mij)) ras = mij, u = mij - 1;
    else p = mij + 1;
}
printf ("%d\n", ras);
return 0;
}