#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		int A, B, C, res = 2e9;
		for (int i = 1; i <= c; i++) {
			// a = i;
			int tb, tc;
			int cnt = abs(a - i);
			for (int j = i; j < c + i; j += i) {
				int vb = abs(b - j);
				int t = c / j, sc, vc;
				if (abs(t * j - c) < abs((t + 1) * j - c)) {
				    sc = t * j, vc = abs(t * j - c);
				} else sc = (t + 1) * j, vc = abs((t + 1) * j - c);
				if (vb + vc + cnt < res) res = vb + vc + cnt, A = i, B = j, C = sc; 
			}
		}
		printf("%d\n%d %d %d\n", res, A, B, C);
	}
	return 0;
}