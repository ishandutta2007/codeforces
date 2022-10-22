#include <bits/stdc++.h>
using namespace std;

vector <int> a;
vector <int> op;
int n;

bool check() {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == n) return 1;
	}
	return 0;
}

bool dfs(int dep) {
	if (dep == 0) {
		if (check()) return 1;
		return 0;
	}
	a.push_back(0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			for (int k = 1; k <= 8; k <<= 1) {
				op.push_back(i * 10000 + j * 100 + k);
				a.back() = a[i] + a[j] * k;
				if (dfs(dep - 1)) return 1;
				a.back() = 0;
				op.pop_back();
			}
		}
	}
	a.pop_back();
	return 0;
}

int main () {
	cin >> n;
	int lim = 0;
	a.push_back(1);
	while (!dfs(lim)) lim++;
	cout << lim << endl;
	for (int i = 0; i < op.size(); i++) {
		int x = op[i] / 10000, y = op[i] / 100 % 100, k = op[i] % 100;
		string X = "e"; X.push_back(char('a' + x)); X.push_back('x');
		string Y = "e"; Y.push_back(char('a' + y)); Y.push_back('x');
		if (k != 1) Y.insert(Y.begin(), '*'), Y.insert(Y.begin(), char('0' + k));
		string app = "e"; app.push_back(char('a' + i + 1)); app += "x";
		cout << "lea " << app << ", [" << X << " + " << Y << "]" << endl;
	}
	return 0;
}