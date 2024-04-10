#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 200100;
const int maxk = 60;
const double inf = 1e18;

int n, k;
int t[maxn];

int brgr;

long long int prefsum[maxn];
double prefraz[maxn];
double prefrec[maxn];

double dp[maxk][maxn];

double inter(int a, int b)
{
    if(a == 0) return prefraz[b];
    return prefraz[b] - prefraz[a - 1] - (double) prefsum[a - 1] * (prefrec[b] - prefrec[a - 1]);
}

void rek(int l, int r, int lp, int rp)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    int optp = lp;
    double optv = inter(optp, mid);
    if(lp > 0) optv += dp[brgr - 1][optp - 1];
    REP(i, lp + 1, min(mid + 1, rp + 1))
    {
        if(dp[brgr - 1][i - 1] + inter(i, mid) < optv)
        {
            optv = dp[brgr - 1][i - 1] + inter(i, mid);
            optp = i;
        }
    }
    dp[brgr][mid] = optv;
    rek(l, mid - 1, lp, optp);
    rek(mid + 1, r, optp, rp);
    return;
}

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 0, n) dp[0][i] = inf;
    REP(i, 0, n)
    {
        scanf("%d", &t[i]);
        prefsum[i] = i == 0 ? t[i] : (prefsum[i - 1] + t[i]);
        prefraz[i] = i == 0 ? ((double) prefsum[i] / t[i]) : (prefraz[i - 1] + (double) prefsum[i] / t[i]);
        prefrec[i] = i == 0 ? ((double) 1 / t[i]) : ((double) prefrec[i - 1] + (double) 1 / t[i]);
    }
    REP(tt, 1, k + 1) {brgr = tt; rek(0, n - 1, 0, n - 1);}
    printf("%lf\n", dp[k][n - 1]);
    /*REP(i, 0, k + 1)
    {
        REP(j, 0, n)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}