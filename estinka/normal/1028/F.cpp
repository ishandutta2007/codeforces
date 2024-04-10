#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

const int maxc = 113000;
int gcd(int x, int y)
{
    if (x < y) swap(x, y);
    while (y)
    {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}
class query
{
public:
    int t, x, y;
};
pair<int, int> normalize(pair<int, int> p)
{
    int g = gcd(p.first, p.second);
    p.first /= g; p.second /= g;
    return p;
}
pair<int, int> midpoint(pair<int, int> p1, pair<int, int> p2)
{
    p1.first += p2.first; p1.second += p2.second;
    return normalize(p1);
}
map<pair<int, int>, int> s, l;
map<ll, vector<pair<int, int> > > c;
int points = 0;
void new_point(ll dist, int delta, pair<int, int> b)
{
    pair<int, int> p = normalize(b);
    l[p] += delta;
    for (pair<int, int> j : c[dist])
    {
        pair<int, int> mid = midpoint(b, j);
        s[mid] += delta;
    }
    points += delta;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<query>v(q);
    for (int i = 0; i < q; i++) cin >> v[i].t >> v[i].x >> v[i].y;
    for (int i = 0; i < q; i++)
    {
        if (v[i].t == 1)
        {
            ll dist = v[i].x * 1ll * v[i].x + v[i].y * 1ll * v[i].y;
            new_point(dist, 1, { v[i].x, v[i].y });
            c[dist].push_back({ v[i].x, v[i].y });
        }
        else if (v[i].t == 2)
        {
            ll dist = v[i].x * 1ll * v[i].x + v[i].y * 1ll * v[i].y;
            c[dist].erase(find(c[dist].begin(), c[dist].end(), make_pair( v[i].x, v[i].y )));
            new_point(dist, -1, { v[i].x, v[i].y });

        }
        else
        {
            tie(v[i].x, v[i].y) = normalize({ v[i].x, v[i].y });
            cout << points - s[{v[i].x, v[i].y}] * 2 - l[{v[i].x, v[i].y}] << "\n";
        }
    }
    return 0;
}