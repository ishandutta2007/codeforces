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
        int x, y;
        cin >> x >> y;
        ll ans = 0;
        for (int k = 1; k <= y && k * k <= x; k++)
        {
            ans += max(0, min(y + 1, x / k) - k - 1);
        }
        cout << ans << "\n";
    }
    return 0;
}