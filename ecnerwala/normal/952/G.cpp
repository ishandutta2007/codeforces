#include<bits/stdc++.h>
using namespace std;

const int W = 16;
static_assert(W % 2 == 0);

int main() {
	string s;
	cin >> s;
	string empty(W, '.');
	string full(W, 'X');
	int v = 0;
	for (char c : s) {
		cout << empty << '\n';
		cout << full << '\n';
		assert(c > 32);
		while (!(c+1 <= v && v <= c+W)) {
			cout << full << '\n';
			v += W;
			v %= 256;
		}

		cout << empty << '\n';

		while (v - c > 1) {
			string tmp = empty;
			for (int j = 0; j < W / 2 && v-c > 1; j++) {
				tmp[2*j] = 'X';
				v--;
			}
			cout << tmp << '\n';
			cout << empty << '\n';
		}
		assert(v == c+1);
		string out = empty;
		out[0] = 'X';
		cout << out << '\n';
		v--;
		cout << out << '\n';
		cout << empty << '\n';
	}

	return 0;
}