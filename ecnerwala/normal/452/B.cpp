#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

inline int sq(int a) {
	return a * a;
}

inline double dist(pii a, pii b) {
	return sqrt(double(sq(a.A - b.A) + sq(a.B - b.B)));
}

int N, M;

inline bool inRange(int a, int v) { return 0 <= a && a <= v; }

inline bool inRange(pii a) { return inRange(a.A, N) && inRange(a.B, M); }

vector<pii> pts;
int main() {
	cin >> N >> M;
	pii cur;
	vector<int> x, y;
	for(int i = 0; i < 4; i++) {
		if(i <= N) {
			x.push_back(i);
			x.push_back(N - i);
		}
		if(i <= M) {
			y.push_back(i);
			y.push_back(M - i);
		}
	}

	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());

	sort(y.begin(), y.end());
	y.resize(unique(y.begin(), y.end()) - y.begin());

	vector<pii> pts;
	for(int i = 0; i < int(x.size()); i++) {
		for(int j = 0; j < int(y.size()); j++) {
			pts.push_back(pii(x[i], y[j]));
		}
	}

	sort(pts.begin(), pts.end());
	pts.resize(unique(pts.begin(), pts.end()) - pts.begin());

	double res = -1;

	pii a, b, c, d;

	for(pii i : pts) {
		for(pii j : pts) {
			if(j == i) continue;
			for(pii k : pts) {
				if(k == i || k == j) continue;
				for(pii l : pts) {
					if(l == i || l == j || l == k) continue;
					double val = dist(i, j) + dist(j, k) + dist(k, l);
					if(val > res) {
						res = val;
						a = i, b = j, c = k, d = l;
					}
				}
			}
		}
	}
	cout << a.A << ' ' << a.B << '\n';
	cout << b.A << ' ' << b.B << '\n';
	cout << c.A << ' ' << c.B << '\n';
	cout << d.A << ' ' << d.B << '\n';
	return 0;
}