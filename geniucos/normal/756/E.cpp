#include<bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7, lim = 300000, N, aux[300009], rap[300009], cnt[300009], a[300009], b[300009], dp[6000009], old[6000009], maxP[300009];
int sz = 9, base = 1e9;
struct mare
{
    int v[1309];
    mare ()
    {
        memset (v, 0, sizeof (v));
    }

    int get_val ()
    {
        int val = 0;
        for (int i=v[0]; i>=1; i--)
        {
            if (1LL * val * base + v[i] > 2 * lim) return 2 * lim + 1;
            val = val * base + v[i];
        }
        return val;
    }

    void Read ()
    {
        char sir[10009];
        gets (sir + 1);
        int L = strlen (sir + 1);
        while (L)
        {
            int l2 = min (L, sz);
            v[++v[0]] = 0;
            for (int j=L - l2 + 1; j<=L; j++)
                v[v[0]] = v[v[0]] * 10 + sir[j] - '0';
            L -= l2;
        }
    }

    int operator % (int val)
    {
        int p = 0;
        for (int i=v[0]; i>=1; i--)
            p = ((long long)1LL * p * base + v[i]) % val;
        return p;
    }

    mare operator / (int val)
    {
        mare ans;
        long long t = 0;
        ans.v[0] = v[0];
        for (int i=v[0]; i>=1; i--)
        {
            t = (long long) 1LL * t * base + v[i];
            ans.v[i] = t / val;
            t %= val;
        }
        while (ans.v[ans.v[0]] == 0 && ans.v[0]) ans.v[0] --;
        return ans;
    }

    bool not0 ()
    {
        if (v[0] == 0 || (v[0] == 1 && v[1] == 0)) return 0;
        return 1;
    }
}totu;

void ReadAndPartition ()
{
    scanf ("%d", &N);
    for (int i=1; i<N; i++)
        scanf ("%d", &rap[i]);
    for (int i=1; i<=N; i++)
        scanf ("%d", &b[i]);
    scanf ("\n");
    totu.Read ();
    for (int i=1; i<=N; i++)
    if (i == N || rap[i] != 1)
    {
        if (i == N)
        {
            a[i] = totu.get_val ();
            break;
        }
        a[i] = totu % rap[i];
        totu = totu / rap[i];
    }
    //if (N == 300000) exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);
ReadAndPartition ();
for (int i=1; i<=N; i++)
    aux[i] = b[i];
for (int i=2; i<=N; i++)
{
    aux[i] += aux[i - 1] / rap[i - 1];
    maxP[i] = aux[i];
}
for (int i=N; i>=1; i--)
{
    int curr = 1;
    for (int j=i - 1; j>=1; j--)
    {
        if (1LL * curr * rap[j] > lim) break;
        curr *= rap[j], maxP[i] += b[j] / curr;
    }
}
for (int i=1; i<=N; i++)
    if (a[i] > b[i] + maxP[i])
    {
        printf ("0\n");
        return 0;
    }
dp[a[N]] = 1, rap[0] = 1;
for (int i=N; i>=1; i--)
{
/*    for (int j=0; j<=b[i] + maxP[i]; j++)
        printf ("%d ", dp[j]);
    printf ("\n");*/
    for (int j=0; j<=b[i] + maxP[i]; j++)
        old[j] = dp[j], dp[j] = 0;
    for (int j=0; j<=b[i - 1] + maxP[i - 1]; j++)
        dp[j] = 0;
    for (int j=0; j<=b[i] + maxP[i]; j++)
        if (old[j] > 0)
        {
            int st, dr;
            st = max (0, j - b[i]);
            dr = min (j, (b[i - 1] + maxP[i - 1] - a[i - 1]) / rap[i - 1]);
            if (st > dr) continue;
            st *= rap[i - 1], dr *= rap[i - 1];
            st += a[i - 1], dr += a[i - 1];
            ///
            if (st <= b[i - 1] + maxP[i - 1])
            {
                dp[st] += old[j];
                if (dp[st] >= mod) dp[st] -= mod;
            }
            if (dr + rap[i - 1] <= b[i - 1] + maxP[i - 1])
            {
                dp[dr + rap[i - 1]] -= old[j];
                if (dp[dr + rap[i - 1]] < 0) dp[dr + rap[i - 1]] += mod;
            }
        }
    for (int j=rap[i - 1]; j<=b[i - 1] + maxP[i - 1]; j++)
    {
        dp[j] += dp[j - rap[i - 1]];
        if (dp[j] >= mod) dp[j] -= mod;
    }
}
printf ("%d\n", dp[0]);
return 0;
}