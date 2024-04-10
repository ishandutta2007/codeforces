#include<bits/stdc++.h>
using namespace std;

void wssert(bool b) {
	if (!b) {
		cout << "GARBAGE\n";
		exit(0);
	}
}

// first negate the problem, make the jellyfish have size
// we just need to see if there's a path of intersections between the two walls

// To check 2 jellies, we can do the difference trick again...
// We first take minkowski difference of the polygon with itself (double the edges)
// Then, you have a circle with radius r1 + r2 at the other point, and you want to see if it intersects
// (Wall case is a thicker wall at the other point)

using ll = long long;

struct point {
	int x, y;
	point() : x(0), y(0) {}
	point(int x_, int y_) : x(x_), y(y_) {}
	friend std::ostream& operator << (std::ostream& o, const point& p) {
		return o << "(" << p.x << "," << p.y << ")";
	}
	friend std::istream& operator >> (std::istream& i, point& p) {
		return i >> p.x >> p.y;
	}
	point operator - () const {
		return point(-x, -y);
	}
	point& operator += (const point& o) {
		x += o.x, y += o.y;
		return *this;
	}
	point& operator -= (const point& o) {
		x -= o.x, y -= o.y;
		return *this;
	}
	friend point operator + (const point& a, const point& b) { return point(a) += b; }
	friend point operator - (const point& a, const point& b) { return point(a) -= b; }

	friend bool operator == (const point& a, const point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator != (const point& a, const point& b) { return a.x != b.x || a.y != b.y; }

	ll norm() const {
		return ll(x) * ll(x) + ll(y) * ll(y);
	}
	int quad() const {
		assert(x != 0 || y != 0);
		if (x < 0 && y <= 0) return 1;
		if (y < 0 && x >= 0) return 2;
		if (x > 0 && y >= 0) return 3;
		if (y > 0 && x <= 0) return 4;
		assert(false);
		return 0;
	}
};

bool angle_cmp(const point& a, const point& b) {
	int qa = a.quad();
	int qb = b.quad();
	if (qa != qb) return qa < qb;
	ll cross = ll(a.x) * b.y - ll(a.y) * b.x;
	if (cross != 0) return cross > 0;
	return a.norm() < b.norm();
}

const int MAXN = 300;
const int MAXM = 300;

int W;

int N;
point P[2*MAXN];
point mink[2*MAXN];

bool intersects(point center, ll r) {
	assert(r > 0);
	if ((P[0] - center).norm() < r * r) return true;
	int numCross = 0;
	for (int a = 0; a < N; a++) {
		point p = P[a] - center;
		point q = P[a+1] - center;
		if (q.norm() < r * r) {
			return true;
		}

		// it's acute
		if (abs(p.norm() - q.norm()) < (q-p).norm()) {
			// we want to check if the area is correct
			// we want to check if r * sqrt((q-p).norm()) > p cross q
			// we want to check if sqrt((q-p).norm()) > (p cross q) / r
			// we want to check if sqrt((q-p).norm()) > floor((p cross q) / r)
			ll area = abs(p.x * q.y - p.y * q.x);
			if (r * r * (q-p).norm() > area * area) {
				return true;
			}
		}

		if ((p.x > 0) != (q.x > 0)) {
			if (q.x > 0) swap(p, q);
			assert(p.x > 0);
			assert(q.x <= 0);
			ll cross = ll(q.x) * p.y - p.x * q.y;
			if (cross == 0) {
				return true;
			}
			if (cross > 0) {
				numCross ++;
			}
		}
	}
	if (numCross & 1) {
		return true;
	}
	return false;
}

int M;
pair<point, int> J[MAXM];
const int MAXV = MAXM * 2;
int V;
int cap[MAXV][MAXV];
int vis[MAXV];

int flow() {
	int res = 0;
	while (true) {
		for (int i = 0; i < V; i++) {
			vis[i] = -1;
		}
		queue<int> q;
		vis[0] = 0;
		q.push(0);
		while (vis[V-1] == -1 && !q.empty()) {
			int cur = q.front(); q.pop();
			for (int nxt = V-1; nxt >= 0; nxt--) {
				if (vis[nxt] != -1) continue;
				if (!cap[cur][nxt]) continue;
				vis[nxt] = cur;
				q.push(nxt);
			}
		}
		if (vis[V-1] == -1) break;
		res++;
		for (int cur = V-1; cur != 0; cur = vis[cur]) {
			int prv = vis[cur];
			assert(prv != -1);
			cap[prv][cur] -= 1;
			cap[cur][prv] += 1;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> W;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	P[N] = P[0];
	cin >> M;
	for (int j = 0; j < M; j++) {
		cin >> J[j].first >> J[j].second;
	}

	for (int i = 0; i < N; i++) {
		mink[2*i+0] = P[i+1] - P[i];
		mink[2*i+1] = P[i] - P[i+1];
	}

	N *= 2;

	sort(mink, mink + N, angle_cmp);
	// first is build the minkowski polygon
	P[0] = {0, 0};
	for (int i = 0; i < N; i++) {
		P[i+1] = P[i] + mink[i];
	}
	assert(P[N] == P[0]);
	point mid = P[0] + P[N/2];
	assert(mid.x % 2 == 0 && mid.y % 2 == 0);
	mid.x /= 2;
	mid.y /= 2;
	for (int i = 0; i <= N; i++) {
		P[i] -= mid;
	}
	for (int i = 0; i < N / 2; i++) {
		assert(P[i] + P[i+N/2] == point(0, 0));
	}

	//for (int i = 0; i <= N; i++) { cerr << P[i] << '\n'; }

	V = 2 * M + 2;

	int maxX = P[0].x;
	for (int a = 0; a < N; a++) {
		maxX = max(maxX, P[a].x);
	}
	assert(maxX <= W);

	for (int j = 0; j < M; j++) {
		cap[2*j+1][2*j+2] = 1;
		if (maxX + J[j].second > J[j].first.x) {
			//cerr << "left" << ' ' << j << '\n';
			cap[0][2*j+1] = 1;
		}
		if (maxX + J[j].second > W - J[j].first.x) {
			//cerr << "right" << ' ' << j << '\n';
			cap[2*j+2][2*M+1] = 1;
		}
	}

	for (int j = 0; j < M; j++) {
		for (int k = j+1; k < M; k++) {
			point p = J[j].first - J[k].first;
			ll r = J[j].second + J[k].second;
			if (intersects(p, r)) {
				//cerr << j << ' ' << k << '\n';
				cap[2*j+2][2*k+1] = 1;
				cap[2*k+2][2*j+1] = 1;
			}
		}
	}
	int res = flow();
	cout << res << '\n';

	return 0;
}