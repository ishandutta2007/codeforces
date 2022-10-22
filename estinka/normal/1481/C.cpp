#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n), c(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < m; i++) cin >> c[i];
        vector<vector<int> > pos(n + 1);
        for (int i = 0; i < n; i++) if (a[i] == b[i]) pos[b[i]].push_back(i);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i]) pos[b[i]].push_back(i);
        }
        vector<int> x(m);
        bool good = true;
        for (int i = m - 1; i >= 0; i--)
        {
            if (pos[c[i]].size())
            {
                x[i] = pos[c[i]].back();
                b[x[i]] = -1;
                pos[c[i]].pop_back();
                pos[0].push_back(x[i]);
            }
            else if (pos[0].size())
            {
                x[i] = pos[0].back();
            }
            else
            {
                good = false;
                break;
            }
        }
        for (int i = 0; i < n; i++) if (b[i] != -1 && b[i] != a[i]) good = false;
        if (good)
        {
            cout << "YES\n";
            for (int i = 0; i < m; i++) cout << x[i] + 1 << " ";
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}