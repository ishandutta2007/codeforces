#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
using namespace std;

const int maxn = 1e6 + 79;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> f(maxn, 0);
    for (int i = 0, w; i < n; i++)
    {
        cin >> w;
        f[w]++;
    }
    int ans = 0;
    for (int i = 0; i < maxn - 1; i++)
    {
        if (f[i] % 2 == 1)
        {
            ans++;
            f[i]--;
        }
        f[i + 1] += f[i] / 2;
    }
    cout << ans << "\n";
    return 0;
}