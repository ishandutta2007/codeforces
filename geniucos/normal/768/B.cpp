#include<bits/stdc++.h>

using namespace std;

long long N, Left, Right, L[60];

int getVal (long long pos, int K, long long val)
{
    if (K == 0) return (int) val;
    if (pos == L[K - 1] + 1) return (int) (val % 2);
    if (pos <= L[K - 1]) return getVal (pos, K - 1, val / 2);
    return getVal (pos - L[K - 1] - 1, K - 1, val / 2);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d %I64d %I64d", &N, &Left, &Right);
L[0] = 1;
for (int i=1; i<=51; i++)
    L[i] = 2LL * L[i - 1] + 1;
//printf ("%I64d\n", L[51]);
long long aux = N;
int k = 0;
while (aux > 1) k ++, aux = aux / 2;
int ans = 0;
//for (long long pos = 1; pos <= 7; pos ++)
  //  printf ("%d\n", getVal (pos, k, N));
for (long long pos = Left; pos <= Right; pos ++)
{
    if (getVal (pos, k, N))
        ans ++;
}
printf ("%d\n", ans);
return 0;
}