#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define endl '\n'
#define X first
#define Y second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h;
	cin >> h;
	vector<int> a(h + 1);
	int n = 0;
	for (int i = 0; i < h + 1; ++i) {
		cin >> a[i];
		n += a[i];
	}	
	bool can = false;
	int id = -1;
	for (int i = 0; i < h; ++i) {
		if (a[i] >= 2 && a[i + 1] >= 2) {
			can = true;
			id = i + 1;
			break;
		}
	}
	if (!can) {
		cout << "perfect" << endl;
		return 0;
	}
	cout << "ambiguous" << endl;
	int curh = 0;
	int p = -1;
	int placed = 0;
	for (int i = 0; i < n; ++i) {
		if (placed < a[curh]) {
				cout << p + 1 << " ";
				++placed;
		} else {
				++curh;
				p = i - 1;
				placed = 0;
				cout << p + 1 << " ";
				++placed;
		}
	}
	cout << endl;
	bool mark = false;
	curh = 0;
	p = -1;
	placed = 0;
	for (int i = 0; i < n; ++i) {
		if (curh == id && !mark) {
			cout << p << " ";
			++placed;
			mark = true;			
			continue;
		}
		if (placed < a[curh]) {
				cout << p + 1 << " ";
				++placed;
		} else {
				++curh;
				p = i - 1;
				placed = 0;
				cout << p + 1 << " ";
				++placed;
		}
	}
	return 0;
}