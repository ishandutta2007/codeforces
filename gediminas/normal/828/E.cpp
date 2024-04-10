/*input
GAGTTGTTAA
6
2 3 4 TATGGTG
1 1 T
1 6 G
2 5 9 AGTAATA
1 10 G
2 2 6 TTGT
*/
#include <bits/stdc++.h>

using namespace std;

#define lsb(x) ((x)&(-(x)))
template<int N>
struct BITree {
	int tree[N + 1];
	BITree() {
		for (int i = 0; i <= N; i++)
			tree[i] = 0;
	}
	void add(int pos, const int &x) {
		while (pos <= N) {
			tree[pos] += x;
			pos += lsb(pos);
		}
	}
	int get(int pos) {
		int ret = 0;

		while (pos > 0) {
			ret += tree[pos];
			pos -= lsb(pos);
		}

		return ret;
	}
	int get(int from, int to) {
		return get(to) - get(from - 1);
	}
};
#undef lsb

BITree<100000> med[4][10][10];

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);

	map<char, int> ch;
	ch['A'] = 0;
	ch['T'] = 1;
	ch['G'] = 2;
	ch['C'] = 3;
	string s;
	cin >> s;
	s = " " + s;
	int q;
	cin >> q;

	for (int i = 1; i <= s.size(); i++) {
		for (int j = 0; j < 10; j++)
			med[ch[s[i]]][j][i % (j + 1)].add(i, 1);
	}

	while (q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int pos;
			char into;
			cin >> pos >> into;

			for (int j = 0; j < 10; j++)
				med[ch[s[pos]]][j][pos % (j + 1)].add(pos, -1);

			for (int j = 0; j < 10; j++)
				med[ch[into]][j][pos % (j + 1)].add(pos, 1);

			s[pos] = into;
		}
		else {
			int l, r;
			string a;
			cin >> l >> r >> a;
			int ats = 0;

			for (int i = 0; i < a.size(); i++)
				ats += med[ch[a[i]]][a.size() - 1][(i + l) % a.size()].get(l, r);

			cout << ats << "\n";
		}
	}


	return 0;
}