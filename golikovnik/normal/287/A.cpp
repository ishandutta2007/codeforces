#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define fi first
#define se second

char a[4][4];

bool check() {
	for (int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if (a[i][j] == a[i+1][j] && a[i+1][j] == a[i][j+1] && a[i][j+1] == a[i+1][j+1]) return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	for(int i = 0; i < 4; ++i) {
		string row;
		cin >> row;
		for (int j = 0; j < 4; ++j) {
			if (row[j] == '#') a[i][j] = true;
			else a[i][j] = false;
		}
	}
	if (check()) {
		cout << "YES";
		return 0;
	}
	for(int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = !a[i][j];
			if (check()) {
				cout << "YES";
				return 0;
			}
			a[i][j] = !a[i][j];
		}
	}
	cout << "NO";
	return 0;
}