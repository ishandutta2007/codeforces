#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

struct Rectangle {
	ll x = 0;
	ll y = 0;
	ll a = 0;

	friend istream& operator>>(istream& in, Rectangle& rectangle) {
		return in >> rectangle.x >> rectangle.y >> rectangle.a;
	}

	bool operator<(const Rectangle& rectangle) const {
		if (x != rectangle.x) {
			return x < rectangle.x;
		}
		return y < rectangle.y;
	}
};

vector<ll> ans;
vector<Rectangle> rectangles;

ll func(int old_ind, int new_ind) {
	return ans[old_ind] + (rectangles[new_ind].x - rectangles[old_ind].x) * rectangles[new_ind].y - rectangles[new_ind].a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	rectangles.resize(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> rectangles[i];
	}
	sort(rectangles.begin(), rectangles.end());
	ans.resize(n + 1);
	int st = 0, fi = 0;
	vector<int> cht(n + 1);
	for (int i = 1; i <= n; ++i) {
		while (st < fi && func(cht[st], i) < func(cht[st + 1], i)) {
			++st;
		}
		if (st <= fi) {
			ans[i] = max(func(cht[st], i), rectangles[i].x * rectangles[i].y - rectangles[i].a);
		} else {
			ans[i] = rectangles[i].x * rectangles[i].y - rectangles[i].a;
		}
		while (st < fi) {
			int ind1 = cht[fi - 1];
			int ind2 = cht[fi];
			__int128 val1 = static_cast<__int128>(ans[ind1] - ans[ind2]) * static_cast<__int128>(rectangles[i].x - rectangles[ind2].x);
			__int128 val2 = static_cast<__int128>(ans[ind2] - ans[i]) * static_cast<__int128>(rectangles[ind2].x - rectangles[ind1].x);
			if (val1 < val2) {
				break;
			} else {
				--fi;
			}
		}
		cht[++fi] = i;
	}
	cout << *max_element(ans.begin(), ans.end());
	return 0;
}

/*
4
1 4 3
2 3 3
3 2 5
4 1 2
 */