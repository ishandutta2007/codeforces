#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

class point
{
public:
    ll x, y; 
    point(ll X, ll Y) : x(X), y(Y) {}
    point() {}
};
bool up(const point& a)
{
    return a.y > 0 || (a.y == 0 && a.x > 0);
}
ll orientation(const point& p1, const point& p2, const point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}
point o(0, 0);
bool cmp(const pair<point, int>& a, const pair<point, int>& b)
{
    int aup = up(a.first), bup = up(b.first);
    if (aup != bup) return aup > bup;
    return orientation(o, a.first, b.first) > 0;
}
ll choose2(ll n)
{
    return (n * (n - 1)) / 2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        vector<pair<point, int> > u;
        ll cu = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            point tmp(v[j].x - v[i].x, v[j].y - v[i].y);
            cu += up(tmp);
            u.push_back({ tmp, -1 });
            u.push_back({ { -tmp.x, -tmp.y}, 1 });
        }
        sort(u.begin(), u.end(), cmp);
        for (const pair<point, int>& j : u)
        {
            cu += j.second;
            if (j.second == -1)
            {
                //cout << cu << ": " << choose2(n - 2 - cu) << " " << choose2(cu) << "\n";
                ans += choose2(n - 2 - cu) * choose2(cu);
            }
        }
    }
    cout << ans / 2ll << "\n";
    return 0;
}