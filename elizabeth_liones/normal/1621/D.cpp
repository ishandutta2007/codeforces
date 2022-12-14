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

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };
const ll inf = 1e18;
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
        vector<vector<int> > c(2 * n, vector<int>(2 * n, 0));
        ll sum = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                cin >> c[i][j];
                if (i >= n && j >= n)
                {
                    sum += c[i][j];
                    c[i][j] = 0;
                }
            }
        }
        ll mini = inf;
        mini = min(mini, (ll)c[n][n - 1]);
        mini = min(mini, (ll)c[n][0]);
        mini = min(mini, (ll)c[2 * n - 1][n - 1]);
        mini = min(mini, (ll)c[0][2 * n - 1]);

        mini = min(mini, (ll)c[n - 1][n]);
        mini = min(mini, (ll)c[0][n]);
        mini = min(mini, (ll)c[n - 1][2 * n - 1]);
        mini = min(mini, (ll)c[2 * n - 1][0]);
        cout << sum + mini << "\n";
    }
    return 0;
}