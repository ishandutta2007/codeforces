#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, x, y, u[150055];
vector<int> g[150055];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    map<vector<int>, int> mp;

    for (int i = 1; i <= n; ++i) {
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end());
        ++mp[g[i]];
    }

    for (map<vector<int>, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        if (it->first.size() && it->first.size() != it->second) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}