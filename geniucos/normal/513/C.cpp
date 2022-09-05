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

int N, fac, nr, L[10], R[10], p[10], tip[10];
double dp[10][10009], s[10][10009], sol;

void back (int poz)
{
    if (poz == N + 1)
    {
        for (int j=1; j<=10000; j++)
        {
            if (j < L[p[1]] || j > R[p[1]])
                dp[1][j] = 0.0;
            else
                dp[1][j] = (double) 1.0 / (R[p[1]] - L[p[1]] + 1);
        }

        for (int j=1; j<=10000; j++)
            s[1][j] = (double) s[1][j-1] + dp[1][j];
        for (int i=2; i<N; i++)
        {
            for (int j=1; j<=10000; j++)
            {
                if (j < L[p[i]] || j > R[p[i]]) dp[i][j] = 0.0;
                else dp[i][j] = (double) s[i-1][j] / (R[p[i]] - L[p[i]] + 1.0);
                s[i][j] = (double)s[i][j-1] + dp[i][j];
            }
        }
        for (int j=L[p[N-1]]; j<=R[p[N-1]]; j++)
        {
            double prob;
            prob = dp[N-1][j];
            if (tip[N])
            {
                if (j < L[p[N]] || j > R[p[N]])
                    prob = 0.0;
                else
                    prob = (double) prob / (R[p[N]] - L[p[N]] + 1);
            }
            else
            {
                if (R[p[N]] <= j)
                    prob = 0.0;
                else
                if (L[p[N]] <= j)
                    prob = (double) prob * (R[p[N]] - j) / (R[p[N]] - L[p[N]] + 1);
            }
            if (prob > 0.0000001)
                R[0] = 0;
            sol += (double)j * prob;
        }
        return;
    }
    for (int v=0; v<2; v++)
    {
        tip[poz] = v;
        back (poz + 1);
    }
}

double toateinmskmaimici (int msk, int v)
{
    double ans = 1.0;
    for (int j=1; j<=N; j++)
        if (msk&(1<<(j-1)))
        {
            if (L[j] >= v) ans = 0.0;
            else
            if (R[j] < v) ;
            else ans = (double) ans * (v - 1 - L[j] + 1) / (R[j] - L[j] + 1);
        }
    return ans;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
int fac = 1;
for (int i=1; i<=N; i++)
    scanf ("%d %d", &L[i], &R[i]);

for (int i=1; i<=10000; i++)
    for (int msk = 1; msk < (1<<N); msk ++)
    {
        double prob = 1.0;
        int nrb = 0;
        for (int j=1; j<=N; j++)
            if (msk&(1<<(j-1)))
            {
                if (L[j] > i || R[j] < i) prob = 0.0;
                else prob = (double) prob * 1.0 / (R[j] - L[j] + 1);
                nrb ++;
            }
        if (nrb >= 2)
            sol = (double) sol + i * toateinmskmaimici((1<<N) - 1 - msk, i) * prob;
        for (int p=1; p<=N; p++)
        {
            if (msk&(1<<(p-1))) continue;
            double P = prob;
            if (L[p] > i) ;
            else
            if (R[p] <= i) P = 0.0;
            else P = (double) P * (R[p] - i) / (R[p] - L[p] + 1);
            if (toateinmskmaimici((1<<N) - 1 - msk-(1<<(p-1)), i) * P > 0.00001)
                R[0]=0;
            sol = (double) sol + i * toateinmskmaimici((1<<N) - 1 - msk-(1<<(p-1)), i) * P;
        }
    }

printf ("%.10lf\n", sol);

return 0;
}