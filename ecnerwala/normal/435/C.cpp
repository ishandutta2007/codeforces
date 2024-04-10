#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int X = 0;
	map<int, unordered_map<int, char>> mp;
	int Y = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (i & 1) {
			while (a--) {
				mp[Y++][X++] = '\\';
			}
		} else {
			while (a--) {
				mp[--Y][X++] = '/';
			}
		}
	}
	for (const auto& it : mp) {
		for (int v = 0; v < X; v++) {
			auto jt = it.second.find(v);
			if (jt == it.second.end()) {
				cout << ' ';
			} else {
				cout << jt->second;
			}
		}
		cout << '\n';
	}

	return 0;
}