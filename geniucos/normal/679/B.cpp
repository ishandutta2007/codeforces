#include<bits/stdc++.h>

using namespace std;

int nr, K;
long long X, mi[30], how[30];

int solve (int val)
{
    int nr = 0;
    for (int j=10; j>=1;)
    {
        if (j * j * j <= val) val -= j * j * j, nr ++;
        else j --;
    }
    return nr;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%I64d", &X);
int ans = 1;
long long curr = 1;
int y = 1;
mi[1] = 1;
while (1)
{
    while (3LL * y * y + 3LL * y + 1 <= curr) y ++;
    curr += 1LL * y * y * y, ans ++;
//    printf ("%d - %I64d\n", ans, curr);
    mi[ans] = curr, nr = ans;
    if (curr > 1e15) break;
}
for (int i=1; i<=nr; i++)
    if (mi[i] <= X) K = i;
printf ("%d ", K);
int Nr = K;
for (int y=100000; y>=1; y--)
{
    ///(y + 1) ^ 3 > X >= y ^ 3 + mi[K - 1]
    long long st = 1LL * y * y * y + mi[K - 1], dr = 1LL * (y + 1) * (y + 1) * (y + 1);
    if (dr > X) dr = X;
    if (st <= dr)
    {
        how[K --] = y;
        X = dr - 1LL * y * y * y;
        y ++;
        if (K == 0) break;
    }
}
/*printf ("\n");
for (int i=1; i<=Nr; i++)
    printf ("%I64d ", how[i]);
printf ("\n");*/
long long fin_ans = 0;
for (int i=1; i<=Nr; i++)
    fin_ans += 1LL * how[i] * how[i] * how[i];
printf ("%I64d\n", fin_ans);

return 0;
}