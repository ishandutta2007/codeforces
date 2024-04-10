#include <bits/stdc++.h>
using namespace std;

int can[10000];

int main () {
	int n, k; cin >> n >> k;
	cout << "?";
	for (int i = 1; i <= k; i++) {
		cout << " " << i;
	}
	cout << endl;
	int pos, val; cin >> pos >> val;
	int v;
	for (int i = 1; i <= k; i++) {
		if (i == pos) continue;
		cout << "?";
		for (int j = 1; j <= k; j++) {
			cout << " " << (i == j ? k + 1 : j);
		}
		cout << endl;
		int p, tmp; cin >> p >> tmp;
		if (p == pos) can[i] = 1;
		else can[i] = 0, v = tmp;
	}
	int cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (can[i] == 1) cnt++;
	}
	if (cnt != k - 1 && cnt != 0) {
		if (v < val) {
			cout << "! " << cnt + 1 << endl;
			return 0;
		}
		cnt = k - 1 - cnt;
		cout << "! " << cnt + 1 << endl;
		return 0;
	}
	cout << "?";
	for (int i = 1; i <= k + 1; i++) {
		if (i != pos) cout << " " << i;
	}
	cout << endl;
	int x, y; cin >> x >> y;
	if (cnt == 0) {
		if (x == k + 1 && y > val) cout << "! " << k << endl;
		else if (x == k + 1) cout << "! " << 1 << endl;
		else if (y > val) cout << "! " << 1 << endl;
		else cout << "! " << k << endl;
	} else {
		if (x == k + 1 && y > val) cout << "! " << 1 << endl;
		else if (x == k + 1) cout << "! " << k << endl;
		else if (y > val) cout << "! " << 1 << endl;
		else cout << "! " << k << endl;
	}
	return 0;
}