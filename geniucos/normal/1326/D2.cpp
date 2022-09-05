#include<bits/stdc++.h>

using namespace std;

int N, dp[2000009];
char sir[2000009], v[2000009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests;
scanf ("%d\n", &tests);
while (tests --)
{
    scanf ("%s\n", sir + 1), N = strlen (sir + 1);
    for (int i=1; i<=2 * N - 1; i++)
        v[i] = (i % 2 ? sir[(i + 1) / 2] : '#');
    N = 2 * N - 1;
    int R = 0, P = 0;
    for (int i=1; i<=N; i++)
    {
        dp[i] = 1;
        if (R >= i)
            dp[i] = min (R - i + 1, dp[P - (i - P)]);
        while (i + dp[i] <= N && i - dp[i] >= 1 && v[i + dp[i]] == v[i - dp[i]])
            dp[i] ++;
        if (i + dp[i] - 1 > R)
            R = i + dp[i] - 1,
            P = i;
    }
    int i = 1, j = N, ans = 0, where = -1;
    while (i < j && v[i] == v[j])
        i ++, j --;
    for (int k=i; k<=j; k++)
    {
        int l = min (min (dp[k], k - i + 1), j - k + 1);
        if ((i == k - l + 1 || j == k + l - 1) && l > ans)
            ans = l, where = k;
    }
    for (int p=1; p<=N; p+=2)
        if (p < i || p > j || (where - ans + 1 <= p && p <= where + ans - 1))
            printf ("%c", v[p]);
    printf ("\n");
}
return 0;
}