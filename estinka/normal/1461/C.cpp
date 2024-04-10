#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
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
        vector<int> a(n);
        int bad = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] != i + 1) break;
            bad++;
        }
        ld un = 1.;
        if (bad == n)
        {
            un = 0.;
        }
        for (int i = 0; i < m; i++)
        {
            int r; ld p;
            cin >> r >> p;
            if (r >= n - bad)
            {
                un *= (1. - p);
            }
        }
        cout << setprecision(10) << fixed << (1. - un) << "\n";
    }
    return 0;
}