#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int N = 200010, M = 65, P = 15, REP = 50;

int n, m, p, ans;
bool s[N][M];
char str[M];
int id[M];
int tot[1 << P];

int popcnt(int s) { return __builtin_popcount(s); }

void test(int k) {
	int c = 0;
	for (int i = 0; i != m; ++i) if (s[k][i])
		id[c++] = i;
	memset(tot, 0, sizeof(tot));
	for (int i = 0; i != n; ++i) {
		int mask = 0;
		for (int j = 0; j != c; ++j) if (s[i][id[j]])
			mask |= 1 << j;
		++tot[mask];
	}
	for (int i = 0; i != c; ++i)
		for (int j = 0; j != 1 << c; ++j)
			if (!((j >> i) & 1)) tot[j] += tot[j ^ (1 << i)];
	for (int i = 0; i != 1 << c; ++i) if (tot[i] * 2 >= n && popcnt(i) > ans) {
		ans = popcnt(i);
		fill(str, str + m, '0');
		for (int j = 0; j != c; ++j) if ((i >> j) & 1)
			++str[id[j]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> p;
	for (int i = 0; i != n; ++i) {
		cin >> str;
		for (int j = 0; j != m; ++j) 
			s[i][j] = str[j] == '1';
	}
	
	uniform_int_distribution<int> uid(0, n - 1);
	fill(str, str + m, '0');
	for (int rep = 0; rep != 50; ++rep) test(uid(rng));
	cout << str;
	
	return 0;
}