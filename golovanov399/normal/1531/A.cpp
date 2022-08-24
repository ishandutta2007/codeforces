#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	string cur = "blue";
	bool locked = false;
	while (n--) {
		string s;
		cin >> s;
		if (s == "lock") {
			locked = true;
		} else if (s == "unlock") {
			locked = false;
		} else if (!locked) {
			cur = s;
		}
	}
	cout << cur << "\n";

	return 0;
}