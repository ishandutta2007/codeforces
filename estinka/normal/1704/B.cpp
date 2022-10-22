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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ch = 0;
        int mi = a[0], mx = a[0];
        for (int i = 0; i < n; i++)
        {
            mi = min(mi, a[i]);
            mx = max(mx, a[i]);
            if (mx - mi > 2 * x)
            {
                ch++;
                mi = mx = a[i];
            }
        }
        //cout << "                   ";
        cout << ch << "\n";
    }
    return 0;
}