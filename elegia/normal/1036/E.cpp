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

typedef long long num;

struct vec2d {
    num x, y;
 
    vec2d() {}
 
    vec2d(num x, num y) : x(x), y(y) {}
 
    num len() const {
        return sqrt(x * x + y * y);
    }
 
    vec2d rot90() const {
        return vec2d(-y, x);
    }
 
    vec2d rot90(const vec2d& v) const {
        return (*this - v).rot90() + v;
    }
 
    vec2d operator-() const {
        return vec2d(-x, -y);
    }
 
    vec2d operator+(const vec2d& v) const {
        return vec2d(x + v.x, y + v.y);
    }
 
    vec2d operator-(const vec2d& v) const {
        return vec2d(x - v.x, y - v.y);
    }
 
    vec2d operator+=(const vec2d& v) {
        x += v.x;
        y += v.y;
        return *this;
    }
 
    vec2d operator-=(const vec2d& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
 
    vec2d operator*(num a) const {
        return vec2d(x * a, y * a);
    }
 
    vec2d operator/(num a) const {
        return vec2d(x / a, y / a);
    }
 
    num operator^(const vec2d& v) const {
        return x * v.x + y * v.y;
    }
 
    num operator*(const vec2d& v) const {
        return x * v.y - y * v.x;
    }
 
    friend vec2d operator*(num a, const vec2d& v) {
        return vec2d(a * v.x, a * v.y);
    }
 
    num angle(vec2d u, vec2d v) const {
        u -= *this;
        v -= *this;
        return acos((u / u.len()) ^ (v / v.len()));
    }
 
    friend vec2d intersect(const vec2d& p1, const vec2d& p2, const vec2d& q1, const vec2d& q2) {
        num a1 = (q1 - p1) * (q2 - q1), a2 = (p2 - q1) * (q2 - p2);
        return (p2 - p1) * a1 / (a1 + a2) + p1;
    }
};

const int N = 1010;

int n;
int x1[N], y1[N], x2[N], y2[N];
vec2d v1[N], v2[N];
pair<int, int> pts[N * N];

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
#ifdef LBT
	freopen("test.in", "r", stdin);
	int nol_cl = clock();
#endif

	scanf("%d", &n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		v1[i] = vec2d(x1[i], y1[i]);
		v2[i] = vec2d(x2[i], y2[i]);
		if (x1[i] > x2[i]) {
			swap(x1[i], x2[i]);
			swap(y1[i], y2[i]);
		}
		int dx = x2[i] - x1[i], dy = y2[i] - y1[i];
		if (dy < 0)
			dy = -dy;
		ans += gcd(dx, dy) + 1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j) {
			if ((v1[i] - v2[i]) * (v1[j] - v2[j]) != 0) {
				vec2d po = intersect(v1[i], v2[i], v1[j], v2[j]);
				int xx = po.x, yy = po.y;
				vec2d rp = vec2d(xx, yy);
				if ((v1[i] - v2[i]) * (v1[i] - rp) == 0 && (v1[j] - v2[j]) * (v1[j] - rp) == 0) {
					if (x1[i] <= xx && xx <= x2[i] && x1[j] <= xx && xx <= x2[j] && min(y1[i], y2[i]) <= yy && yy <= max(y1[i], y2[i]) && min(y1[j], y2[j]) <= yy && yy <= max(y1[j], y2[j]))
						pts[cnt++] = make_pair(xx, yy);
				}
			}
		}
	sort(pts, pts + cnt);
	for (int i = 0; i < cnt; ++i) {
		int r = i;
		while (r + 1 < cnt && pts[r + 1] == pts[i])
			++r;
		int k = 2;
		while (k * (k - 1) / 2 < (r - i + 1))
			++k;
		ans -= k - 1;
		i = r;
	}
	printf("%lld\n", ans);

#ifdef LBT
	LOG("Time: %dms\n", int((clock() - nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
	return 0;
}