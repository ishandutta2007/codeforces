#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>


using namespace std;
#define int long long
int mod = 1e9 + 7;
int big_mod = 1e18 + 7;
const int MAXN = 2000000 + 228;
vector <string> s;


struct node {
	int s_num, s_pos;
	bool check;
};


node tree[MAXN * 4];
string ans = "";
int right1 = -mod;


void push(int v) {
	if (!tree[v].check) {
		return;
	}

	tree[v * 2 + 1].s_num = tree[v].s_num;
	tree[v * 2 + 2].s_num = tree[v].s_num;
	tree[v * 2 + 1].s_pos = tree[v * 2 + 2].s_pos = tree[v].s_pos;
	tree[v * 2 + 1].check = tree[v * 2 + 2].check = true;
}


void build(int v, int tl, int tr) {
	tree[v].s_num = -1;
	tree[v].s_pos = -1;
	tree[v].check = false;

	if (tl == tr) {
		return;
	}

	int m = (tl + tr) / 2;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m + 1, tr);
}


void upd(int v, int tl, int tr, int l, int r, int num, int pos) {
	if (tl > r || l > tr) {
		return;
	}

	if (tl >= l && tr <= r) {
		tree[v].check = true;
		tree[v].s_num = num;
		tree[v].s_pos = pos;
		return;
	}

	int m = (tl + tr) / 2;
	upd(v * 2 + 1, tl, m, l, r, num, pos);
	upd(v * 2 + 2, m + 1, tr, l, r, num, pos);
}


void print(int v, int tl, int tr) {
	if (tl == tr) {
		if (tl > right1) {
			return;
		}

		if (!tree[v].check) {
			ans += 'a';
		}
		else {
			ans += s[tree[v].s_num][tl - tree[v].s_pos];
		}

		return;
	}

	int m = (tl + tr) / 2;
	push(v);
	print(v * 2 + 1, tl, m);
	print(v * 2 + 2, m + 1, tr);
}


signed main() {
	cout.precision(20);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	s.resize(n);
	build(0, 0, MAXN - 1);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int k;
		cin >> k;
		int p;
		for (int j = 0; j < k; ++j) {
			cin >> p;
			right1 = max(right1, p - 1 + s[i].size() - 1);
			upd(0, 0, MAXN - 1, p - 1, p - 1 + s[i].size() - 1, i, p - 1);
		}
	}

	print(0, 0, MAXN - 1);
	cout << ans;
	return 0;
}