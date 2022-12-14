#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <bitset>
#include <cmath>
#include <cassert>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxb = 20;
int solve(int a, int b)
{
    int ans = b - a;
    for (int i = 0; i <= ans; i++)
    {
        int x = (1 << maxb) - 1;
        for (int j = maxb - 1; j >= 0; j--)
        {
            if (((a + i) & (1 << j)) == 0 && x - (1 << j) >= b)
            {
                x -= (1 << j);
            }
        }
        ans = min(ans, i + x - b + 1);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}