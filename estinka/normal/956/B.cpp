#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <array>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u;
    cin >> n >> u;
    vector<int> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];
    ld ans = -1.;
    for (int i = 0; i < n; i++)
    {
        int k = upper_bound(e.begin(), e.end(), e[i] + u) - e.begin() - 1;
        if (k <= i + 1) continue;
        ans = max(ans, (ld)(e[k] - e[i + 1]) / (ld)(e[k] - e[i]));
    }
    if (ans < 0) cout << "-1\n";
    else cout << setprecision(30) << fixed << ans << "\n";
    return 0;
}