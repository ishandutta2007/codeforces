#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
#include <array>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
const int sz = 64, logn = 31;
vector<vector<int> > mul(const vector<vector<int> >& a, const vector<vector<int> >& b)
{
    int n = a.size();
    vector<vector<int> > c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                c[i][j] += (a[i][k] * 1ll * b[k][j]) % mod;
                if (c[i][j] >= mod) c[i][j] -= mod;
            }
    return c;
}
vector<int> mul(const vector<int>& a, const vector<vector<int> >& b)
{
    int n = a.size();
    vector<int>c(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c[j] += (a[i] * 1ll * b[i][j]) % mod;
            if (c[j] >= mod) c[j] -= mod;
        }
    return c;
}
array<array<int, 3>, 3> f;
int nw(int pv, int col)
{
    array<int, 4> mex{ 0 };
    for (int i = 0; i < 3; i++) if (f[col][i]) mex[(pv >> (i * 2)) & 3]++;
    for (int i = 0; i < 4; i++) if (!mex[i]) return ((pv << 2) | i) & 63;
}
vector<vector<vector<int> > > cm(3, vector<vector<int> >(sz, vector<int>(sz, 0))), all(logn, vector<vector<int> >(sz, vector<int>(sz, 0)));
void multiply_by_pwr(vector<int>& my, int p)
{
    for (int i = logn - 1; i >= 0; i--)
        if ((1 << i) & p) my = mul(my, all[i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<vector<pair<int, int> > > cl(n);
    for (int i = 0, x, y, c; i < m; i++)
    {
        cin >> x >> y >> c;
        cl[--x].push_back({ --y, --c });
    }
    for (int i = 0; i < n; i++) sort(cl[i].begin(), cl[i].end());
    for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) cin >> f[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < sz; j++)
            cm[i][j][nw(j, i)]++, all[0][j][nw(j, i)]++;
    for (int i = 1; i < logn; i++) all[i] = mul(all[i - 1], all[i - 1]);
    vector<vector<int> > dp(n + 1, vector<int>(4, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        vector<int> mym(sz, 0);
        mym[63] = 1;
        int last = -1;
        for (int j = 0; j < cl[i].size(); j++)
        {
            int dif = cl[i][j].first - last - 1;
            multiply_by_pwr(mym, dif);
            mym = mul(mym, cm[cl[i][j].second]);
            last = cl[i][j].first;
        }
        int dif = a[i] - last - 1;
        multiply_by_pwr(mym, dif);
        //for (int j = 0; j < sz; j++) cout << mym[j] << " ";
        //cout << "\n";
        for (int x = 0; x < 4; x++)
        {
            for (int j = 0; j < sz; j++)
            {
                int nwx = x ^ (j & 3);
                dp[i + 1][nwx] += (dp[i][x] * 1ll * mym[j]) % mod;
                if (dp[i + 1][nwx] >= mod) dp[i + 1][nwx] -= mod;
            }
        }
        //for (int x = 0; x < 4; x++) cout << dp[i + 1][x] << " ";
        //cout << "\n";
    }
    cout << dp[n][0] << "\n";
    return 0;
}