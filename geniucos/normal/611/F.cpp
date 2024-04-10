#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int N, H, W, mod, minx[500009], maxx[500009], miny[500009], maxy[500009], x[500009], y[500009];
long long dp1[500009], dp2[500009], INF = 1LL << 58;
char sir[500009];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int cod (char c)
{
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'L') return 2;
    return 3;
}

void builddp1 ()
{
    if (x[N] < 0)
    {
        for (int i=1; i<=H; i++)
        {
            if (minx[N] + i >= 1 && maxx[N] + i <= H)
            {
                if (x[N] == 0) dp1[i] = -1;
                else dp1[i] = dp1[i + x[N]] + N;
            }
            else
            {
                int p = 1, u = N, mij, ras;
                while (p <= u)
                {
                    mij = (p + u) >> 1;
                    if (minx[mij] + i >= 1 && maxx[mij] + i <= H) p = mij + 1;
                    else ras = mij, u = mij - 1;
                }
                dp1[i] = ras;
            }
        }
    }
    else
    {
        for (int i=H; i>=1; i--)
        {
            if (minx[N] + i >= 1 && maxx[N] + i <= H)
            {
                if (x[N] == 0) dp1[i] = -1;
                else dp1[i] = dp1[i + x[N]] + N;
            }
            else
            {
                int p = 1, u = N, mij, ras;
                while (p <= u)
                {
                    mij = (p + u) >> 1;
                    if (minx[mij] + i >= 1 && maxx[mij] + i <= H) p = mij + 1;
                    else ras = mij, u = mij - 1;
                }
                dp1[i] = ras;
            }
        }
    }
}

void builddp2 ()
{
    if (y[N] < 0)
    {
        for (int i=1; i<=W; i++)
        {
            if (miny[N] + i >= 1 && maxy[N] + i <= W)
            {
                if (y[N] == 0) dp2[i] = -1;
                else dp2[i] = dp2[i + y[N]] + N;
            }
            else
            {
                int p = 1, u = N, mij, ras;
                while (p <= u)
                {
                    mij = (p + u) >> 1;
                    if (miny[mij] + i >= 1 && maxy[mij] + i <= W) p = mij + 1;
                    else ras = mij, u = mij - 1;
                }
                dp2[i] = ras;
            }
        }
    }
    else
    {
        for (int i=W; i>=1; i--)
        {
            if (miny[N] + i >= 1 && maxy[N] + i <= W)
            {
                if (y[N] == 0) dp2[i] = -1;
                else dp2[i] = dp2[i + y[N]] + N;
            }
            else
            {
                int p = 1, u = N, mij, ras;
                while (p <= u)
                {
                    mij = (p + u) >> 1;
                    if (miny[mij] + i >= 1 && maxy[mij] + i <= W) p = mij + 1;
                    else ras = mij, u = mij - 1;
                }
                dp2[i] = ras;
            }
        }
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &H, &W), mod = 1e9 + 7;
gets (sir + 1);
x[0] = y[0] = 0;
for (int i=1; i<=N; i++)
{
    sir[i] = cod (sir[i]);
    x[i] = x[i - 1] + dx[sir[i]];
    y[i] = y[i - 1] + dy[sir[i]];
    minx[i] = min (minx[i - 1], x[i]);
    maxx[i] = max (maxx[i - 1], x[i]);
    miny[i] = min (miny[i - 1], y[i]);
    maxy[i] = max (maxy[i - 1], y[i]);
}
builddp1 ();
builddp2 ();
/*for (int i=1; i<=H; i++)
    printf ("%I64d ", dp1[i]);
printf ("\n");
for (int i=1; i<=W; i++)
    printf ("%I64d ", dp2[i]);*/
//return 0;
bool ok1 = 0, ok2 = 0;
for (int i=1; i<=H; i++)
    if (dp1[i] == -1)
    {
        ok1 = 1;
        dp1[i] = INF;
    }
for (int i=1; i<=W; i++)
    if (dp2[i] == -1)
    {
        ok2 = 1;
        dp2[i] = INF;
    }
if (ok1 && ok2)
{
    printf ("-1\n");
    return 0;
}
/*int sol = 0;
for (int i=1; i<=H; i++)
    for (int j=1; j<=W; j++)
    {
        if (dp1[i] == -1 && dp2[j] == -1)
        {
            printf ("-1\n");
            return 0;
        }
        long long curr;
        if (dp1[i] == -1) curr = dp2[j];
        else
        if (dp2[j] == -1) curr = dp1[i];
        else curr = min (dp1[i], dp2[j]);
        sol = ((long long)sol + curr) % mod;
    }
printf ("%d\n", sol);*/
sort (dp1 + 1, dp1 + H + 1);
sort (dp2 + 1, dp2 + W + 1);
int j = 1, sol = 0;
for (int i=1; i<=H; i++)
{
    while (dp2[j] <= dp1[i] && j <= W) j ++;
    int curr = dp1[i] % mod;
    sol = ((long long) sol + 1LL * curr * (W - j + 1)) % mod;
}
j = 1;
for (int i=1; i<=W; i++)
{
    while (dp1[j] < dp2[i] && j <= H) j ++;
    int curr = dp2[i] % mod;
    sol = ((long long) sol + 1LL * curr * (H - j + 1)) % mod;
}
printf ("%d\n", sol);
return 0;
}