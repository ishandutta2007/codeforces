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

const int maxn = 2e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<int> > p(maxn);
    for (int n = 2; n < maxn; n++)
    {
        if (p[n].empty())
        {
            for (int i = n; i < maxn; i += n) p[i].push_back(n);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int k = p[n].size();
        vector<vector<ll> > sum(k);
        vector<multiset<ll> > v(k);
        ll ans = 0;
        for (int i = 0; i < k; i++)
        {
            int pr = p[n][i], rs = n / pr;
            sum[i].resize(rs);
            for (int j = 0; j < n; j++) sum[i][j % rs] += a[j];
            for (int j = 0; j < rs; j++) v[i].insert(sum[i][j] * (ll)rs);
            ans = max(ans, *v[i].rbegin());
        }
        //cout << "                       ";
        cout << ans << "\n";
        while (q--)
        {
            int id, x;
            cin >> id >> x;
            id--;
            ans = 0;
            for (int i = 0; i < k; i++)
            {
                int pr = p[n][i], rs = n / pr, re = id % rs;
                v[i].erase(v[i].find(sum[i][re] * (ll)rs));
                sum[i][re] += x - a[id];
                v[i].insert(sum[i][re] * (ll)rs);
                ans = max(ans, *v[i].rbegin());
            }
            a[id] = x;
            //cout << "                       ";
            cout << ans << "\n";
        }
    }
    return 0;
}