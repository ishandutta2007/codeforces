#include<bits/stdc++.h>

using namespace std;

int N, T = 0, a[100009], dp[2][100009], v[100009], ap[100009], ans[100009];

void doDp (int lim)
{
    for (int i=1; i<=N; i++)
    {
        dp[1][i] = dp[1][i - 1];
        if (ap[a[i]] == 0)
            ap[a[i]] = 1, dp[1][i] ++;
    }
    for (int i=1; i<=N; i++)
        ap[a[i]] = 0;
    ans[dp[1][N]] = min (ans[dp[1][N]], 1);
    for (int i=2; i<=lim; i++)
    {
        int P = 1, lin = (i & 1) ^ 1, k = 0, diff = 0;
        ///k is the biggest so that dp[lin][k] <= P
        ///diff is the number of different elements [k + 1, j]
        for (int j=1; j<=N; j++)
        {
            if (ap[a[j]] == 0) v[j] = 1, ap[a[j]] = j, diff ++;
            else v[ap[a[j]]] = 0, diff += (ap[a[j]] <= k), ap[a[j]] = j, v[j] = 1;
            while (1)
            {
                while (k < j && dp[lin][k + 1] <= P)
                    k ++, diff -= v[k];
                if (diff <= P)
                {
                    dp[i & 1][j] = P;
                    break;
                }
                else P ++;
            }
        }
        ans[dp[i & 1][N]] = min (ans[dp[i & 1][N]], i);
        for (int j=1; j<=N; j++)
            v[j] = 0, ap[a[j]] = 0;
    }
}

void print ()
{
    for (int i=1; i<=N; i++)
    {
        if (i > 1 && ans[i - 1] < ans[i])
            ans[i] = ans[i - 1];
        printf ("%d ", ans[i]);
    }
    printf ("\n");
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]), ans[i] = N + 1;
while ((T + 1) * (T + 1) <= N) T ++;
doDp (N / (T + 1) + (N % (T + 1) != 0));
for (int K=1; K<=T; K++)
{
    ans[K] = 0;
    for (int i=1; i<=N; i++)
    {
        int j = i, cnt = 0;
        while (1)
        {
            if (ap[a[j]] == 0) ap[a[j]] = 1, cnt ++;
            if (cnt > K || j > N) break;
            else j ++;
        }
        for (int k=i; k<=j; k++)
            ap[a[k]] = 0;
        j --, ans[K] ++;
        i = j;
    }
}
print ();
return 0;
}