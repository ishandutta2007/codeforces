#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int p1, p2, N, Qr, v[100009], c[100009];
long long max1, max2, dp[100009];

void U (int pos, long long val)
{
    if (val <= dp[pos])
        return ;
    dp[pos] = val;
    if (p1 == pos)
    {
        max1 = val;
        return;
    }
    if (val >= max1)
        max2 = max1, p2 = p1, max1 = val, p1 = pos;
    else
    if (val > max2)
        max2 = val, p2 = pos;
}

long long Q (int fara)
{
    if (p1 != fara)
        return max1;
    return max2;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &Qr);

for (int i=1; i<=N; i++)
    scanf ("%d", &v[i]);

for (int i=1; i<=N; i++)
    scanf ("%d", &c[i]);

while (Qr)
{
    Qr --;
    int A, B;
    scanf ("%d %d", &A, &B);

    max1 = 0, p1 = 0;
    for (int i=1; i<=N; i++)
        dp[i] = -100000000000000000LL;

    for (int i=1; i<=N; i++)
    {
        long long v1, v2;
        v1 = dp[c[i]] + 1LL * A * v[i];
        v2 = Q (c[i]) + 1LL * B * v[i];
        if (v1 < v2)
            v1 = v2;
        U (c[i], v1);
    }
    printf ("%I64d\n", max1);
}

return 0;
}