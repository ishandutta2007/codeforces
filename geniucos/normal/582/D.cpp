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

int nr, P, lim, alf, mod, cif[5009], dp[2][3500][2][2];

struct mare
{
    int v[1009];
    mare ()
    {
        memset (v, 0, sizeof (v));
    }

    void Read ()
    {
        char sir[1009];
        gets (sir + 1);
        v[0] = strlen (sir + 1);
        for (int i=1; i<=v[0]; i++)
            v[i] = sir[v[0] + 1 - i] - '0';
    }

    int operator % (int val)
    {
        int p = 0;
        for (int i=v[0]; i>=1; i--)
            p = ((long long)1LL * p * 10 + v[i]) % val;
        return p;
    }

    mare operator / (int val)
    {
        mare ans;
        long long t = 0;
        ans.v[0] = v[0];
        for (int i=v[0]; i>=1; i--)
        {
            t = (long long) 1LL * t * 10 + v[i];
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

void Finish (int val)
{
    printf ("%d\n", val);
    exit (0);
}

int Gaus (int val)
{
    if (val < 0) return 0;
    int a, b;
    if (val & 1LL) a = val, b = (val + 1) / 2;
    else a = val / 2, b = val + 1;
    a %= mod, b %= mod;
    return (1LL * a * b) % mod;
}

int Gaus_Segment (int st, int dr)
{
    int val = Gaus (dr) - Gaus (st - 1);
    if (val < 0) val += mod;
    return val;
}

int Sum_Smaller (int val)
{
    if (val < 0) return 0;
    if (val > 2 * P - 2) val = 2 * P - 2;
    if (val <= lim)
    {
        return Gaus (val + 1);
        ///0 + 0, 0 + 1, ..., 0 + val, 1 + 0, 1 + 1, 1 + val - 1
        ///val + 1, val, ..., 1
    }
    int cnt = Gaus (lim + 1);
    ///lim + 1 = 1 + lim, 2 + lim - 1, ..., lim + 1 -> lim
    ///lim + 2 = 2 + lim, 3 + lim - 1, ..., lim + 2 -> lim - 1
    ///cnt + lim + lim - 1 + ... + lim - (val - lim - 1)
    ///cnt + Gaus_Segment (lim - (val - lim - 1), lim)
    ///val = lim + 1 -> cnt + (lim - 0, lim) ok
    ///val = lim + 2 -> cnt + (lim - 1, lim) ok
    cnt += Gaus_Segment (lim - (val - lim - 1), lim);
    if (cnt >= mod) cnt -= mod;
    return cnt;
}

int Sum_Segment (int st, int dr)
{
    int val = Sum_Smaller (dr) - Sum_Smaller (st - 1);
    if (val < 0) val += mod;
    return val;
}

int Fix (int sum)
{
    if (sum < lim) return (sum + 1) % mod;
    if (sum > 2 * lim) return 0;
    return (lim - (sum - lim - 1)) % mod;
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &P, &alf), mod = 1e9 + 7, lim = P - 1;
totu.Read ();
if (P == 1)
{
    int curr = totu % mod;
    curr = (1LL * curr * (curr + 1)) % mod;
    Finish (curr);
}
if (totu.not0 () == 0) Finish (0);
while (totu.not0 ())
{
    cif[++nr] = totu % P;
    totu = totu / P;
}
if (alf > nr) Finish (0);
reverse (cif + 1, cif + nr + 1);
/*
dp[i][j][car][fix]
din primele i cifre, fiind toate fixate, stiind ca de la cifra urmatoare primim un transport car,
sa avem j transporutri(de la o cifra p <= j la cifra p - 1) stiind ca pana acum e
(daca fix = 0 -> sunt la fel, e exact altfel e mult mai mic)
*/

/*int sum[10]; sum[0] = 0;
for (int i=0; i<4; i++)
    sum[i + 1] = sum[i] + Fix (i);

for (int i=0; i<4; i++)
    for (int j=i; j<4; j++)
        printf ("(%d, %d) -> %d, adev = %d\n", i, j, Sum_Segment (i, j), sum[j + 1] - sum[i]);*/

dp[0][0][0][0] = 1LL;
for (int i=1; i<=nr; i++)
{
    memset (dp[i & 1], 0, sizeof (dp[i & 1]));
    for (int j=0; j<=i; j++)
        for (int car_prec = 0; car_prec < 2; car_prec ++)
            for (int car = 0; car <= j && car < 2; car ++)
            {
                dp[i & 1][j][car_prec][0] = ((long long)dp[i & 1][j][car_prec][0] +
                1LL * dp[(i & 1) ^ 1][j - car][car][0] * Fix (cif[i] + car * P - car_prec)) % mod;

                if (cif[i]) dp[i & 1][j][car_prec][1] = ((long long)dp[i & 1][j][car_prec][1] +
                1LL * dp[(i & 1) ^ 1][j - car][car][0] * Sum_Segment (car * P - car_prec, car * P - car_prec + cif[i] - 1)) % mod;

                dp[i & 1][j][car_prec][1] = ((long long)dp[i & 1][j][car_prec][1] +
                1LL * dp[(i & 1) ^ 1][j - car][car][1] * Sum_Segment (car * P - car_prec, car * P - car_prec + P - 1)) % mod;
            }
}

int sol = 0;
for (int p=alf; p<=nr; p++)
    for (int F=0; F<=1; F++)
    {
        sol += dp[nr & 1][p][0][F];
        if (sol >= mod) sol -= mod;
    }
Finish (sol);
return 0;
}