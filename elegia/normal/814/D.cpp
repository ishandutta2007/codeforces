#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <queue>
#include <functional>
#include <numeric>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct Pt2i {
	int x, y, r;

	bool operator<(const Pt2i &rhs) const;

	bool operator>(const Pt2i &rhs) const;

	bool operator<=(const Pt2i &rhs) const;

	bool operator>=(const Pt2i &rhs) const;

	bool in(const Pt2i& o) const;
};

typedef long long ll;

const int N = 1010;

int n;
int dep[N];
Pt2i points[N];

ll sq(ll x) { return x * x; }

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d%d", &points[i].x, &points[i].y, &points[i].r);
	sort(points + 1, points + n + 1, greater<Pt2i>());
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i - 1; j; --j)
			if (points[i].in(points[j])) {
				dep[i] = dep[j] + 1;
				break;
			}
		if (dep[i] == 0 || (dep[i] & 1))
			ans += sq(points[i].r);
		else
			ans -= sq(points[i].r);
	}
	printf("%.9lf\n", ans * M_PI);
	return 0;
}

bool Pt2i::in(const Pt2i &o) const {
	ll dist2 = sq(x - o.x) + sq(y - o.y);
	ll r2 = sq(r + o.r);
	return dist2 < r2;
}

bool Pt2i::operator<(const Pt2i &rhs) const {
	return r < rhs.r;
}

bool Pt2i::operator>(const Pt2i &rhs) const {
	return rhs < *this;
}

bool Pt2i::operator<=(const Pt2i &rhs) const {
	return !(rhs < *this);
}

bool Pt2i::operator>=(const Pt2i &rhs) const {
	return !(*this < rhs);
}