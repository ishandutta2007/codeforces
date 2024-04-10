#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> b(m);
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}
	
	auto getCost = [&](const vector< vector<int> > &p) -> int {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int knt = p[i][0] == '#';
			for (int j = 1; j < m; j++) {
				knt += p[i][j] == '#' && p[i][j-1] == '.';
			}
			ans += (knt - a[i]) * (knt - a[i]);
		}
		for (int i = 0; i < m; i++) {
			int knt = p[0][i] == '#';
			for (int j = 1; j < n; j++) {
				knt += p[j][i] == '#' && p[j-1][i] == '.';
			}
			ans += (knt - b[i]) * (knt - b[i]);
		}
		return ans;
	};
	
	mt19937 rnd(42);
	
	vector< vector<int> > p(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			p[i][j] = (rnd() & 1) ? '.' : '#';
		}
	}
	
	int val = getCost(p);
	
	for (long double t = 2000.0; ; t *= 0.99995) {
		int v1, v2;
		v1 = rnd() % n;
		v2 = rnd() % m;
		
		p[v1][v2] = (p[v1][v2] == '.') ? '#' : '.';
		
		int nVal = getCost(p);
		
		if (nVal == 0) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << (p[i][j] == '.' ? '.' : '*');
				}
				cout << endl;
			}
			return 0;
		}
		
		int64_t delta = val - nVal;
		long double prob = (delta > 0) ? 1.0 : exp(delta / t);
		int64_t precision = 268435456;
		bool ok = rnd() % precision < (uint64_t)(prob * precision);
		
		if (ok) {
			val = nVal;
		} else {
			p[v1][v2] = (p[v1][v2] == '.') ? '#' : '.';
		}
	}
	
	return 0;
}