#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 7;
int a[100], v[100];

struct matrix {
	int m[100][100];
	inline int* operator [] (int x) const { return (int*) m[x]; }
	matrix() {
		for (int i = 0; i < 100; ++i)
			for (int j = 0; j < 100; ++j)
				m[i][j] = -INF;
	}
};

matrix operator * (matrix a, matrix b) {
	matrix c;
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			for (int k = 0; k < 100; ++k)
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
	return c;
}

matrix operator ^ (matrix base, int p) {
	matrix res;
	for (int i = 0; i < 100; ++i)
		res[i][i] = 0;
	while (p > 0) {
		if (p & 1) res = res * base;
		base = base * base;
		p >>= 1;
	}
	return res;
}

int main() {
	int n, t, ans = 0; scanf("%d%d", &n, &t);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			v[i] += a[j] < a[i];
	matrix res;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (v[j] >= i) {
				if (res[i][v[j]] == -INF)
					res[i][v[j]] = 0;
				for (int k = 0; k < j; ++k)
					if (v[k] <= v[j])
						res[i][v[j]] = max(res[i][v[j]], res[i][v[k]]);
				++res[i][v[j]];
			}
	res = res ^ t;
	for (int i = 0; i < n; ++i)
		ans = max(ans, res[0][i]);
	printf("%d", ans);
}