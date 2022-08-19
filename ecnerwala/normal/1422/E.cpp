#include<bits/stdc++.h>

// string ends with -infty
struct compressed_string {
	int len = 0;
	std::array<char, 10> pref = {'\0',};
	bool incr = false;

	auto prepend(char c) {
		if (c != pref[0]) {
			incr = (c < pref[0]);
		} else {
			// no change
		}

		if (len < 10) {
			for (int i = len; i > 0; i--) pref[i] = pref[i-1];
		} else {
			if (len == 10) {
				pref[5] = pref[6] = pref[7] = '.';
			}
			for (int i = 4; i > 0; i--) pref[i] = pref[i-1];
		}
		len++;
		pref[0] = c;
	}
};

// xx xx zz xx x (aa) zz z ...

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string S; cin >> S;
	int N = int(S.size());
	vector<compressed_string> res(N+1);
	res[N] = compressed_string();
	for (int i = N-1; i >= 0; i--) {
		char c = S[i];
		if (i + 1 < N && S[i+1] == c) {
			// we need to decide whether to keep or delete i,i+1
			compressed_string a = res[i+2];
			if (c < a.pref[0] || (c == a.pref[0] && a.incr)) {
				a.prepend(c);
				a.prepend(c);
			}
			res[i] = std::move(a);
		} else {
			// no choice but to keep i
			compressed_string a = res[i+1];
			a.prepend(c);
			res[i] = std::move(a);
		}
	}

	for (int i = 0; i < N; i++) {
		cout << res[i].len << ' ';
		for (int z = 0; z < min(10, res[i].len); z++) cout << res[i].pref[z];
		cout << '\n';
	}

	return 0;
}