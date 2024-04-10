#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <random>
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
        ll x;
        cin >> n >> x;
        map<ll, int> f;
        for (int i = 0, a; i < n; i++)
        {
            cin >> a;
            f[a]++;
        }
        ll ans = 0;
        for (pair<ll, int> i : f) if (i.second > 0)
        {
            ll num = i.first;
            ll use = 0;
            if (f.count(num * x)) use = min(f[num], f[num * x]);
            f[num] -= use;
            f[num * x] -= use;
            ans += f[num];
        }
        cout << ans << "\n";
    }
    return 0;
}