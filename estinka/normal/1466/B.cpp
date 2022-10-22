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
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> f(2 * n + 79);
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            f[x[i]]++;
        }
        for (int i = f.size() - 2; i >= 0; i--)
        {
            if (f[i])
            {
                if (!f[i + 1])
                {
                    f[i]--;
                    f[i + 1]++;
                }
            }
        }
        int ans = 0;
        for (int i : f) if (i)ans++;
        cout << ans << "\n";
    }
    return 0;
}