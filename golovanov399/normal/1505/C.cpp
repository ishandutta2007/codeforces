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

int main() {
	string s;
	cin >> s;
	if (s.length() <= 1) {
		cout << "YES\n";
		return 0;
	}
	int x = s[0] - 'A';
	int y = s[1] - 'A';
	for (int i = 2; i < (int)s.length(); ++i) {
		x = (x + y) % 26;
		swap(x, y);
		if (s[i] - 'A' != y) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}