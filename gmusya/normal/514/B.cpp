#include <iostream>
#include <vector>

using namespace std;

struct point {
	int x, y;
};
bool check_line(point A, point B, point O) {
	return ((A.x - B.x) * (O.y - B.y) == (O.x - B.x) * (A.y - B.y));
}

int main() {
	int n;
	point O;
	cin >> n >> O.x >> O.y;
	vector <point> a(n);
	vector <bool> used(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (used[i])
			continue;
		cnt++;
		for (int j = 0; j < n; j++) {
			if (used[j])
				continue;
			used[j] = check_line(a[i], a[j], O);
		}
	}
	cout << cnt;
	return 0;
}