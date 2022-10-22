#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[400010];
const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int ID(int x, int y) {return x * m + y;}

bool Check(int id) {
	int i = id / m, j = id % m;
	if (a[ID(i, j)] == 1) return 1;
	int ok = 0;
	for (int d = 0; d < 4; d++) {
		int x = i + dir[d][0], y = j + dir[d][1];
		if (x < 0 || y < 0 || x >= n || y >= m) continue;
		if (a[ID(x, y)] < a[ID(i, j)]) {
			ok = 1;
			break;
		}
	}
	return ok;
}

bool Check() {
	for (int i = 0; i < n * m; i++) if (!Check(i)) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	; for (int i = 0; i < n * m; i++) scanf("%d", &a[i]);
	if (Check()) {
		printf("0\n");
	} else {
		static vector <int> bad; for (int i = 0; i < n * m; i++) if (!Check(i)) bad.push_back(i);
		if (bad.size() > 4) {
			printf("2\n");
			return 0;
		}
		static vector <int> all; all = bad;
		for (auto id : bad) for (int d = 0; d < 4; d++) {
			int x = id / m + dir[d][0], y = id % m + dir[d][1];
			if (x >= 0 && y >= 0 && x < n && y < m) all.push_back(ID(x, y));
		}
		sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
		static vector <int> chk; chk = all;
		for (auto id : all) for (int d = 0; d < 4; d++) {
			int x = id / m + dir[d][0], y = id % m + dir[d][1];
			if (x >= 0 && y >= 0 && x < n && y < m) chk.push_back(ID(x, y));
		}
		sort(chk.begin(), chk.end()), chk.resize(unique(chk.begin(), chk.end()) - chk.begin());
		int cnt = 0;
		auto Try = [&](int x, int y) -> int {
			swap(a[x], a[y]);
			int ok = 1;
			for (auto x : chk) {
				if (!Check(x)) {
					ok = 0;
					break;
				}
			}
			if (y % m > 0 && !Check(y - 1)) ok = 0;
			if (y % m + 1 < m && !Check(y + 1)) ok = 0;
			if (y / m > 0 && !Check(y - m)) ok = 0;
			if (y / m + 1 < n && !Check(y + m)) ok = 0;
			if (!Check(y)) ok = 0;
			swap(a[x], a[y]);
			return ok;
		};
		for (auto x : all) for (int y = 0; y < n * m; y++) {
			if (x != y) cnt += Try(x, y);
		}
		for (auto x : all) for (auto y : all) {
			if (x < y) cnt -= Try(x, y);
		}
		if (cnt) {
			printf("%d %d\n", 1, cnt);
		} else {
			printf("2\n");
		}
	}
	return 0;
}