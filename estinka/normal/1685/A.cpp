#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (n & 1)
        {
            cout << "NO\n";
            continue;
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0; i < n / 2; i++)
        {
            ans.push_back(a[i]);
            ans.push_back(a[i + n / 2]);
        }
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == ans[(i + 1) % n]) ok = false;
        }
        if (!ok)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}