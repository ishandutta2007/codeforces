#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for (int i = 0; i < min(n + 1, m); i++)
    {
        for (int j = 0; j < min(n + 1, m); j++)
        {
            if ((i * i + j * j) % m == 0)
            {
                int good1 = (n / m) + (i <= n % m) - (i == 0);
                int good2 = (n / m) + (j <= n % m) - (j == 0);
                ans += good1 * 1ll * good2;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}