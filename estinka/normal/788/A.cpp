#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

ll best = -1e18;
void upd(ll& a, const ll& b)
{
    best = max(best, b);
    a = max(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll> > dp(n, vector<ll>(2, 0)); // 0: +, 1: -
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i)
        {
            ll dif = abs(a[i] - a[i - 1]);
            upd(dp[i][1], dif);
            upd(dp[i][1], dp[i - 1][0] + dif);
            upd(dp[i][0], dp[i - 1][1] - dif);
        }
    }
    cout << best << "\n";
    return 0;
}