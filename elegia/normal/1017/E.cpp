#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <queue>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Vec {
	int x, y;
	
	Vec() : x(), y() {}
	
	Vec(int x, int y) : x(x), y(y) {}
	
	Vec(const Vec& v) : x(v.x), y(v.y) {}
	
	Vec operator-() const { return Vec(-x, -y); }
	
	Vec operator+(const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
	Vec operator-(const Vec& rhs) const { return *this + -rhs; }

	ll operator^(const Vec& rhs) const { return x * (ll)rhs.x + y * (ll)rhs.y; }
	ll operator*(const Vec& rhs) const { return x * (ll)rhs.y - y * (ll)rhs.x; }
	
	bool operator==(const Vec& rhs) const { return x == rhs.x && y == rhs.y; }
	
	ll norm() const { return x * (ll)x + y * (ll)y; }
};

int n, m;

bool cmpX(const Vec& lhs, const Vec& rhs) { return lhs.x < rhs.x; }

vector<pair<ll, ll> > convex(vector<Vec> seq);
vector<Vec> hull(const vector<Vec>& seq, int sign);

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	vector<Vec> a(n), b(m);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &b[i].x, &b[i].y);
	vector<pair<ll, ll> > p = convex(a), q = convex(b);
	n = p.size(), m = q.size();
	if (n != m) {
		puts("NO");
		return 0;
	}
	q.insert(q.end(), q.begin(), q.end());
	vector<int> fail(n);
	int k = 0;
	for (int i = 1; i < n; ++i) {
		while (k && p[i] != p[k])
			k = fail[k - 1];
		if (p[i] == p[k])
			++k;
		fail[i] = k;
	}
	int cur = 0;
	for (int i = 0; i < n * 2; ++i) {
		while (cur && q[i] != p[cur])
			cur = fail[cur - 1];
		if (q[i] == p[cur])
			if (++cur == n) {
				puts("YES");
				return 0;
			}
	}
	puts("NO");
#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}

vector<pair<ll, ll> > convex(vector<Vec> seq) {
	sort(seq.begin(), seq.end(), cmpX);
	vector<Vec> a = hull(seq, 1), b = hull(seq, -1);
	reverse(a.begin(), a.end());
	a.insert(a.end(), b.begin(), b.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	if (a.size() > 1 && a.front() == a.back())
		a.pop_back();
	vector<pair<ll, ll> > ret;
	int n = a.size();
	for (int i = 0; i < n; ++i)
		ret.emplace_back((a[(i + 1) % n] - a[i]).norm(), (a[(i + 2) % n] - a[(i + 1) % n]) ^ (a[(i + 1) % n] - a[i]));
	return ret;
}

vector<Vec> hull(const vector<Vec>& seq, int sign) {
	vector<Vec> ret;
	int n = seq.size(), top = 0;
	for (int i = 0; i < n; ++i) {
		if (!ret.empty() && seq[i].x == ret.back().x)
			if ((seq[i].y - ret[top - 1].y) * sign >= 0) {
				ret.pop_back();
				--top;
			} else
				continue;
		while (top > 1 && (ret[top - 1] - ret[top - 2]) * (seq[i] - ret[top - 1]) * sign >= 0) {
			ret.pop_back();
			--top;
		}
		ret.push_back(seq[i]);
		++top;
	}
	return ret;
}