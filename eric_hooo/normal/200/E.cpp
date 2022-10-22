#include <bits/stdc++.h>
using namespace std;

int n, S;
int C[3], D[3];
int f[3][200010];

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return g;
}

int Floor(int, int);
int Ceil(int, int);

int Ceil(int x, int y) {
	if (y < 0) return Ceil(-x, -y);
	if (x < 0) return -Floor(-x, y);
	return (x + y - 1) / y;
}

int Floor(int x, int y) {
	if (y < 0) return Floor(-x, -y);
	if (x < 0) return -Ceil(-x, y);
	return x / y;
}

int main() {
	scanf("%d%d", &n, &S);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		C[x - 3]++;
	}
	int ans = 0x3f3f3f3f, I, J, K;
	for (int j = 0; j * C[1] <= S; j++) {
		int T = S - j * C[1];
		// i * C[0] + k * C[2] = T
		int i, k, g = exgcd(C[0], C[2], i, k);
		if (T % g != 0) continue;
		i *= T / g, k *= T / g;
		int di = C[2] / g, dk = C[0] / g;
		// 0 <= i + x * di <= j
		// j <= k - x * dk
		int L = -0x3f3f3f3f, R = 0x3f3f3f3f;
		L = max(L, Ceil(-i, di)), R = min(R, Floor(j - i, di));
		R = min(R, Floor(k - j, dk));
		if (L > R) continue;
		auto Check = [&](int x) -> void {
			if (x < L || x > R) return ;
			int ii = i + x * di, kk = k - x * dk;
			int val = abs(ii * C[0] - j * C[1]) + abs(j * C[1] - kk * C[2]);
			if (ans > val) ans = val, I = ii, J = j, K = kk;
		};
		Check(L), Check(R);
		Check(Floor(C[1] * j - C[0] * i, di * C[0])), Check(Ceil(C[1] * j - C[0] * i, di * C[0]));
		Check(Floor(C[1] * j - C[2] * k, dk * C[2])), Check(Ceil(C[1] * j - C[2] * k, dk * C[2]));
	}
	if (ans == 0x3f3f3f3f) printf("-1\n");
	else printf("%d %d %d\n", I, J, K);
	return 0;
}