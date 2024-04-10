#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using ld = long double;

int n;
std::vector<ld> x, y, z;
ld x_ans, y_ans, z_ans;
ld answer = 0;

ld distance(ld x1, ld y1, ld z1, ld x2, ld y2, ld z2) {
	ld dx = (x1 - x2);
	ld dy = (y1 - y2);
	ld dz = (z1 - z2);
	return sqrtl(dx * dx + dy * dy + dz * dz);
}

ld f(ld x1, ld y1, ld z1) {
	ld sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = std::max(sum, distance(x[i], y[i], z[i], x1, y1, z1));
	}
	return sum;
}

const int ITERATIONS = 40;

ld solve3(ld x1, ld y1) {
	ld L = -1e4;
	ld R = 1e4;
	for (int i = 0; i < ITERATIONS; ++i) {
		ld M1 = (20 * L + 19 * R) / 39;
		ld M2 = (19 * L + 20 * R) / 39;
		ld ans1 = f(x1, y1, M1);
		ld ans2 = f(x1, y1, M2);
		if (ans1 < answer) {
			answer = ans1;
			x_ans = x1;
			y_ans = y1;
			z_ans = M1;
		}
		if (ans2 < answer) {
			answer = ans2;
			x_ans = x1;
			y_ans = y1;
			z_ans = M2;
		}
		if (ans1 > ans2) {
			L = M1;
		} else {
			R = M2;
		}
	}
	return f(x1, y1, L);
}

ld solve2(ld x1) {
	ld L = -1e4;
	ld R = 1e4;
	for (int i = 0; i < ITERATIONS; ++i) {
		ld M1 = (20 * L + 19 * R) / 39;
		ld M2 = (19 * L + 20 * R) / 39;
		ld ans1 = solve3(x1, M1);
		ld ans2 = solve3(x1, M2);
		if (ans1 > ans2) {
			L = M1;
		} else {
			R = M2;
		}
	}
	return solve3(x1, L);
}

ld solve1() {
	ld L = -1e4;
	ld R = 1e4;
	for (int i = 0; i < ITERATIONS; ++i) {
		ld M1 = (20 * L + 19 * R) / 39;
		ld M2 = (19 * L + 20 * R) / 39;
		ld ans1 = solve2(M1);
		ld ans2 = solve2(M2);
		if (ans1 > ans2) {
			L = M1;
		} else {
			R = M2;
		}
	}
	return solve2(L);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	x.assign(n, 0);
	y.assign(n, 0);
	z.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i] >> z[i];
	}
	answer = f(0, 0, 0);
	solve1();
	std::cout << std::fixed << std::setprecision(10) << x_ans << ' ' << y_ans << ' ' << z_ans << std::endl;
	return 0;
}