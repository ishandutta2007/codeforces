#include <iostream>
#include <algorithm>
#define x first
#define y second

using namespace std;

int n, i, j, t, zone;

long long rez;

pair<int, int> a[200005], b;

typedef long long ll;

int area(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	ll arie = (ll) a.x * (ll) (b.y - c.y) + (ll) b.x * (ll) (c.y - a.y) + (ll) c.x * (ll) (a.y - b.y);
	if (arie < 0)
		return -1;
	if (arie > 0)
		return 1;
	return 0;
}

int main() {
	cin >> n;
	for (i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y;
	for (i = n + 1; i <= 2 * n; ++i)
		a[i] = a[i - n];
	
	cin >> t;
	while (t--) {
		cin >> b.x >> b.y;

		for (i = 2; i <= n; ++i)
			if (area(a[i - 1], a[i], b) != area(a[i], a[i + 1], b))
				break;
		if (i <= n) {
			cout << "0\n";
			continue;
		}

		zone = area(a[1], a[2], b);
		for (i = 2; i <= n; ++i)
			if (area(a[1], a[i], b) != zone)
		
				break;

		rez = (long long) n * (long long) (n - 1) * (long long) (n - 2) / 3;
		//fprintf(stderr, "%lld\n", rez);
		j = i;
		for (i = 1; i <= n; ++i) {
			while (area(a[i], a[j], b) == zone)
				++j;
			//fprintf(stderr, "%d ->", j);
			rez -= (long long) (j - i - 1) * (long long) (j - i - 2) / 2;//fprintf(stderr, "%lld ", rez);
			rez -= (long long) (n - j + i - 1) * (long long) (n - j + i) / 2;//fprintf(stderr, "%lld\n", rez);
			}
		rez /= 2;
		cout << rez << "\n";
	}
}