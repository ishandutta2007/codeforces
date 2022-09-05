#include<bits/stdc++.h>

using namespace std;

int N, p[1000009], aib[1000009];
long long v[2][1000009];

void U (int pos)
{
    while (pos <= N)
        aib[pos] ++, pos += pos - (pos & (pos - 1));
}

int Q (int pos)
{
    int sum = 0;
    while (pos)
        sum += aib[pos], pos &= pos - 1;
    return sum;
}

void shuffle (int moves)
{
    for (int i=1; i<=N; i++)
        p[i] = i;
    while (moves --)
    {
        int x = rand () % N + 1, y = rand () % N + 1;
        while (x == y)
            x = rand () % N + 1, y = rand () % N + 1;
        swap (p[x], p[y]);
    }
}

long long countInversions ()
{
    for (int i=1; i<=N; i++)
        aib[i] = 0;
    long long cnt = 0;
    for (int i=1; i<=N; i++)
    {
        cnt += i - 1 - Q (p[i]);
        U (p[i]);
    }
    return cnt;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &p[i]);
long long curr = countInversions ();
if (curr % 2 == N % 2) printf ("Petr\n");
else printf ("Um_nik\n");

/*N = 10000;
int steps = 100;
for (int i=1; i<=steps; i++)
{
    shuffle (3 * N), v[0][i] = countInversions ();
    shuffle (7 * N + 1), v[1][i] = countInversions ();
}
sort (v[0] + 1, v[0] + steps + 1);
sort (v[1] + 1, v[1] + steps + 1);
for (int i=1; i<=steps; i++)
    printf ("%I64d ", v[0][i]);
printf ("\n");
for (int i=1; i<=steps; i++)
    printf ("%I64d ", v[1][i]);
printf ("\n");*/
return 0;
}