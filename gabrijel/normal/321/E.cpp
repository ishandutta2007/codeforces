#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 4050;
const int maxk = 810;
const int inf = 1e9;
const int maxs = 10000;

int n, k;

int mat[maxn][maxn];

int prefsum[maxn][maxn];

int dp[maxk][maxn];

int trk;

char upis[maxs];

int inter(int a, int b)
{
    if(a == 0) return prefsum[b][b] / 2;
    else return (prefsum[b][b] - prefsum[b][a - 1] - prefsum[a - 1][b] + prefsum[a - 1][a - 1]) / 2;
}

void rek(int l, int r, int lp, int rp)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    int optp = lp, optv;
    if(optp == 0) optv = inter(optp, mid);
    else optv = dp[trk - 1][optp - 1] + inter(optp, mid);
    REP(i, lp + 1, min(rp + 1, mid + 1))
    {
        if(dp[trk - 1][i - 1] + inter(i, mid) < optv)
        {
            optp = i;
            optv = dp[trk - 1][i - 1] + inter(i, mid);
        }
    }
    dp[trk][mid] = optv;
    //cout << trk << " " << mid << " " << dp[trk][mid] << endl;
    rek(l, mid - 1, lp, optp);
    rek(mid + 1, r, optp, rp);
    return;
}

int main()
{
    scanf("%d%d", &n, &k);
    //memset(dp, -1, sizeof dp);
    //! REP(i, 0, k) REP(j, 0, n) dp[i][j] = inf;
    REP(i, 0, n)
    {
        scanf("\n%[^\n]", upis);
        REP(j, 0, n)
        {
            mat[i][j] = upis[j * 2] - '0';
            //cout << mat[i][j] << endl;
            //scanf("%d", &mat[i][j]);
        }
    }
    prefsum[0][0] = mat[0][0];
    REP(i, 1, n)
    {
        prefsum[0][i] = prefsum[0][i - 1] + mat[0][i];
        prefsum[i][0] = prefsum[i - 1][0] + mat[i][0];
    }
    REP(i, 1, n)
    {
        REP(j, 1, n)
        {
            prefsum[i][j] = prefsum[i - 1][j] + prefsum[i][j - 1] - prefsum[i - 1][j - 1] + mat[i][j];
        }
    }
    REP(i, 0, n) dp[0][i] = inf;
    REP(t, 1, k + 1)
    {
        trk = t;
        rek(0, n - 1, 0, n - 1);
    }
    printf("%d\n", dp[k][n - 1]);
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