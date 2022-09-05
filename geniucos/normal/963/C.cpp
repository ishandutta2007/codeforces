#include<bits/stdc++.h>

using namespace std;

int p, q, N;
long long **v, x[200009], y[200009], cnt[200009];

long long gcd (long long a, long long b)
{
    long long r;
    while (b)
        r = a % b,
        a = b,
        b = r;
    return a;
}

int cntDiv (long long x)
{
    int ans = 0;
    for (int i=1; 1LL * i * i <= x; i++)
        if (x % i == 0)
        {
            ans += 2;
            if (i * i == x) ans --;
        }
    return ans;
}

void printAns (int x)
{
    printf ("%d\n", x);
    exit (0);
}

map < long long, int > ln, cl;
void read ()
{
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
    {
        scanf ("%I64d %I64d %I64d", &x[i], &y[i], &cnt[i]);
        if (ln[x[i]] == 0) ln[x[i]] = ++p;
        if (cl[y[i]] == 0) cl[y[i]] = ++q;
        if (p > N || q > N) printAns (0);
    }
    if (1LL * p * q != N) printAns (0);
    v = new long long*[p + 1];
    for (int i=1; i<=p; i++)
        v[i] = new long long[q + 1];
    for (int i=1; i<=N; i++)
        x[i] = ln[x[i]], y[i] = cl[y[i]], v[x[i]][y[i]] = cnt[i];
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

read ();
for (int i=1; i<p; i++)
    for (int j=1; j<q; j++)
    {
        long long a = v[i][j], b = v[i + 1][j + 1], c = v[i][j + 1], d = v[i + 1][j];
        ///a*b=c*d
        long long r = gcd (a, c);
        a /= r, c /= r;
        r = gcd (a, d), a /= r, d /= r;
        r = gcd (b, c), b /= r, c /= r;
        r = gcd (b, d), b /= r, d /= r;
        if (a + b + c + d != 4)
            printAns (0);
    }
long long gd = 0;
for (int i=1; i<=p; i++)
    for (int j=1; j<=q; j++)
        gd = gcd (gd, v[i][j]);
printAns (cntDiv (gd));
return 0;
}