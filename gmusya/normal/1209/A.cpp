#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector <int> a;

int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 0;
	bool tf = false;
	while (a.size() > 0 && !tf) {
		int x = a[0];
		a.erase(a.begin());
		for (int i = 0; i < a.size(); i++)  if (a[i] % x == 0) a[i] = 1;
		tf = true;
		for (int i = 0; i < a.size(); i++) if (a[i] != 1) tf = false;
		if (a.size() < 1) {
			cnt++;
			break;
		}
		while (a[0] == 1 && a.size() > 1) a.erase(a.begin());
		cnt++;
	}
	cout << cnt;
	return 0;
}