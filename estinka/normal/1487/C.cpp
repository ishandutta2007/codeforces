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
typedef long long ll;
using namespace std;

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
        int m = (n * (n - 1)) / 2;
        vector<vector<int> > ans(n, vector<int>(n, -2));
        for (int i = 0; i < n; i++)
        {
            int mywin = m / n;
            for (int j = 0; j < mywin; j++)
            {
                int in = (i + j + 1) % n;
                ans[i][in] = 1;
                ans[in][i] = -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ans[i][j] == -2) ans[i][j] = ans[j][i] = 0;
                //cout << ans[i][j] << " ";
            }
            //cout << "\n";
        }
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    return 0;
}