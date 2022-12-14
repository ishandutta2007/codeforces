#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

void upd(int& a, int b) { a = max(a, b); }
const int inf = 1e9;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int x;
        cin >> x;
        for (int i = 0; i < n; i++) a[i] -= x;
        vector<vector<int> > dp(n + 1, vector<int>(3, -inf));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++) if (dp[i][j] != -inf)
            {
                upd(dp[i + 1][0], dp[i][j]);
                bool ok = true;
                if (j && a[i - 1] + a[i] < 0) ok = false;
                if (j >= 2 && a[i - 2] + a[i - 1] + a[i] < 0) ok = false;
                if (ok)
                    upd(dp[i + 1][min(2, j + 1)], dp[i][j] + 1);
            }
        }
        //cout << "           ";
        cout << max({ dp[n][0], dp[n][1], dp[n][2] }) << "\n";
    }
    return 0;
}