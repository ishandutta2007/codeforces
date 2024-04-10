#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
typedef long long ll;
typedef long double ld;
using namespace std;

class point
{
public:
	ll x, y;
	int i;
};
ll dist(point& a, point &b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].x >> v[i].y;
		v[i].i = i;
	}
	vector<int> p(1, 0);
	vector<bool> vis(n, false);
	vis[0] = true;
	for (int i = 1; i < n; i++)
	{
		point best = v[p.back()];
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && dist(v[j], v[p.back()]) >= dist(best, v[p.back()]))
			{
				best = v[j];
			}
		}
		p.push_back(best.i);
		vis[best.i] = true;
	}
	for (int i = 0; i < n; i++) cout << p[i] + 1 << " ";
	cout << "\n";
	return 0;
}