#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<ll, vector<ll>> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) m[a[i]].push_back(b[i]);
    ll ans = 0;
    vector<pair<ll, ll> > taken;
    vector<pair<ll, vector<ll> > > v;
    for (const auto& i : m) v.push_back(i);
    reverse(v.begin(), v.end());
    for (const auto &i : v)
    {
        if (i.second.size() > 1)
        {
            for (ll j : i.second) taken.push_back({ i.first, j });
        }
        else
        {
            for (auto j : taken)
            {
                if ((i.first | j.first) == j.first)
                {
                    taken.push_back({ i.first, i.second[0] });
                    break;
                }
            }
        }
    }
    if (taken.size() > 1)
    {
        for (auto j : taken) ans += j.second;
    }
    cout << ans << "\n";
    return 0;
}