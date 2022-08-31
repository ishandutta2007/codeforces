#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

class Point
{
public:
	long long x, y;
};

int q[500][500] = {0};

bool cmp(Point a, Point b)
{
	return a.x < b.x;
}

int main()
{
//	freopen("in", "rt", stdin);
//	freopen("out", "wt", stdout);
	int n, m;
	cin >> n >> m;	
	vector <Point> a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < m; ++i)
		cin >> b[i].x >> b[i].y;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
		{
			if (a[i].x == a[j].x) continue;
			for (int k = 0; k < m; ++k)
				if ((b[k].y - a[i].y) * (a[j].x - a[i].x) < (a[j].y - a[i].y) * (b[k].x - a[i].x))
					if (b[k].x > a[i].x && b[k].x < a[j].x)
						q[i][j] += 2;
					else
					if (b[k].x == a[i].x || b[k].x == a[j].x)
						q[i][j]++;
		}
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			for (int k = j+1; k < n; ++k)
			{
				if (q[i][k] == q[i][j] + q[j][k])
					ans++;	
			}
	cout << ans << '\n';
	return 0;
}