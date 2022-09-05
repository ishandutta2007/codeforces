#include<iomanip>
#include<iostream>
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

int lst, P1, N, M, K, a[250009], b[250009], c[250009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &K), M = N + 50;
for (int i=0; i<=N; i++)
    scanf ("%d", &a[i]), b[i] = a[i];
for (int i=0; i<=M; i++)
    a[i + 1] += a[i] / 2, a[i] %= 2;
for (int i=0; i<=M; i++)
    a[i] = -a[i];
for (int i=0; i<=M; i++)
    if (a[i] != 0)
    {
        P1 = i;
        break;
    }
for (int i=M; i>=0; i--)
    if (a[i] != 0)
    {
        lst = i;
        break;
    }
for (int i=P1; i<=lst; i++)
    c[i - P1] = a[i];
M = lst - P1;
for (int i=M; i>=36; i--)
    if (c[i] != 0)
    {
        if (c[i - 1] + c[i] != 0)
        {
            printf ("0\n");
            return 0;
        }
        c[i - 1] += 2 * c[i], c[i] = 0;
    }
long long curr = 1, cof = 0;
for (int i=0; i<=36 && i<=M; i++)
{
    cof += c[i] * curr;
    curr += curr;
}
int i = P1, sol = 0;
while (1)
{
    if (cof + b[i] <= K && cof + b[i] >= -K && (cof + b[i] != 0 || i != N) && i <= N)
    {
        sol ++;
//        printf ("%d -> %I64d\n", i, cof + b[i]);
    }
    i --, cof += cof;
    if (cof >= 8LL * K || cof <= -8LL * K) break;
    if (i < 0) break;
}
printf ("%d\n", sol);
return 0;
}