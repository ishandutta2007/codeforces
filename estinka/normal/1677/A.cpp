#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 5005;
int big[maxn][maxn];
int sum(int i, int l, int r) // vacsie
{
    return big[i][r + 1] - big[i][l];
}
int sum2(int i, int l, int r) // mensie
{
    return (r - l + 1) - (big[i][r + 1] - big[i][l]);
}
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
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++)
        {
            big[i][j] = 0;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                big[i][j + 1] = big[i][j] + (p[j] > p[i] ? 1 : 0);
            }
        }
        ll ans = 0;
        for (int b = 1; b < n; b++)
        {
            for (int c = b + 1; c + 1 < n; c++)
            {
                int cnta = sum2(c, 0, b - 1);
                int cntd = sum2(b, c + 1, n - 1);
                ans += cnta * cntd;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}