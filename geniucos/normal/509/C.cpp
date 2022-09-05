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

int N, b[309], bst[1009], sol[309][2009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);

for (int i=1; i<=N; i++)
    scanf ("%d", &b[i]);

sol[0][0] = 1;
for (int i=1; i<=N; i++)
{
    bool ok = 1;
    for (int j=0; j<=sol[i-1][0]; j++)
    {
        sol[i][j] = sol[i-1][j];
        if (sol[i][j] != 9 && j != 0)
            ok = 0;
    }

    if (ok)
    {
        sol[i][0] ++;
        for (int j=1; j<=sol[i][0]; j++)
            sol[i][j] = (j == 1);
    }
    else
    {
        sol[i][sol[i][0]] ++;
        int j = sol[i][0];
        while (sol[i][j] == 10)
            sol[i][j--] = 0, sol[i][j] ++;
    }

    int L = b[i] / 9;
    if (b[i] % 9 != 0)
        L ++;
    if (L > sol[i][0])
    {
        sol[i][0] = L;
        for (int j=2; j<=L; j++)
            sol[i][j] = 9;
        if (b[i]%9) sol[i][1] = b[i] % 9;
        else sol[i][1] = 9;
        continue;
    }

    int sum = b[i];
    for (int j=1; j<=sol[i][0]; j++)
    {
        if (sum <= 9) bst[j] = sum, sum = 0;
        else bst[j] = 9, sum -= 9;
    }

    ok = 1;
    for (int j=1; j<=sol[i][0]; j++)
        if (bst[j] != sol[i][j])
        {
            if (bst[j] < sol[i][j])
                ok = 0;
            break;
        }
    if (ok)
    {
        int S = 0;
        for (int j=1; j<=sol[i][0]; j++)
            S += sol[i][j];
        if (S == b[i])
            continue;
        S = 0;
        int last_cor_pref = 0;
        for (int j=1; j<=sol[i][0]; j++)
        {
            if (S + sol[i][j] + 1 <= b[i] && S + 9 * (sol[i][0] - j + 1) >= b[i] && sol[i][j] < 9)
                last_cor_pref = j - 1;
            S += sol[i][j];
        }
        int sum = b[i];
        for (int j=1; j<=last_cor_pref; j++)
            sum -= sol[i][j];
        for (int v = sol[i][last_cor_pref + 1] + 1; v<10; v++)
            if (v + 9 * (sol[i][0] - last_cor_pref - 1) >= sum)
            {
                sum -= v;
                sol[i][last_cor_pref + 1] = v;
                break;
            }
        for (int j=sol[i][0]; j>last_cor_pref + 1; j--)
        {
            if (sum <= 9) sol[i][j] = sum, sum = 0;
            else sol[i][j] = 9, sum -= 9;
        }
        continue;
    }

    sol[i][0] ++;
    sol[i][1] = 1;
    sum = b[i] - 1;
    for (int j=sol[i][0]; j>=2; j--)
    {
        if (sum <= 9) sol[i][j] = sum, sum = 0;
        else sol[i][j] = 9, sum -= 9;
    }
}

for (int i=1; i<=N; i++, printf ("\n"))
    for (int j=1; j<=sol[i][0]; j++)
        printf ("%d", sol[i][j]);
return 0;
}