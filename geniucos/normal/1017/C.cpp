#include<bits/stdc++.h>

using namespace std;

int N, a[1000009];

int getLCS (int v[])
{
    int ans = 0, dp[109];
    for (int i=1; i<=N; i++)
    {
        dp[i] = 0;
        for (int j=1; j<i; j++)
            if (v[j] < v[i] && dp[j] > dp[i])
                dp[i] = dp[j];
        dp[i] ++, ans = max (ans, dp[i]);
    }
    return ans;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int mini = 2 * N + 2, how = 0;
for (int k=1; k<=N; k++)
{
    int curr = k + (N / k) + (N % k != 0);
    if (curr < mini)
        mini = curr, how = k;
}
for (int i=1; i<=how; i++)
    a[i] = N / how;
for (int j=1; j<=N % how; j++)
    a[j] ++;
int s = 0;
for (int i=1; i<=how; i++)
{
    for (int j=s + a[i]; j>s; j--)
        printf ("%d ", j);
    s += a[i];
}
printf ("\n");
/*int v[109], p[109], g[109];
for (int i=1; i<=N; i++)
    p[i] = i;
int mini = 2 * N;
do {
    for (int i=1; i<=N; i++)
        v[i] = p[i], g[i] = N + 1 - p[i];
    int curr = getLCS (v) + getLCS (g);
    if (curr < mini)
        mini = curr;
}while (next_permutation (p + 1, p + N + 1));
printf ("%d\n", mini);
for (int i=1; i<=N; i++)
    p[i] = i;
int steps = 0;
do {
    for (int i=1; i<=N; i++)
        v[i] = p[i], g[i] = N + 1 - p[i];
    int curr = getLCS (v) + getLCS (g);
    if (curr == mini)
    {
        for (int i=1; i<=N; i++)
            printf ("%d", p[i]);
        printf ("\n");
        if (++steps == 100) break;
    }
}while (next_permutation (p + 1, p + N + 1));*/
return 0;
}