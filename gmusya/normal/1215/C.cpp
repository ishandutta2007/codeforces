#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector <char> s1, s2;
vector <int> ab, ba;

int main() {
	cin >> n;
	s1.resize(n);
	s2.resize(n);
	for (int i = 0; i < n; i++) cin >> s1[i];
	for (int i = 0; i < n; i++) cin >> s2[i];
	for (int i = 0; i < n; i++) {
		if (s1[i] == 'a' && s2[i] == 'b') ab.push_back(i);
		if (s1[i] == 'b' && s2[i] == 'a') ba.push_back(i);
	}
	if (((ab.size() + ba.size()) % 2 == 1)) cout << -1;
	else {
		cout << (ab.size() / 2 + ba.size() / 2 + ab.size() % 2 + ba.size() % 2) << endl;
		if (ab.size() > 0) for (int i = 0; i < ab.size() - 1; i++) if (i % 2 == 0) cout << ab[i] + 1 << " " << ab[i + 1] + 1 << endl;
		if (ba.size() > 0) for (int i = 0; i < ba.size() - 1; i++) if (i % 2 == 0) cout << ba[i] + 1 << " " << ba[i + 1] + 1 << endl;
		if (ab.size() % 2 == 1) {
			cout << ab[ab.size() - 1] + 1 << " " << ab[ab.size() - 1] + 1 << endl;
			cout << ab[ab.size() - 1] + 1 << " " << ba[ba.size() - 1] + 1 << endl;
		}
	}
	return 0;
}