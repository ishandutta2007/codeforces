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
        int n, m;
        cin >> n >> m;
        string a, b;
        cin >> a >> b;
        bool ok = true;
        char mi = '1', mx = '0';
        for (int i = 0; i <= n - m; i++) mi = min(mi, a[i]), mx = max(mx, a[i]);
        if (b[0] != mi && b[0] != mx) ok = false;

        for (int i = n - m + 1; i < n; i++) if (a[i] != b[i - (n - m)]) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}