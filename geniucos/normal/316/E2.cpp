#include<cstdio>
#include<bitset>
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

int ans_x, ans_y, mod, N, M, a[200009], x[800009], y[800009], coef_x[200009], coef_y[200009], sum_x[200009], sum_y[200009], fibo[200009];

void Fibonacci_Precompution ()
{
    coef_x[0] = 1, coef_y[0] = 0;
    coef_x[1] = 0, coef_y[1] = 1;
    for (int i=2; i<=N + 3; i++)
    {
        coef_x[i] = coef_x[i - 1] + coef_x[i - 2];
        if (coef_x[i] >= mod) coef_x[i] -= mod;
        coef_y[i] = coef_y[i - 1] + coef_y[i - 2];
        if (coef_y[i] >= mod) coef_y[i] -= mod;
    }

    fibo[0] = fibo[1] = 1;
    for (int i=2; i<=N + 3; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        if (fibo[i] >= mod) fibo[i] -= mod;
    }

    sum_x[0] = 1, sum_y[0] = 0;
    for (int i=1; i<=N + 3; i++)
    {
        sum_x[i] = sum_x[i - 1] + coef_x[i];
        if (sum_x[i] >= mod) sum_x[i] -= mod;
        sum_y[i] = sum_y[i - 1] + coef_y[i];
        if (sum_y[i] >= mod) sum_y[i] -= mod;
    }
}

void Refresh (int nod, int st, int dr, int mij)
{
    int f1 = nod << 1, f2 = f1 + 1;
    x[nod] = ((long long) x[f1] + 1LL * x[f2] * coef_x[mij - st + 1] + 1LL * y[f2] * coef_x[mij - st + 2]) % mod;
    if (mij == st) y[nod] = x[f2];
    else y[nod] = ((long long) y[f1] + 1LL * y[f2] * coef_y[mij - st + 2] + 1LL * x[f2] * coef_y[mij - st + 1]) % mod;
}

void Build (int nod, int st, int dr)
{
    if (st == dr)
    {
        x[nod] = a[st], y[nod] = 0;
        return ;
    }
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build ((nod << 1) + 1, mij + 1, dr);
    Refresh (nod, st, dr, mij);
}

void Query (int nod, int st, int dr, int x_q, int y_q)
{
    if (x_q <= st && dr <= y_q)
    {
        int pos = st - x_q;
        ans_x = ((long long) ans_x + 1LL * x[nod] * coef_x[pos] + 1LL * y[nod] * coef_x[pos + 1]) % mod;
        if (pos > 0) ans_y = ((long long) ans_y + 1LL * y[nod] * coef_y[pos + 1] + 1LL * x[nod] * coef_y[pos]) % mod;
        else ans_y = y[nod];
        return ;
    }
    int mij = (st + dr) >> 1;
    if (x_q <= mij) Query (nod << 1, st, mij, x_q, y_q);
    if (y_q > mij) Query ((nod << 1) + 1, mij + 1, dr, x_q, y_q);
}

void Update (int nod, int st, int dr, int pos, int val)
{
    if (st == dr)
    {
        x[nod] = val;
        return ;
    }
    int mij = (st + dr) >> 1;
    if (pos <= mij) Update (nod << 1, st, mij, pos, val);
    else Update ((nod << 1) + 1, mij + 1, dr, pos, val);
    Refresh (nod, st, dr, mij);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), mod = 1e9;
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
Fibonacci_Precompution ();
Build (1, 1, N);
while (M --)
{
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int pos, val;
        scanf ("%d %d", &pos, &val);
        Update (1, 1, N, pos, val);
        continue;
    }
    int left, right, ans;
    scanf ("%d %d", &left, &right), ans_x = 0, ans_y = 0;
    Query (1, 1, N, left, right);
    ans = ans_x + ans_y;
    if (ans >= mod) ans -= mod;
    printf ("%d\n", ans);
}
return 0;
}