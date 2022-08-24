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

string f(string s) {
	string res = "";
	int num_k = 0;
	for (char c : s) {
		if (c == 'h') {
			res += c;
			num_k = 0;
		} else {
			if (c == 'u') {
				res += string(num_k, 'k');
				num_k = 0;
				res += "oo";
			} else if (c == 'k') {
				num_k += 1;
			} else {
				res += string(num_k, 'k');
				num_k = 0;
				res += c;
			}
		}
	}
	if (num_k) {
		res += string(num_k, 'k');
	}
	return res;
}

int main() {
	int n = nxt();
	set<string> S;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		S.insert(f(s));
	}

	cout << S.size() << "\n";

	return 0;
}