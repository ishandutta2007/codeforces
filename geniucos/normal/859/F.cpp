#include<bits/stdc++.h>

using namespace std;

int N, x[400009];
long long C, s[400009], dp[400009], val[400009];
deque < int > dq;

long long query () {if (dq.empty ()) return -(1LL << 60); return val[dq.front ()];}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d", &N, &C);
for (int i=1; i<2 * N; i++)
    scanf ("%d", &x[i]), s[i] = s[i - 1] + x[i];
int j = 0;
val[0] = 0, dq.push_back (0);
for (int i=1; i<=N; i++)
{
    while (s[2 * i - 1] - s[2 * j] > C && j < i)
    {
        if (dq.front () == j) dq.pop_front ();
        j ++;
    }
    if (j > 0)
        dp[i] = dp[j - 1] + C;
    dp[i] = max (dp[i], query () + s[2 * i - 1]);
    val[i] = dp[i] - s[2 * i];
    while (!dq.empty () && val[i] > val[dq.back ()])
        dq.pop_back ();
    dq.push_back (i);
}
printf ("%I64d\n", dp[N]);
return 0;
}