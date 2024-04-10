#include <iostream>
#include <vector>

typedef double long dl;
typedef long long ll;

using namespace std;

const ll INF = 1e9;
const dl eps = 1e-9;

struct vec {
	dl x, y;
	void read() {
		cin >> x >> y;
	}
	vec operator - (vec a) {
		return { x - a.x, y - a.y };
	}
	int operator % (vec a) {
		ll val = (x * a.y - y * a.x);
		if (val > 0) return 1;
		if (val < 0) return -1;
		return 0;
	}
};

struct lane {
	dl A, B, C;
};

int main() {
	vec S, F;
	S.read(), F.read();
	int n;
	cin >> n;
	vector <lane> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].A >> a[i].B >> a[i].C;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		vec C;
		vec D = { -a[i].B, a[i].A };
		if (abs(a[i].A) > eps) C = { -a[i].C / a[i].A, 0 };
		if (abs(a[i].B) > eps) C = { 0, -a[i].C / a[i].B };
		int hm1 = (S - C) % D;
		int hm2 = (F - C) % D;
		if (hm1 * hm2 < 0) ans++;
	}
	cout << ans;
	return 0;
}