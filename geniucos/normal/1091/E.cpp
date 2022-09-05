/*
this problem is a pure shit
*/
#include<bits/stdc++.h>

using namespace std;

int nr, N, ans[500009], d[500009];
long long s[500009], minXi[500009], minX[500009], minY[500009], x[500009], y[500009];
const long long INF = 1LL << 50;

void buildX ()
{
    int pntr = N + 1;
    for (int k=1; k<=N; k++)
    {
        x[k] = 1LL * k * (k - 1) - s[k];
        while (pntr > 1 && d[pntr - 1] < k)
            pntr --;
        if (k + 1 < pntr)
            x[k] += 1LL * k * (pntr - k - 1);
        x[k] += s[N] - s[max (pntr - 1, k)];
        ///assuming this is the right indexing: the inserted value is to the right of k
    }
    minX[0] = INF, minXi[0] = INF;
    for (int i=1; i<=N + 1; i++)
        minX[i] = min (minX[i - 1], x[i]),
        minXi[i] = min (minXi[i - 1], x[i] + i);
}

void buildY ()
{
    int pntr = N + 1;
    for (int fakek=1; fakek<=N + 1; fakek++)
    {
        ///consider the inserted value is to the left of k, which implies we're actually woking with k - 1 of the ds
        int k = fakek - 1;
        y[fakek] = 1LL * fakek * (fakek - 1) - s[k];
        while (pntr > 1 && d[pntr - 1] < fakek)
            pntr --;
        if (k + 1 < pntr)
            y[fakek] += 1LL * fakek * (pntr - k - 1);
        y[fakek] += s[N] - s[max (pntr - 1, k)];
    }
    minY[N + 2] = INF;
    for (int i=N + 1; i>=1; i--)
        minY[i] = min (minY[i + 1], y[i]);
}

int oldL = -1, oldR = -1;
long long wrst = INF;
void increaseLR (int newL, int newR)
{
    if (newL > newR) return ;
    if (oldL == -1)
    {
        for (int i=newL; i<=newR; i++)
            wrst = min (wrst, x[i]);
    }
    else
    {
        for (int i=newL; i<oldL; i++)
            wrst = min (wrst, x[i]);
        for (int i=oldR + 1; i<=newR; i++)
            wrst = min (wrst, x[i]);
    }
    oldL = newL, oldR = newR;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &d[i]);
sort (d + 1, d + N + 1);
reverse (d + 1, d + N + 1);
for (int i=1; i<=N; i++)
    s[i] = s[i - 1] + d[i];
buildX ();
buildY ();
int pntr = 0;
for (int x=N; x>=0; x--)
    if ((s[N] + x) % 2 == 0)
    {
        while (pntr < N && d[pntr + 1] > x)
            pntr ++;
        ///I assume I'll insert x on position pntr + 1
        bool ok = 1;
        if (minXi[pntr] < 0)
            ok = 0;
        increaseLR (x + 1, pntr);
        if (wrst + x < 0)
            ok = 0;
        if (minY[pntr + 1] - x < 0)
            ok = 0;
        if (ok)
            ans[++nr] = x;
    }
for (int i=nr; i>=1; i--)
    printf ("%d%c", ans[i], " \n"[i == 1]);
if (nr == 0)
    printf ("-1\n");
return 0;
}