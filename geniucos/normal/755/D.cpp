#include<bits/stdc++.h>

using namespace std;

int N, K, aib[1000009];
long long inter;

void U (int pos, int val) {while (pos <= N) aib[pos] += val, pos += pos - (pos & (pos - 1));}
int Q (int pos) {int sum = 0; while (pos) sum += aib[pos], pos &= pos - 1; return sum;}
int Qry (int st, int dr) {return Q (dr) - Q(st - 1);}

int get_sum (int st, int dr)
{
    if (st <= dr) return Qry (st, dr);
    return Qry (st, N) + Qry (1, dr);
}

int get_val (int x, int y)
{
    int st = x - K + 1, dr = y - 1;
    if (dr < 1) dr += N;
    if (st < 1) st += N;
    return get_sum (st, dr);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K);
K = min (K, N - K);
int x = 1;
for (int i=1; i<=N; i++)
{
    int y = x + K;
    if (y > N) y -= N;
    inter += get_val (x, y);
//    printf ("%d ", inter);
    printf ("%I64d ", 2 + i + N - (N - inter) - 1);
    U (x, +1), x = y;
}
return 0;
}