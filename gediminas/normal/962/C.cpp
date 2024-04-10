/*input
333

*/
#include <bits/stdc++.h>

using namespace std;

bool arKvad(const string &a) {
	long long s = stoll(a);
	long long b = sqrtl(s);
	return b * b == s or (b + 1) * (b + 1) == s or (b - 1) * (b - 1) == s;
}

int rek(const string &sk) {
	//cout << sk << " " << arKvad(sk) << endl;
	if (arKvad(sk)) {
		return 0;
	}

	if (sk.size() == 1) {
		return 15;
	}

	int mi = 15;

	if (sk[1] != '0') {
		string t = sk;
		t.erase(t.begin());
		mi = min(mi, 1 + rek(t));
	}

	for (int i = 1; i < sk.size(); i++) {
		string t = sk;
		t.erase(t.begin() + i);
		mi = min(mi, 1 + rek(t));
	}

	return mi;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string x;
	cin >> x;
	int ats = rek(x);
	cout << (ats < 15 ? ats : -1);

	return 0;
}