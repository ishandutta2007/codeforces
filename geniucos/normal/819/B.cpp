#include<bits/stdc++.h>

using namespace std;

int N, p[1000009], ap[4000009];

int f (int x) {return ap[x + N];}
void inc (int x, int d) {ap[x + N] += d;}

long long brt = 0;
void test ()
{
    N = rand () % 100;
    for (int i=1; i<=N; i++)
        p[i] = i;
    random_shuffle (p + 1, p + N + 1);
    for (int i=1; i<=N; i++)
        p[i + N] = p[i];
    for (int i=1; i<=N; i++)
    {
        int k = 1;
        long long curr = 0;
        for (int j=i; j<=N + i - 1; j++, k ++)
        {
            int val = p[j] - k;
            if (val < 0) val = -val;
            curr += val;
        }
        if (i == 1 || curr < brt)
            brt = curr;
    }
//    printf ("%I64d\n", brt);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

srand (time (0));
//test ();
scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
long long pl = 0, mi = 0, bst;
int cntP = 0, cntM = 0;
for (int i=1; i<=N; i++)
{
    int val = p[i] - i;
    inc (val, +1);
    if (val >= 0) pl += val, cntP ++;
    else mi -= val, cntM ++;
}
bst = pl + mi;
    //printf ("%I64d %I64d\n", pl, mi);
int how = 0, currP = N, dec = 0;
for (int i=1; i<N; i++, currP --)
{
    int old = p[currP] - N;
    if (old < 0) mi += old, cntM --;
    else pl -= old, cntP --;
    inc (old + dec, -1);
    int frq = f (dec);
    dec ++;
    cntM += frq, cntP -= frq;
    mi += cntM, pl -= cntP;
    int nou = p[currP] - 1;
    if (nou < 0) mi -= nou, cntM ++;
    else pl += nou, cntP ++;
    inc (nou + dec, +1);
    if (pl + mi < bst)
        bst = pl + mi, how = i;
    //printf ("%I64d %I64d\n", pl, mi);
}
printf ("%I64d %d\n", bst, how);
return 0;
}