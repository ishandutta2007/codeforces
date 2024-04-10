#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
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
        vector<ll> w(n);
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
            ans += w[i];
        }
        vector<int> d(n, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            d[--u]++;
            d[--v]++;
        }
        multiset<pair<ll, int>, greater<pair<ll, int>>>m;
        for (int i = 0; i < n; i++)
        {
            d[i]--;
            if (d[i])
            {
                m.insert({ w[i], i });
            }
        }
        //cout << "           ";
        cout << ans;
        for (int i = 1; i < n - 1; i++)
        {
            pair<ll, int> now = *m.begin();
            ans += now.first;
            m.erase(m.begin());
            d[now.second]--;
            if (d[now.second])
            {
                m.insert(now);
            }
            cout << " " << ans;
        }
        cout << "\n";
    }
    return 0;
}