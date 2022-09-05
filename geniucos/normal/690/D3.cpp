#include<bits/stdc++.h>

using namespace std;

int C, W, H, mod, put[209], dp2[1009];

int getDp (int i)
{
    return dp2[i % (W + 2)];
}

void FixDp (int i, int val)
{
    if (val >= mod) val -= mod;
    dp2[i % (W + 2)] = val;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &C, &W, &H), mod = 1e6 + 3;
put[0] = 1;
for (int i=1; i<=W + 1; i++)
    put[i] = (1LL * put[i - 1] * H) % mod;
FixDp (0, 1);
int curr = 0;
for (int i=1; i<=C; i++)
{
    FixDp (i, getDp (i - 1) + curr);

    curr += getDp (i - 1);
    if (curr >= mod) curr -= mod;
    curr = (1LL * curr * H) % mod;
    if (i >= W + 1)
    {
        curr = ((long long) curr - 1LL * put[W + 1] * getDp (i - W - 1)) % mod;
        if (curr < 0) curr += mod;
    }
}
int ans = getDp (C) + curr;
if (ans >= mod) ans -= mod;
printf ("%d\n", ans);
return 0;
}