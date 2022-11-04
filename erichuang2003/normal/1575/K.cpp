#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

const int P = 1000000007, Q = P - 1;

int mpow(int x, int k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m, k, r, c; std::cin >> n >> m >> k >> r >> c;
	int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;
	int ed = r * (ull)c % Q;
	if (x1 == x2 && y1 == y2) ed = 0;
	int ord = n * (ull)m % Q; if ((ord -= ed) < 0) ord += Q;
	std::cout << mpow(k, ord) << '\n';

	return 0;
}