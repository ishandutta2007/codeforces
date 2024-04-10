#include <cstdio>

#include <algorithm>

using namespace std;

typedef long long ll;

struct Point {
	int x, y, id;
	int tag;

	Point() {}

	Point(int x, int y) : x(x), y(y) {}

	bool operator<(const Point& rhs) const {
		return x < rhs.x;
	}

	Point operator-(const Point& rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}

	ll operator*(const Point& rhs) const {
		return x * (ll)rhs.y - y * (ll)rhs.x;
	}
};

const int N = 20010;

int n;
int match[N];
Point p[N];
Point rel;

void solve(int l, int k);
bool cmp(const Point& lhs, const Point& rhs);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
		p[i].tag = 1;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i + n].x, &p[i + n].y);
		p[i + n].id = i;
		p[i + n].tag = -1;
	}
	solve(1, n * 2);
	for (int i = 1; i <= n; ++i)
		printf("%d\n", match[i]);
	return 0;
}

void solve(int l, int k) {
	if (k == 0)
		return;
	swap(p[l], *min_element(p + l, p + l + k));
	rel = p[l];
	sort(p + l + 1, p + l + k, cmp);
	int cnt = p[l].tag;
	int i = l + 1;
	for (; i < l + k; ++i) {
		cnt += p[i].tag;
		if (cnt == 0 && p[i].tag == -p[l].tag)
			break;
	}
//	printf("FIND %d\n", i);
	if (p[i].tag == 1)
		match[p[i].id] = p[l].id;
	else
		match[p[l].id] = p[i].id;
	solve(l + 1, i - l - 1);
	solve(i + 1, k - (i - l - 1) - 2);
}

bool cmp(const Point& lhs, const Point& rhs) {
	return (lhs - rel) * (rhs - rel) > 0;
}