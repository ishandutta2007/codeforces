#include<bits/stdc++.h>

using namespace std;

int N, primitiveRoot, paint[100009], val[100009], p[100009];
vector < int > divisors;

int power (int a, int b, int mod)
{
    int p = 1;
    while (b)
    {
        if (b & 1) p = (1LL * p * a) % mod;
        a = (1LL * a * a) % mod, b >>= 1;
    }
    return p;
}

bool isPrimitiveRoot (int r)
{
    for (auto it : divisors)
        if (power (r, (N - 1) / it, N) == 1)
            return 0;
    return 1;
}

void findExponentPermutation (int N)
{
/*    bool ap[1009];
    for (int i=1; i<=N; i++)
        p[i] = i - 1;
    do {
        for (int i=0; i<N; i++)
            ap[i] = 0;
        int s = 0;
        bool ok = 1;
        for (int i=1; i<=N; i++)
        {
            s = (s + p[i]) % N;
            if (ap[s]) ok = 0;
            ap[s] = 1;
        }
        if (ok)
        {
            for (int i=1; i<=N; i++)
                printf ("%d ", p[i]);
            printf ("\n");
        }
    }while (next_permutation (p + 1, p + N + 1));*/
    p[1] = 0, p[N] = N - 1;
    for (int i=2, j=1; i<N - 1; i+=2, j+=2)
        p[i] = j, p[i + 1] = N - 1 - j;
/*    for (int i=1; i<=N; i++)
        printf ("%d%c", p[i], " \n"[i == N]);*/
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
if (N <= 2)
{
    printf ("YES\n1\n");
    if (N == 2) printf ("2\n");
    return 0;
}
if (N == 4)
{
    printf ("YES\n1\n3\n2\n4\n");
    return 0;
}
for (int i=2; i<N; i++)
    if (N % i == 0)
    {
        printf ("NO\n");
        return 0;
    }
for (int i=2; i<=(N - 1); i++)
    if ((N - 1) % i == 0)
        divisors.push_back (i);
while (1)
{
    primitiveRoot = 2 + rand () % (N - 2);
    if (isPrimitiveRoot (primitiveRoot)) break;
}
int curr = 1;
for (int i=0; i<N - 1; i++)
{
    paint[curr] = i, val[i] = curr;
    curr = (1LL * curr * primitiveRoot) % N;
}
findExponentPermutation (N - 1);
printf ("YES\n");
for (int i=1; i<=N - 1; i++)
    printf ("%d\n", val[p[i]]);//, curr = (1LL * curr * val[p[i]]) % N, fprintf (stderr, "%d\n", curr);
printf ("%d\n", N);
return 0;
}