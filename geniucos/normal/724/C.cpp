#include<bits/stdc++.h>

using namespace std;

int Step0, G, N, M, Q, ap[200009];
long long Lcm, INF = 1LL << 60;

long long solve (int A, int B)
{
    A = A % (2 * N), B = B % (2 * M);///ma asigur ca sunt resturi
    if (A == 0 && B == 0) return Lcm;
    ///X % 2N = A si X % 2M = B
    ///X = alpha * 2N + A = beta * 2M + B echivalent cu alpha * 2N - beta * 2M = B - A
    ///fac sistemul de mai sus modulo 2M si iese alpha * 2N = (B - A) % (2M), deci un alpha minim ar fi ap[(B - A) % (2M)]
    ///B - A < 2M
    int dff = (B - A) % (2 * M);
    if (dff < 0) dff += 2 * M;
    if (ap[dff] == -1) return INF;
    ///alpha = ap[(B - A) % (2 * M)] + k * Step0, cu k minim a.i. alpha * 2N >= B - A
    int C = ap[dff];
    ///(C + k*Step0) * 2N >= B - A -> k * (2N * Step0) >= B - A - 2N * C;
    long long D = 2LL * N * Step0, E = B - A - 2LL * N * C;
    ///k min a.i. k * D >= E
    long long k_min;
    for (long long i = (E / D) - 1; i <= (E / D) + 1; i++)
        if (1LL * i * D >= E)
        {
            k_min = i;
            break;
        }
    long long alpha = C + 1LL * k_min * Step0;
    return 2LL * N * alpha + A;
}

long long min4 (long long a, long long b, long long c, long long d)
{
    long long opt = a;
    if (b < opt) opt = b;
    if (c < opt) opt = c;
    if (d < opt) opt = d;
    return opt;
}

long long f (int x, int y)
{
    long long a = solve (x, y), b = solve (2 * N - x, y), c = solve (x, 2 * M - y), d = solve (2 * N - x, 2 * M - y), opt;
    return min4 (a, b, c, d);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &M, &Q), Lcm = -1LL;
for (int i=0; i<2 * M; i++)
    ap[i] = -1;///ce numar inmultesc cu 2N a.i. sa obtin i modulo 2M
for (int i=0; i<=2 * M; i++)
{
    if (ap[(2LL * i * N) % (2 * M)] == -1)
        ap[(2LL * i * N) % (2 * M)] = i;
    if (i != 0 && (2LL * i * N) % (2 * M) == 0 && Lcm == -1) Lcm = 2LL * i * N, Step0 = i;
}
G = 4LL * N * M / Lcm;
long long Stp = min4 (f (0, 0), f (N, 0), f (0, M), f (N, M));
while (Q --)
{
    int x, y;
    scanf ("%d %d", &x, &y);
    long long curr = f (x, y);
    if (curr > Stp) printf ("-1\n");
    else printf ("%I64d\n", curr);
}
return 0;
}