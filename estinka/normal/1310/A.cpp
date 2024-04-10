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
    int n;
    cin >> n;
    vector<pair<ll, ll>>a(n);
    map<ll, vector<ll> > m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        m[a[i].first].push_back(a[i].second);
    }
    vector<vector<ll>> t;
    vector<ll> aa;
    for (const auto& i : m)
    {
        t.push_back(i.second);
        aa.push_back(i.first);
    }
    ll ans = 0;
    int last = 0, cnt = 0;
    for (int i=0;i<t.size();i++)
    {
        cnt += t[i].size();
        if (i == t.size() - 1 || cnt < aa[i + 1] - aa[last])
        {
            multiset<ll, greater<ll> > s;
            for (int j = aa[last]; j <= aa[i] || s.size(); j++)
            {
                if (m.count(j))
                {
                    for (ll& k : m[j])
                    {
                        s.insert(k);
                        ans -= k * 1ll * j;
                    }
                }
                ans += (*s.begin()) * 1ll * j;
                s.erase(s.begin());
            }
            cnt = 0;
            last = i + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}