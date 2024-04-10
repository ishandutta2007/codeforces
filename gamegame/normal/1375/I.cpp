#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

typedef int ftype;
typedef complex<ftype> point;
typedef complex<point> quater;
#define X real()
#define Y imag()
#define qs X.X
#define qx X.Y
#define qy Y.X
#define qz Y.Y

namespace std {
	quater operator * (quater a, quater b) {
		return {(a.X * b.X - a.Y * conj(b.Y)) / (int)2,
				(a.X * b.Y + a.Y * conj(b.X)) / (int)2};
	}
	quater conj(quater x) {
		return {conj(x.X), -x.Y};
	}
	ftype norm(quater x) {
		return (x * conj(x)).qs / 2;
	}
	quater operator *(quater a, ftype b) {
		return {{a.qs * b, a.qx * b}, {a.qy * b, a.qz * b}};
	}
	quater operator /(quater a, ftype b) {
		return {{a.qs / b, a.qx / b}, {a.qy / b, a.qz / b}};
	}
	quater operator /(quater a, quater b) {
		return a * conj(b) / norm(b);
	}
	bool operator != (quater a, ftype s) {
		return a != point(s);
	}
	const int K = 1;
	quater operator %(quater a, quater b) {
		quater d = a / b;
		quater res = a;
		for(int s = -K; s <= K; s++) {
			for(int i = -K; i <= K; i++) {
				for(int j = -K; j <= K; j++) {
					for(int k = -K; k <= K; k++) {
						bool A = (d.qs + s) % 2;
						bool B = (d.qx + i) % 2;
						bool C = (d.qy + j) % 2;
						bool D = (d.qz + k) % 2;
						if(A == B && B == C && C == D) {
							quater gd = {{d.qs + s, d.qx + i}, {d.qy + j, d.qz + k}};
							quater cand = a - gd * b;
							if(norm(cand) < norm(res)) {
								res = cand;
							}
						}
					}
				}
			}
		}
		
		assert(2 * norm(res) <= norm(b));
		return res;
	}
}

quater vec(ftype x, ftype y, ftype z) {
	return {{0, 2 * x}, {2 * y, 2 * z}};
}
quater scal(ftype s) {
	return {{2 * s, 0}, {0, 0}};
}

quater ex = vec(1, 0, 0);
quater ey = vec(0, 1, 0);
quater ez = vec(0, 0, 1);

void print(quater a) {
	cout << a.qx / 2 << ' ' << a.qy / 2 << ' ' << a.qz / 2 << endl;
}

vector<ftype> divs(ftype n) {
	vector<ftype> ans;
	for(int z = 1; z * z <= n; z++) {
		if(n % z == 0) {
			ans.push_back(z);
			ans.push_back(n / z);
		}
	}
	return ans;
}
ftype max_sq(ftype n) {
	ftype ans = 1;
	for(ftype z = 1; z * z * z <= n; z++) {
		if(n % z == 0) {
			int t = sqrt(n / z);
			if(t * t == n / z) {
				ans = max(ans, t);
			}
			if(n / z % z == 0) {
				ans = max(ans, z);
			}
		}
	}
	return ans;
}

void solve_proven(vector<quater> r) {
	int n = r.size();
	quater g = (point)0;
	ftype Gn = 0;
	for(int i = 0; i < n; i++) {
		g = __gcd(g, r[i]);
		Gn = __gcd(Gn, norm(r[i]));
	}
	ftype k = 1, nq = 1;
	ftype mxk = __gcd(__gcd(abs(g.qs), abs(g.qx)),
					  __gcd(abs(g.qy), abs(g.qz)));
	g /= point(mxk);
	ftype a = abs(g.qs) % 2, b = abs(g.qx) % 2;
	ftype c = abs(g.qy) % 2, d = abs(g.qz) % 2;
	if(a != b || a != c || a != d) {
		mxk /= 2;
		g *= point(2);
	}
	ftype t = max_sq(Gn);
	for(auto cnq: divs(t)) {
		quater cand = __gcd(g, scal(cnq));
		ftype ck = t / cnq;
		for(auto it: r) {
			auto jt = cand * it / cnq * conj(cand) / cnq;
			if(conj(cand) * jt * cand == it && ck) {
				ck = __gcd(ck, __gcd(abs(jt.qx), __gcd(abs(jt.qy), abs(jt.qz))));
			} else {
				ck = 0;
			}
		}
		if(ck * cnq > k * nq) {
			k = ck, nq = cnq;
		}
	}
	quater ans = conj(__gcd(g, scal(nq)));
	assert(norm(ans) == nq);
	cout << norm(point(k) * ans * conj(ans) / point(2)) << endl;
	print(point(k) * ans * vec(1, 0, 0) * conj(ans) / point(2));
	print(point(k) * ans * vec(0, 1, 0) * conj(ans) / point(2));
	print(point(k) * ans * vec(0, 0, 1) * conj(ans) / point(2));
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<quater> r(n);
	for(int i = 0; i < n; i++) {
		ftype x, y, z;
		cin >> x >> y >> z;
		r[i] = vec(2 * x, 2 * y, 2 * z);
	}
	solve_proven(r);
	return 0;
}