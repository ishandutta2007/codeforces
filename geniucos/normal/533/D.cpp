#include<bits/stdc++.h>

using namespace std;

int INF, ans, N, x[100009], d[100009], dp1[100009], dp2[100009], Norm[100009], aib[100009];
pair < int, int > h[100009];

void Clear (int val) {for (int i=0; i<=N; i++) aib[i] = val;}
void Updt (int pos, int val) {while (pos <= N) aib[pos] = max (aib[pos], val), pos += pos - (pos & (pos - 1));}
int Qry (int pos) {int maxi = -INF; while (pos) maxi = max (maxi, aib[pos]), pos &= pos - 1; return maxi;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N), INF = 2e9;
for (int i=0; i<=N + 1; i++)
    scanf ("%d", &x[i]);
for (int i=1; i<=N; i++)
    scanf ("%d", &d[i]);
for (int i=1; i<=N; i++)
{
    dp1[i] = Qry (N - i + 1);
    ///now update: each x[i] - dp1[i] <= 2d[i]
    int p = 1, u = N, mij, ras = -1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (x[mij] - dp1[i] <= 2 * d[i]) ras = mij, p = mij + 1;
        else u = mij - 1;
    }
    if (ras != -1) Updt (N - ras + 1, x[i]);
}
Clear (-x[N + 1]), ans = x[N + 1];
for (int i=N; i>=1; i--)
{
    dp2[i] = -Qry (i);
    ///now update: each dp2[i] - x[i] <= 2d[i]
    int p = 1, u = N, mij, ras = -1;
    while (p <= u)
    {
        mij = (p + u) >> 1;
        if (dp2[i] - x[mij] <= 2 * d[i]) ras = mij, u = mij - 1;
        else p = mij + 1;
    }
    if (ras != -1) Updt (ras, -x[i]);
}
//for (int i=1; i<=N; i++)
  //  printf ("%d %d\n", dp1[i], dp2[i]);
for (int i=1; i<=N; i++)
{
    ///try to build a new coloumn after i
    if (2 * d[i] + dp1[i] > x[i])
    {
        if (2 * d[i] + dp1[i] >= x[N + 1]) ans = 0; /// I actually don't have to add anything
        else
        {
            int curr = x[N + 1] - x[i];
            if (curr < ans) ans = curr;
        }
    }
    ///try to build a new coloumn before i
    if (dp2[i] - 2 * d[i] < x[i])
    {
        if (dp2[i] - 2 * d[i] <= 0) ans = 0; /// I actually don't have to add anything
        else
        {
            int curr = x[i];
            if (curr < ans) ans = curr;
        }
    }
}
///let's normalize the values for the biggest x of some coloumn at left of i so that
///I can select some at its right so that all after i and i inclusive are stable
///those x are equal to dp2[i] - 2d[i]
for (int i=1; i<=N; i++)
    h[i] = make_pair (dp2[i] - 2 * d[i], i);
sort (h + 1, h + N + 1);
for (int i=1; i<=N; i++)
    Norm[h[i].second] = i;
///I'm going to try to build a new coloumn between some i and j
Clear (-2 * N);
for (int i=N; i>=1; i--)
{
    if (i != N && 2 * d[i] + dp1[i] > x[i])
    {
        ///then there exists at least one j > i
        int p = 1, u = N, mij, ras = -1, j = 2 * N;
        while (p <= u)
        {
            mij = (p + u) >> 1;
            if (2 * d[i] + dp1[i] >= h[mij].first) ras = mij, p = mij + 1;
            else u = mij - 1;
        }
        if (ras != -1) j = -Qry (ras);
        if (j <= N && x[j] - x[i] < ans)
            ans = x[j] - x[i];
    }
    if (dp2[i] - 2 * d[i] < x[i]) Updt (Norm[i], -i);
}
if (ans % 2 == 0) printf ("%d\n", ans / 2);
else printf ("%d.5\n", ans / 2);
return 0;
}