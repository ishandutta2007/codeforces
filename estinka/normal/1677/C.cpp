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
        vector<int> a(n), b(n), p(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) p[--a[i]] = --b[i];
        int o = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) if (!vis[i])
        {
            int j = i, len = 0;
            while (!vis[j])
            {
                vis[j] = 1;
                len++;
                j = p[j];
            }
            if (len & 1) o++;
        }
        cout << (((n + o) * 1ll * (n - o)) / 2ll) << "\n";
    }
    return 0;
}