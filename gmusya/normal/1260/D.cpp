#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct trap {
	int l, r, d;
};

struct lorrag {
	int x, type, agil;
};

	int m, n, k, t;
vector <lorrag> lr;
vector <trap> traps;
vector <pair <int, int>> l, type;
vector <int> agility, ma;

bool cmp(lorrag &a, lorrag &b) {
	return (a.x < b.x || (a.x == b.x && a.type > b.type));
}

bool check(int agil) {
	int cur_pos = 0, cur_sum = 0, ans = 0;
	for (int i = 0; i < lr.size(); i++) {
		if (lr[i].agil <= agil)
			continue;
		if (cur_sum == 0 && lr[i].type == 1) {
			ans += lr[i].x - 1 - cur_pos;
			cur_pos = lr[i].x - 1;
		}
		cur_sum += lr[i].type;
		if (cur_sum == 0) {
			ans += 3 * (lr[i].x - cur_pos);
			cur_pos = lr[i].x;
		}
	}
	ans += n + 1 - cur_pos;
	return (ans <= t);
}

int main() {
	cin >> m >> n >> k >> t;
	agility.resize(m);
	traps.resize(k);
	for (int i = 0; i < m; i++)
		cin >> agility[i];
	for (int i = 0; i < k; i++)
		cin >> traps[i].l >> traps[i].r >> traps[i].d;
	sort(agility.begin(), agility.end());
	for (int i = 0; i < k; i++) {
		lr.push_back({ traps[i].l, 1, traps[i].d });
		lr.push_back({ traps[i].r, -1, traps[i].d });
	}
	sort(lr.begin(), lr.end(), cmp);
	int l = 0;
	int r = m - 1;
	int ans = 0;
	while (l != r) {
		int med = (l + r) / 2;
		int agil = agility[med];
		if (check(agil))
			r = med;
		else
			l = med + 1;
	}
	if (l == m - 1) {
		if (check(agility[m - 1]))
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	cout << m - l;
	return 0;
}
/*5 6 2 7
1 2 3 7 5
2 2 5
1 1 1
*/