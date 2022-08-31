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
	int t = nxt();
	while (t--) {
		string s;
		cin >> s;
		sort(all(s));
		string tt = s;
		reverse(all(tt));
		if (tt != s) {
			cout << s << "\n";
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}