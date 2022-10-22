#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
typedef long long ll;
using namespace std;

int gcd(int a, int b)
{
    while (b)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int> > v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < i; j++)
        {
            if (gcd(a[i], a[j]) > 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    vector<bitset<707> > dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
        dp[i][i] = 1;
    }
    for (int dist = 0; dist < n; dist++)
    {
        for (int l = 0; l + dist < n; l++)
        {
            int r = l + dist;
            if (r + 1 < n)
            {
                for (const int& root : v[r + 1])
                {
                    if (l <= root && root <= r && dp[root][l] && dp[root][r])
                    {
                        dp[r + 1][l] = 1;
                        break;
                    }
                }
            }
            if (l - 1 >= 0)
            {
                for (const int& root : v[l - 1])
                {
                    if (l <= root && root <= r && dp[root][l] && dp[root][r])
                    {
                        dp[l - 1][r] = 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] && dp[i][n - 1])
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}