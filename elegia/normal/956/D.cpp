#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Frac {
	int a, b;

	Frac() {}

	Frac(int a, int b) : a(a), b(b) {
		if (b < 0) {
			this->a = -a;
			this->b = -b;
		}
	}

	bool operator==(const Frac &rhs) const {
		return a * (ll)rhs.b == b * (ll)rhs.a;
	}

	bool operator!=(const Frac &rhs) const {
		return !(rhs == *this);
	}

	bool operator<(const Frac &rhs) const {
		return a * (ll)rhs.b < rhs.a * (ll)b;
	}

	bool operator>(const Frac &rhs) const {
		return rhs < *this;
	}

	bool operator<=(const Frac &rhs) const {
		return !(rhs < *this);
	}

	bool operator>=(const Frac &rhs) const {
		return !(*this < rhs);
	}
};

struct Node {
	Frac x, y;

	Node() {}

	Node(const Frac &x, const Frac &y) : x(x), y(y) {}
};

bool cmp(const Node& lhs, const Node& rhs) {
	if (lhs.x != rhs.x)
		return lhs.x < rhs.x;
	return lhs.y > rhs.y;
}

const int N = 100010;

int n;
ll ans;
int x[N], v[N];
Frac s[N];
Node a[N];
int fw[N];

int lowBit(int k) {
	return k & -k;
}

void change(int k) {
	for (; k <= n; k += lowBit(k))
		++fw[k];
}

int query(int k) {
	int ret = 0;
	for (; k; k -= lowBit(k))
		ret += fw[k];
	return ret;
}

int main() {
	int w;
	scanf("%d%d", &n, &w);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &v[i]);
		a[i].x = Frac(x[i], v[i] + w);
		s[i] = a[i].y = Frac(x[i], v[i] - w);
	}
	sort(s + 1, s + n + 1);
	sort(a + 1, a + n + 1, cmp);
	for (int i = n; i; --i) {
		int ind = lower_bound(s + 1, s + n + 1, a[i].y) - s;
		ans += query(ind);
		change(ind);
	}
	printf("%lld\n", ans);
	return 0;
}