#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 3e3 + 5;
int n, d[N], f[N][N], res[N];

struct TNum { 
	int val, idx; 
} num[N];
inline bool operator < (TNum a, TNum b) {
	return (a.val > b.val);
}

void init_magic() {
	num[n + 1].val = 0;
	for (int i = 1; i <= n; ++i)
		d[i] = num[i].val - num[i + 1].val;
	for (int i = 1; i <= n; ++i) {
		int Max = 0;
		for (int j = i; j <= n; ++j) {
			if (d[j] > d[Max + i]) 
				Max = j - i;
			f[i][j] = Max;
		}
	}
}

int calc_magic(int a, int b) {
	if (a > b << 1 || b > a << 1) return 0;
	int c = max(a, b) + 1 >> 1;
	int d = min(a, b) << 1;
	if (a + b + c > n) return 0;
	return f[a + b + c][min(a + b + d, n)] + c;
}

bool comp_magic(int i, int j, int k, int x, int y, int z) {
	if (!k) return false;
	j += i, k += j;
	y += x, z += y;
	if (d[i] != d[x]) return (d[i] > d[x]);
	if (d[j] != d[y]) return (d[j] > d[y]);
	return (d[k] > d[z]);
}

void solve_magic(int x, int y, int z) {
	int it = 0;
	for (int i = 1; i <= x; ++i)
		res[num[++it].idx] = 1;
	for (int i = 1; i <= y; ++i)
		res[num[++it].idx] = 2;
	for (int i = 1; i <= z; ++i)
		res[num[++it].idx] = 3;
	while (it < n)
		res[num[++it].idx] = -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num[i].val);
		num[i].idx = i;
	}
	sort(num + 1, num + n + 1);
	int x = 1, y = 1, z = 1;
	init_magic();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			int k = calc_magic(i, j);
			if (comp_magic(i, j, k, x, y, z))
				x = i, y = j, z = k;
		}
	solve_magic(x, y, z);
	for (int i = 1; i <= n; ++i)
		printf("%d ", res[i]);
}