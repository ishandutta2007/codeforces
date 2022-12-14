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

const int inf = 2e9 + 5;
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
        vector<int> l(n), r(n), c(n);
        vector<int> ml(n, inf), mr(n, -inf);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i] >> c[i];
            if (!i) ml[i] = l[i], mr[i] = r[i];
            else
            {
                ml[i] = min(ml[i - 1], l[i]);
                mr[i] = max(mr[i - 1], r[i]);
            }
        }
        int lc = inf, rc = inf, both = inf;
        for (int i = 0; i < n; i++)
        {
            if (i && ml[i] != ml[i - 1]) lc = inf, both = inf;
            if (l[i] == ml[i]) lc = min(lc, c[i]);

            if (i && mr[i] != mr[i - 1]) rc = inf, both = inf;
            if (r[i] == mr[i]) rc = min(rc, c[i]);

            if (l[i] == ml[i] && r[i] == mr[i]) both = min(both, c[i]);
            
            cout << min(lc + rc, both) << "\n";
        }
    }
    return 0;
}