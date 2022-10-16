#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) x.size()

void no() {
	cout << "NO";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	vector<string> friends = {"Danil", "Olya", "Slava", "Ann", "Nikita"};
	bool found = false;
	for (auto &fr: friends) {
		auto l = s.find(fr);
		auto r = s.rfind(fr);
		if (l != r) no();
		if (l != s.npos && !found) found = true;
		else if (l != s.npos && found) no();
	}	
	if (found) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	return 0;
}