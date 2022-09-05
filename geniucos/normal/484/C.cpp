#include<bits/stdc++.h>

using namespace std;

int N, M, L, D, p[1000009], ans[1000009], aux[1000009], nxt[20][1000009], a[1000009], old[1000009], prv[1000009];
bool ap[1000009];
char sir[1000009];

void mul (int a[], int b[], int c[])
{
    for (int i=1; i<=N; i++)
        aux[i] = a[b[i]];
    for (int i=1; i<=N; i++)
        c[i] = aux[i];
}

void pow (int E)
{
    for (int i=1; i<=N; i++)
        ans[i] = i;
    for (int i=0; (1 << i) <= E; i++)
    {
        if (E & (1 << i)) mul (ans, nxt[i], ans);
        mul (nxt[i], nxt[i], nxt[i + 1]);
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++) a[i] = i;
scanf ("%d", &M);
while (M --)
{
    int L, K, nr = 0;
    scanf ("%d %d", &L, &D);
    for (int i=0; i<D; i++)
    {
        int j = i;
        while (j < L) p[j + 1] = ++nr, j += D;
    }
    ///am permutarea de lungime L
    for (int i=1; i<=N; i++)
        old[i] = a[i];
    for (int i=1; i<=L; i++)
        nxt[0][i] = p[i] - 1, prv[p[i] - 1] = i;
    for (int i=L + 1; i<=N; i++)
        nxt[0][i] = i - 1, prv[i - 1] = i;
    pow (N - L + 1);
    for (int i=1; i<=N; i++)
        if (ans[i] != 0)
            a[N - L + ans[i] + 1] = old[i];
    ///restu vin din 0
    int steps = N - L + 1, i = 0, j = 1;
    while (steps --) i = prv[i], a[j ++] = old[i];
    for (int i=1; i<=L; i++)
        prv[i] = 0;
/*    for (int i=1; i<=N; i++)
        printf ("%d", a[i]);
    printf ("\n");*/
    for (int i=1; i<=N; i++)
        printf ("%c", sir[a[i]]);
    printf ("\n");
}

return 0;
}