#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long int 
using namespace std;

struct hero {
	int power;
	int stamina;
};

int n, m, cnt = 0;
vector <int> monsters;
vector <hero> heroes;
vector <int> t;
vector <int> answer;

bool cmp(hero &a, hero &b) {
	return (a.power > b.power || (a.power == b.power && a.stamina > b.stamina));
}

int bin_search(int x) {
	int l = 0;
	int r = m - 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (heroes[m].power < x)
			r = m;
		else
			l = m + 1;
	}
	if (heroes[l].power >= x)
		return l;
	return l-1;
}

void build(vector <hero> &a, int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl].stamina;
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}
}

int max_in_tree(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && r == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	return max(max_in_tree(v * 2, tl, tm, l, min(r, tm)), max_in_tree(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}


int main() {
	int z;
	cin >> z;
	answer.resize(z);
	for (int x = 0; x < z; x++) {
		cnt = 0;
		cin >> n;
		monsters.resize(n);
		for (int i = 0; i < n; i++)
			cin >> monsters[i];
		cin >> m;
		heroes.resize(m);
		for (int i = 0; i < m; i++)
			cin >> heroes[i].power >> heroes[i].stamina;
		sort(heroes.begin(), heroes.end(), cmp);
		t.resize(4 * m);
		build(heroes, 1, 0, m - 1);
		int defeated = 0, probably = 0;
		while (defeated < n) {
			bool tf = true;
			int ans = 0;
			int znach = monsters[probably];
			while (probably < monsters.size()) {
				znach = max(znach, monsters[probably]);
				int l = bin_search(znach);
				if (l == -1 || max_in_tree(1, 0, m - 1, 0, l) + defeated <= probably) break;
				ans = max(ans, min(max_in_tree(1, 0, m - 1, 0, l), probably - defeated + 1));
				probably++;
			}
			if (ans == 0) {
				answer[x] = -1;
				break;
			}
			cnt++;
			defeated += ans;
			probably = defeated;
		}
		if (answer[x] != -1)
			answer[x] = cnt;
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	return 0;
}

/*
6
2 3 11 14 1 2
2
3 2
100 1
*/