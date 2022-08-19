#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	string T; cin >> T;
	vector<int> fail;
	fail.push_back(-1);
	for (int i = 0; i < int(T.size()); i++) {
		int cur = fail.back();
		while (cur != -1 && T[cur] != T[i]) {
			cur = fail[cur];
		}
		fail.push_back(cur + 1);
	}
	string Tsuff = T.substr(fail.back());
	int cnt[2] = {0, 0};
	for (char c : S) {
		assert(c == '0' || c == '1');
		cnt[c - '0'] ++;
	}
	string R;
	for (char c : T) {
		if (cnt[c - '0']) {
			R += c;
			cnt[c - '0'] --;
		} else {
			goto failed;
		}
	}
	while (true) {
		for (char c : Tsuff) {
			if (cnt[c - '0']) {
				R += c;
				cnt[c - '0'] --;
			} else {
				goto failed;
			}
		}
	}
failed:
	for (int z = 0; z < 2; z++) {
		while (cnt[z]--) R += char('0' + z);
	}
	cout << R << '\n';

	return 0;
}