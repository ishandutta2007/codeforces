#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	auto cut = [&](string cur, string was) -> string {
		if (cur <= was) {
			return cur;
		}
		was += '!';
		for (int i = 0; i < (int)cur.size(); i++) {
			if (cur[i] > was[i]) {
				return cur.substr(0, i);
			}
		}
		return "#";
	};
	for (int i = n-1; i > 0; i--) {
		v[i-1] = cut(v[i-1], v[i]);
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << "\n";
	}
	return 0;
}