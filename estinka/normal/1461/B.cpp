#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        vector<vector<int> > pf(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < m; j++)
            {
                pf[i][j + 1] = pf[i][j] + (v[i][j] == '*' ? 1 : 0);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '.') continue;
                int cnt = 1;
                for (int k = i + 1; k < n; k++, cnt++)
                {
                    int col1 = j - cnt, col2 = j + cnt;
                    if (col1 < 0 || col2 >= m) break;
                    if (pf[k][col2 + 1] - pf[k][col1] != col2 - col1 + 1)
                    {
                        break;
                    }
                }
                ans += cnt;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}