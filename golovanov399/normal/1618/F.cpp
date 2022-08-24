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

string b() {
	long long x;
	cin >> x;
	string s;
	while (x) {
		s += (char)('0' + x % 2);
		x /= 2;
	}
	return s;
}

set<string> S;

void rec(string s, const string& t) {
	if (s == t) {
		cout << "YES\n";
		exit(0);
	}
	if (s.length() > t.length() && s[0] == '1') {
		return;
	}
	if (S.count(s)) {
		return;
	}
	S.insert(s);
	reverse(all(s));
	rec(s + '1', t);
	while (s.back() == '0') {
		s.pop_back();
	}
	rec(s, t);
}

int main() {
	auto s = b();
	auto t = b();
	rec(s, t);
	cout << "NO\n";

	return 0;
}