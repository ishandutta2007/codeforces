#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int kolvobukv[200001][26];
string s;

bool tf(vector <int> &a, int length) {
	bool tf1 = true;
	for (int i = 0; i < 26; i++) {
		if (a[i] > kolvobukv[length][i]) tf1 = false;
	}
	return tf1;
}

int solving(string sss) {
	vector <int> a(26);
	for (int i = 0; i < 26; i++) a[i] = count(sss.begin(), sss.end(), 'a' + i);
	int l = 0;
	int r = n;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (tf(a, m)) r = m; else l = m;
	}
	return r;
}

int main() {
	cin >> n;
	cin >> s;
	int m;
	cin >> m;
	vector <string> kek(m);
	for (int i = 0; i < m; i++) cin >> kek[i];
	for (int j = 0; j < 26; j++) kolvobukv[0][j] = 0;
	for (int i = 1; i <= n; i++) for (int j = 0; j < 26; j++) {
		kolvobukv[i][j] = kolvobukv[i - 1][j] + (j + 'a' == s[i - 1]);
	}
	for (int i = 0; i < m; i++) cout << solving(kek[i]) << endl;
	return 0;
}