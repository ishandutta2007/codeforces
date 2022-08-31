#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class Point
{

public:

	long long x, y;
	
};

int main()
{
//	freopen("in", "rt", stdin);
//	freopen("out", "wt", stdout);
	int n;
	cin >> n;
	long long q;
	cin >> q;
	q %= (2*n);
	long long x, y;
	cin >> x >> y;
	vector <Point> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	if (q % 2 == 1)
	{
		x = -x;
		y = -y;
	}
	for (int i = 0; i < q; ++i)
	{
		int j = i % n;
		if ((q - i) % 2 == 0)
		{
			x -= 2 * a[j].x;
			y -= 2 * a[j].y;
		}
		else
		{
			x += 2 * a[j].x;
			y += 2 * a[j].y;
		}
	}
	cout << x << ' ' << y << '\n';
	return 0;
}