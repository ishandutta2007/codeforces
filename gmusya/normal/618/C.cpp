#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll INF = 4e18 + 2;

struct vec {
	ll x, y;
	void read() {
		cin >> x >> y;
	}
	vec operator - (vec a) {
		return { x - a.x, y - a.y };
	}
	ll operator % (vec a) {
		return (x * a.y - y * a.x);
	}
	bool operator == (vec a) {
		return a.x == x && a.y == y;
	}
};

int main() {
	int n;
	cin >> n;
	vector <vec> p(n);
	for (int i = 0; i < n; i++)
		p[i].read();
	vec a = p[0], b = p[1];
	pair <ll, int> ans = { INF, -1 };
	for (int i = 2; i < n; i++) {
		vec c = p[i];
		ll s = (c - b) % (a - b);
		s = abs(s);
		if (s == 0) continue;
		if (ans.second == -1) ans = { s, i };
		ans = min(ans, { s, i });
	}
	int idb = ans.second;
	b = p[idb];
	ans = { INF, -1 };
	for (int i = 1; i < n; i++) {
		if (i == idb) continue;
		vec c = p[i];
		ll s = (c - b) % (a - b);
		s = abs(s);
		if (s == 0) continue;
		if (ans.second == -1) ans = { s, i + 1 };
		ans = min(ans, { s, i + 1});
	}
	cout << 1 << " " << idb + 1 << " " << ans.second;
	return 0;
}