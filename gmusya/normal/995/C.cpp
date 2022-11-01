#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

using ll = long long;

mt19937_64 rnd(time(nullptr));

const int K = 1;
const ll LIM = 2.25e12;

struct Point {
	int x, y;

	Point operator+(const Point& point) const {
		return {x + point.x, y + point.y};
	}

	Point operator-(const Point& point) const {
		return {x - point.x, y - point.y};
	}

	friend istream& operator>>(istream& in, Point& point) {
		return in >> point.x >> point.y;
	}

	ll Mod() const {
		return x * 1ll * x + y * 1ll * y;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<Point> vectors(n + K, {0, 0});
	for (int i = 0; i < n; ++i) {
		cin >> vectors[i];
	}
	Point position{0, 0};
	vector<int> c(n + K);
	for (int i = 0; i < n; ++i) {
		vector<pair<ll, int>> variants;
		for (int mask = 0; mask < (1 << (K + 1)); ++mask) {
			Point new_position = position;
			for (int j = 0; j <= K; ++j) {
				if (mask & (1 << j)) {
					new_position = new_position + vectors[i + j];
				} else {
					new_position = new_position - vectors[i + j];
				}
			}
			variants.emplace_back(new_position.Mod(), mask);
		}
		if (min_element(variants.begin(), variants.end())->second & 1) {
			c[i] = 1;
			position = position + vectors[i];
		} else {
			c[i] = -1;
			position = position - vectors[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << c[i] << ' ';
	}
	return 0;
}