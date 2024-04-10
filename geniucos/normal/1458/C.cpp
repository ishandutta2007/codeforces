#include<bits/stdc++.h>

using namespace std;

const int maxN = 1009, maxM = 1e6;
int N, M, a[maxN][maxN], b[maxN][maxN];
char s[maxM];

void print (int N, int a[][maxN], string s)
{
    for (int i=0; i<N; i++, printf ("\n"))
        for (int j=0; j<N; j++)
            printf ("%d ", a[i][j]);
    printf ("%s", s.c_str ());
}

void performR (int a[][maxN])
{
    int aux[N];
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            aux[a[i][j]] = j;
        for (int j=0; j<N; j++)
            a[i][j] = aux[j];
    }
    //printf ("+R -> \n"), print (N, a, "\n");
}

void performC (int a[][maxN])
{
    int aux[N];
    for (int j=0; j<N; j++)
    {
        for (int i=0; i<N; i++)
            aux[a[i][j]] = i;
        for (int i=0; i<N; i++)
            a[i][j] = aux[i];
    }
    //printf ("+C -> \n"), print (N, a, "\n");
}

int nr, stk[100];
void add (int type) ///type = 1 is for R
{
    if (nr > 0 && stk[nr] == type)
        nr --;
    else
    if (nr == 3)
        nr = 2, stk[1] ^= 1, stk[2] ^= 1;
    else
        stk[++nr] = type;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            scanf ("%d", &a[i][j]), a[i][j] --, b[i][j] = a[i][j];
    scanf ("\n%s", s);
    /*performR (a);
    performC (a);
    performR (a);
    performC (a);

    performC (b);
    performR (b);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            assert (a[i][j] == b[i][j]);*/
    nr = 0;
    int dx = 0, dy = 0, dz = 0;
    for (int pos = 0; pos < M; pos ++)
    {
        ///a[i][j] = initA[i + dx][j + dy] + dz
        if (s[pos] == 'R') dy = (dy + N - 1) % N;
        else
        if (s[pos] == 'L') dy = (dy + 1) % N;
        else
        if (s[pos] == 'D') dx = (dx + N - 1) % N;
        else
        if (s[pos] == 'U') dx = (dx + 1) % N;
        else
        if (s[pos] == 'I')
        {
            ///row
            add (1);
            swap (dy, dz);
            dy = (N - dy) % N;
            dz = (N - dz) % N;
        }
        else
        {
            assert (s[pos] == 'C');
            ///col
            add (0);
            swap (dx, dz);
            dx = (N - dx) % N;
            dz = (N - dz) % N;
        }
    }
    for (int i=1; i<=nr; i++)
        if (stk[i]) performR (a);
        else performC (a);
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            b[i][j] = (a[(i + dx) % N][(j + dy) % N] + dz) % N + 1;
    print (N, b, "");
}
return 0;
}