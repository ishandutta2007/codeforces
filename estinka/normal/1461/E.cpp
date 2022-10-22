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

void end(bool good)
{
    cout << (good ? "Yes\n" : "No\n");
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if (x >= y)
    {
        ll maxt = 0;
        if (k + y > r)
        {
            maxt++;
            k -= x;
            if (k < l) end(false);
        }
        if (x == y) end(true);
        maxt += (k - l) / (x - y);
        if (maxt >= t) end(true);
        end(false);
    }
    r -= l;
    k -= l;
    vector<vector<pair<int, ll> > > g(x);
    for (ll i = 0; i < x; i++)
    {
        if (i > r) continue;
        if (i >= x) g[i].push_back({ i - x, 1ll });
        if (i + y <= r && i + y - x >= 0)
        {
            g[i].push_back({ (i + y - x) % x, (i + y - x) / x + 1 });
        }
    }
    vector<ll> dist(x, -1);
    queue<int> q;
    q.push(k % x);
    dist[q.front()] = k / x;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (pair<int, ll> i : g[f])
        {
            if (dist[i.first] != -1) end(true);
            dist[i.first] = dist[f] + i.second;
            q.push(i.first);
        }
    }
    if (*max_element(dist.begin(), dist.end()) >= t) end(true);
    else end(false);
    return 0;
}