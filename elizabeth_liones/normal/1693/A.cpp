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
        ll sum = 0;
        int mz = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i]) mz = i;
            sum += a[i];
        }
        if (sum != 0)
        {
            cout << "No\n";
            continue;
        }
        sum = 0;
        bool ok = true;
        for (int i = 0; i < mz; i++)
        {
            sum += a[i];
            if (sum <= 0) ok = false;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}