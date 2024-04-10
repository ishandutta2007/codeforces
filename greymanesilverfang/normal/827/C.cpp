#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N = 1e5 + 1, p[2] = {70, 72};
const char nu[4] = {'A', 'T', 'G', 'C'};

int Fenwick[2][4][MAX_N];

int val(char c) { for (int i = 0; i < 4; ++i) if (c == nu[i]) return i; }

void build_tree(const string &S) {
	for (int t = 0; t < 2; ++t)
		for (int n = 0; n < 4; ++n)
			for (int i = 1; i < S.length(); ++i) {
				Fenwick[t][n][i] += S[i] == nu[n];
				int quo = (i - 1) / p[t] + 1, rem = (i - 1) % p[t] + 1, tmp;
				quo += quo & -quo;
				if ((tmp = p[t] * (quo - 1) + rem) < MAX_N)
					Fenwick[t][n][tmp] += Fenwick[t][n][i];
			}
}

void setval(int i, char s, char c) {
	int S = val(s), C = val(c);
	for (int t = 0; t < 2; ++t) {
		int quo = (i - 1) / p[t] + 1, rem = (i - 1) % p[t] + 1, tmp;
		while ((tmp = p[t] * (quo - 1) + rem) < MAX_N) {
			--Fenwick[t][S][tmp];
			++Fenwick[t][C][tmp];
			quo += quo & -quo;
		}
	}
}

int getval(int i, int t, char c) {
	int C = val(c), ans = 0;
	int quo = (i - 1) / p[t] + 1, rem = (i - 1) % p[t] + 1, tmp;
	while ((tmp = p[t] * (quo - 1) + rem) > 0) {
		ans += Fenwick[t][C][tmp];
		quo -= quo & -quo;
	}
	return ans;
}

int solve(int L, int R, const string &s) {
	int t = bool(p[0] % s.length()), ans = 0;
	for (int i = 0; i < p[t] && L <= R; ++i, ++L)
		ans += getval(L + (R - L) / p[t] * p[t], t, s[i % s.length()]) - (L > p[t] ? getval(L - p[t], t, s[i % s.length()]) : 0);
	return ans;
}

int main() {
	string S; cin >> S; S.insert(S.begin(), ' ');
	build_tree(S);
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int i; cin >> i;
			char c; cin >> c;
			setval(i, S[i], c);
			S[i] = c;
		} else {
			int i, j; cin >> i >> j;
			string s; cin >> s;
			cout << solve(i, j, s) << endl;
		}
	}
	return 0;
}