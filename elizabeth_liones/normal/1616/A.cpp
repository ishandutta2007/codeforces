#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
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
        vector<int> a(n), f(101, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            f[abs(a[i])]++;
        }
        int ans = min(f[0], 1);
        for (int i = 1; i < f.size(); i++) ans += min(f[i], 2);
        cout << ans << "\n";
    }
    return 0;
}