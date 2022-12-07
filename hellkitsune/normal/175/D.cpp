#include <iostream>
#include <cstdio>

using namespace std;

double eps = 0.000000001;
double dp[2][10000][201] = {{{0}}}, p[2], ppp, tp[2];
int hp[2], dt[2], l[2], r[2], pp[2];

int main(void)
{
    int i, j, k;
    for (i = 0; i < 2; ++i)
    {
        cin >> hp[i] >> dt[i] >> l[i] >> r[i] >> pp[i];
        p[i] = double(100 - pp[i]) / 100.0;
        tp[i] = 1.0 / double(r[i] - l[i] + 1);
    }
    if (pp[0] == 100)
    {
        cout << 0;
        return 0;
    }
    if (pp[1] == 100)
    {
        cout << 1;
        return 0;
    }
    dp[0][0][hp[1]] = 1;
    dp[1][0][hp[0]] = 1;
    int ll, rr;
    for (i = 0; i < 9999; ++i)
    {
        for (j = 1; j <= hp[1]; ++j)
            if (dp[0][i][j] > eps)
            {
                dp[0][i + 1][j] += (1.0 - p[0]) * dp[0][i][j];
                ll = j - l[0];
                rr = j - r[0];
                if (ll < 0)
                    ll = 0;
                if (rr < 0)
                    rr = 0;
                for (k = ll; k >= rr; --k)
                {
                    if (k > 0)
                        ppp = tp[0];
                    else
                        ppp = tp[0] * double(r[0] - l[0] + 1 - ll);
                    dp[0][i + 1][k] += p[0] * ppp * dp[0][i][j];
                }
            }
        for (j = 0; j <= hp[0]; ++j)
            if (dp[1][i][j] > eps)
            {
                dp[1][i + 1][j] += (1.0 - p[1]) * dp[1][i][j];
                ll = j - l[1];
                rr = j - r[1];
                if (ll < 0)
                    ll = 0;
                if (rr < 0)
                    rr = 0;
                for (k = ll; k >= rr; --k)
                {
                    if (k > 0)
                        ppp = tp[1];
                    else
                        ppp = tp[1] * double(r[1] - l[1] + 1 - ll);
                    dp[1][i + 1][k] += p[1] * ppp * dp[1][i][j];
                }
            }
    }
    int z[2] = {0, 0}, t[2] = {0, 0};
    double answ = 0;
    while ((z[0] < 9999) && (z[1] < 9999))
    {
        if (t[0] == t[1])
        {
            ++z[0];
            answ += dp[0][z[0]][0] * (1.0 - dp[1][z[1]][0]);
            ++z[1];
            t[0] = dt[0];
            t[1] = dt[1];
            continue;
        }
        if (t[0] < t[1])
        {
            ++z[0];
            answ += dp[0][z[0]][0] * (1.0 - dp[1][z[1]][0]);
            t[1] -= t[0];
            t[0] = dt[0];
            continue;
        }
        ++z[1];
        t[0] -= t[1];
        t[1] = dt[1];
    }
    printf("%.8lf", answ);
    return 0;
}