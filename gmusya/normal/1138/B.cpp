#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <char> a1(n), a2(n);
	for (int i = 0; i < n; i++) cin >> a1[i];
	for (int i = 0; i < n; i++) cin >> a2[i];
	vector <int> t00, t01, t10, t11;
	for (int i = 0; i < n; i++) {
		if (a1[i] == '0' && a2[i] == '0') t00.push_back(i + 1);
		if (a1[i] == '0' && a2[i] == '1') t01.push_back(i + 1);
		if (a1[i] == '1' && a2[i] == '0') t10.push_back(i + 1);
		if (a1[i] == '1' && a2[i] == '1') t11.push_back(i + 1);
	}
	for (int cnt01 = 0; cnt01 <= t01.size(); cnt01++) {
		for (int cnt10 = 0; cnt10 <= t10.size(); cnt10++) {
			int val = t01.size() + t11.size() - (cnt01 + cnt10);
			if (val % 2) continue;
			int cnt11 = val / 2;
			int cnt00 = n / 2 - (cnt01 + cnt10 + cnt11);
			if (cnt00 < 0 || cnt11 < 0) continue;
			if (cnt00 > t00.size() || cnt11 > t11.size()) continue;
			for (int i = 0; i < cnt01; i++) cout << t01[i] << " ";
			for (int i = 0; i < cnt10; i++) cout << t10[i] << " ";
			for (int i = 0; i < cnt00; i++) cout << t00[i] << " ";
			for (int i = 0; i < cnt11; i++) cout << t11[i] << " ";
			return 0;
		}
	}
	cout << -1;
	return 0;
}