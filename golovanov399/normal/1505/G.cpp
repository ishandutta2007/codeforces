#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const vector<string> lets = {".     ", ". .   ", "..    ", ".. .  ", ".  .  ", "...   ", "....  ", ". ..  ", " ..   ", " ...  ", ".   . ", ". . . ", "..  . ", ".. .. ", ".  .. ", "... . ", "..... ", ". ... ", " .. . ", " .... ", ".   ..", ". . ..", " ... .", "..  ..", ".. ...", ".  ..."};

int main() {
	int n = nxt();
	while (n--) {
		vector<int> a(5);
		generate(all(a), nxt);
		int res = -1;
		for (int i = 0; i < 26; ++i) {
			vector<int> cur(5);
			for (int j = 0; j < 6; ++j) {
				if (lets[i][j] == '.') {
					++cur[j / 2];
					++cur[3 + j % 2];
				}
			}
			if (cur == a) {
				res = i;
				break;
			}
		}
		assert(res > -1);
		cout << (char)('a' + res);
	}
	cout << "\n";

	return 0;
}