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

int sol, N, a[109], ap[109], deja[109], v[109], h[109];
long long dp[59], A;

void back (int pos)
{
    if (pos == N + 1)
    {
        if (a[1] == 1 && a[2] == 2 && a[3] == 4 && a[4] == 3)
            a[1] = 1;
        for (int i=1; i<=N; i++)
            deja[i] = 0;
        int M = 0, nr;
        for (int i=N; i>=1; i--)
            if (deja[i] == 0)
            {
                int aux = i;
                nr = 0;
                v[++nr] = aux;
                deja[i] = 1;
                while (1)
                {
                    aux = a[aux];
                    if (deja[aux])
                        break;
                    v[++nr] = aux;
                    deja[aux] = 1;
                }
                for (int j=nr; j>=1; j--)
                    h[++M] = v[j];
            }
        bool ok = 1;
        for (int i=1; i<=N; i++)
            if (h[N + 1 - i] != a[i])
                ok = 0;
        if (ok)
        {
            for (int i=1; i<=N; i++)
                printf ("%d ", a[i]);
            printf ("\n");
        }
        return ;
    }
    for (int i=1; i<=N; i++)
        if (ap[i] == 0)
            a[pos] = i, ap[i] = pos, back (pos + 1), ap[i] = 0;
}

void back2 (int pos)
{
    if (pos >= N)
    {
        /*for (int i=1; i<=N; i++)
            printf ("%d ", a[i]);
        printf ("\n");*/
        sol ++;
        return ;
    }
    back2 (pos + 1);
    swap (a[pos], a[pos + 1]);
    back2 (pos + 2);
    swap (a[pos], a[pos + 1]);
}

void get (int pos, long long A)
{
    if (pos >= N)
        return;
    if (dp[N - pos] >= A)
        get (pos + 1, A);
    else
    {
        swap (a[pos], a[pos + 1]);
        get (pos + 2, A - dp[N - pos]);
    }
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d", &N, &A);
//back (1);
/*for (int i=1; i<=N; i++)
    a[i] = i;
back2 (1);
printf ("%d\n", sol);*/
dp[1] = 1LL;
dp[2] = 2LL;
for (int i=3; i<=N; i++)
    dp[i] = dp[i-1] + dp[i-2];
for (int i=1; i<=N; i++)
    a[i] = i;
get (1, A);

for (int i=1; i<=N; i++)
    printf ("%d ", a[i]);
printf ("\n");

return 0;
}