#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using D = long double;
struct P{
	LL x, y, z;
	bool operator < (const P& p) const {
		return z == p.z ? (
			y == p.y ? x > p.x : y > p.y
		) : z > p.z;
	}
};
struct F{
	D a, b, c;
	F(D a = 0, D b = 0, D c = 0) : a(a), b(b), c(c) {
	}
	F(const P& p){
		a = p.x;
		b = p.y;
		c = p.z;
	}
	F operator * (D k) const {
		return {a * k, b * k, c * k};
	}
	F operator + (const F& f) const {
		return {a + f.a, b + f.b, c + f.c};
	}
	F operator - (const F& f) const {
		return {a - f.a, b - f.b, c - f.c};
	}
	F& operator += (const F& f) {
		a += f.a;
		b += f.b;
		c += f.c;
		return *this; 
	}
	F& operator -= (const F& f) {
		a -= f.a;
		b -= f.b;
		c -= f.c;
		return *this; 
	}
	D operator()(D x) {
		return (a * x + b) * x + c;
	}
	F cross(const F& f) const {
		return {
			a * f.b - b * f.a,
			b * f.c - c * f.b,
			c * f.a - a * f.c
		};
	}
	D norm() const{
		return sqrt(a * a + b * b + c * c);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	vector<P> p(n);
	for (auto& [x, y, z] : p)
		cin >> x >> y >> z;
	int m;
	cin >> m;
	vector t(m, vector<int>(3));
	vector df(m, vector<F>(3));
	vector G(n, vector<vector<int>>(3));
	for (int i = 0; i < m; i += 1) {
		for (int& tj : t[i]) {
			cin >> tj;
			tj -= 1;
		}
		sort(t[i].begin(), t[i].end(), [&](int x, int y) {
			return p[x] < p[y];
		});
		vector<F> tp(3);
		for (int j = 0; j < 3; j += 1) tp[j] = p[t[i][j]];
		D s = (tp[1] - tp[0]).cross(tp[2] - tp[0]).norm() / 2;
		if (tp[0].c == tp[2].c)
			df[i][0].c = s;
		else if (tp[0].c == tp[1].c) {
			D dh = tp[1].c - tp[2].c;
			D a = s / (dh * dh);
			df[i][1] = {-a, 2 * a * tp[2].c, s - a * tp[2].c * tp[2].c};
			df[i][2] = {0, 0, s};
			df[i][2] -= df[i][1];
		}
		else if (tp[1].c == tp[2].c) {
			D dh = tp[0].c - tp[1].c;
			D a = s / (dh * dh);
			df[i][0] = {a, -2 * a * tp[0].c, a * tp[0].c * tp[0].c};
			df[i][1] = {0, 0, s};
			df[i][1] -= df[i][0];
		}
		else {
			D h1 = tp[0].c - tp[1].c;
			D h2 = tp[1].c - tp[2].c;
			F f = tp[0] + (tp[2] - tp[0]) * (h1 / (h1 + h2));
			D s1 = (tp[1] - tp[0]).cross(f - tp[0]).norm() / 2;
			D s2 = (tp[1] - tp[2]).cross(f - tp[2]).norm() / 2;
			D a1 = s1 / (h1 * h1);
			D a2 = s2 / (h2 * h2);
			df[i][0] = {a1, -2 * a1 * tp[0].c, a1 * tp[0].c * tp[0].c};
			df[i][1] = {-a2, 2 * a2 * tp[2].c, s - a2 * tp[2].c * tp[2].c};
			df[i][2] = {0, 0, s};
			df[i][2] -= df[i][1];
			df[i][1] -= df[i][0];
		}
		for (int j = 0; j < 3; j += 1)
			G[t[i][j]][j].push_back(i);
	}
	int q;
	cin >> q;
	vector<LL> h(q);
	vector<int> pq(q), f(n), pv(n + q), qv(q);
	vector<vector<int>> Q(n);
	for (int i = 0; i < q; i += 1) {
		cin >> h[i] >> pq[i];
		qv[i] = i;
		pv[n + i] = n + i;
		pq[i] -= 1;
		Q[pq[i]].push_back(i);
	}
	vector<D> ans(q, -1);
	vector<F> cf(n);
	for (int i = 0; i < n; i += 1)
		pv[i] = f[i] = i;
	function<int(int)> ff = [&](int u) {
		return f[u] == u ? u : f[u] = ff(f[u]);
	};
	sort(pv.begin(), pv.end(), [&](int x, int y){
		LL px = x >= n ? h[x - n] : p[x].z;
		LL py = y >= n ? h[y - n] : p[y].z;
		return px != py ? px > py : x > y;
	});
	for (int i : pv) {
		if (i < n) {
			int u = i;
			for (int j = 0; j < 3; j += 1) {
				for (int x : G[i][j]) {
					for (int y = 0; y < j; y += 1) {
						int v = t[x][y];
						int fu = ff(u), fv = ff(v);
						if (fu != fv) {
							f[fu] = fv;
							cf[fv] += cf[fu];
						}
					}
					int fu = ff(u);
					cf[fu] += df[x][j];
				}
			}
		}
		else {
			i -= n;
			if (h[i] < p[pq[i]].z) {
				int u = ff(pq[i]);
				ans[i] = cf[u](h[i]);
			}
			i += n;
		}
	}
	for (D d : ans)
		if (d < -0.9) cout << "-1\n";
		else cout << d << "\n";
	return 0;
}