#include <bits/stdc++.h>
using namespace std;

const int maxN = 200000 + 233;
const int maxM = 20 + 1;
int n, m;
int s[maxN]; // only my bitwise-operations
int a[maxN], f[maxN];

int high(int x, int b) {
	return (x >> (m - b)) & ((1 << b) - 1);
}
int low(int x, int b) {
	return x & ((1 << b) - 1);
}
int w(int x, int y) {
	for(int j = m; j >= 0; --j) if(low(x, j) == high(y, j)) return j;
	return -1;
}
vector<int> g[maxM];
int WASTE;
#define displaya(a, st, n)\
	{cerr << #a << " = {";\
	for(int qwq = (st); qwq <= (n); ++qwq) {\
		if(qwq == st) cerr << a[qwq];\
		else cerr << ", " << a[qwq];\
	} cerr << "}" << endl;}

bool chmin(int &x, int y) { return x > y ? x = y, true : false; }
bool chmax(int &x, int y) { return x < y ? x = y, true : false; }

int main() {
	WASTE = scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		static char t[maxM]; WASTE = scanf("%s", t);
		m = strlen(t);
		s[i] = 0;
		for(int j = 0; j < m; ++j) s[i] = s[i] * 2 + (t[j] - '0');
	}
	for(int i = 2; i <= n; ++i) {
		a[i] = w(s[i - 1], s[i]);
	}
	for(int j = 0; j <= m; ++j) g[j].assign(1 << j, 0x80808080);
	int ans = 0;
	for(int i = n; i > 1; --i) {
		f[i] = 0;
//		for(int j = i + 1; j <= n; ++j) f[i] = max(f[i], f[j] + w(s[i - 1], s[j]));
		for(int j = 0; j <= m; ++j) chmax(f[i], g[j][low(s[i - 1], j)] + j);
		f[i] -= a[i];
		for(int j = 0; j <= m; ++j) chmax(g[j][high(s[i], j)], f[i]);
		chmax(ans, f[i]);
	}
//	displaya(a, 2, n);
//	displaya(f, 2, n);
	cout << n * m - ans - accumulate(a + 2, a + n + 1, 0) << endl;
	return 0;
}