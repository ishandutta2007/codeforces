#include<bits/stdc++.h>

using namespace std;

int N, M, lg;

struct matrix
{
    bitset < 502 > rows[502];

    void Print ()
    {
        for (int i=1; i<=N; i++, printf ("\n"))
            for (int j=1; j<=N; j++)
                if (rows[i][j] == 1) printf ("1");
                else printf ("0");
        printf ("\n\n");
    }

    int cnt ()
    {
        int ans = rows[1].count ();///in cate pot ajunge din 1
        return ans;
    }
}dp[2][61];

matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (a.rows[i][j] == 1)
                c.rows[i] |= b.rows[j];
    return c;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M), lg = -1;
while (M --)
{
    int x, y, t;
    scanf ("%d %d %d", &x, &y, &t);
    dp[t][0].rows[x][y] = 1;
}
for (int i=1; i<=60; i++)
{
    dp[0][i] = dp[0][i - 1] * dp[1][i - 1];
    dp[1][i] = dp[1][i - 1] * dp[0][i - 1];
    if (dp[0][i].cnt () == 0)
    {
        lg = i - 1;
        break;
    }
    //printf ("(%d, %d):\n", i, 0), dp[0][i].Print ();
    //printf ("(%d, %d):\n", i, 1), dp[1][i].Print ();
}
if (lg == -1)
{
    printf ("-1\n");
    return 0;
}
matrix curr;
for (int i=1; i<=N; i++)
    curr.rows[i][i] = 1;
bool t = 0;
long long ans = 0;
for (int i=lg; i>=0; i--)
{
    matrix curr2 = curr * dp[t][i];
    if (curr2.cnt () != 0)
        curr = curr2, t ^= 1, ans |= 1LL << i;
    //curr.Print ();
}
if (ans > 1e18) ans = -1;
printf ("%I64d\n", ans);
return 0;
}