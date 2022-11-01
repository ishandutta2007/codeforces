#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector <bool> answer(t);
	for (int z = 0; z < t; z++) {
		int n, r, p, s;
		cin >> n >> r >> p >> s;
		vector <char> arr(n);
		for (int i = 0; i < n; i++) cin >> arr[i];
		vector <char> kek(n);
		for (int i = 0; i < n; i++) kek[i] = 'a';
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] == 'R' && p > 0) {
				cnt++;
				kek[i] = 'P';
				p--;
			}
			if (arr[i] == 'P' && s > 0) {
				cnt++;
				kek[i] = 'S';
				s--;
			}
			if (arr[i] == 'S' && r > 0) {
				cnt++;
				kek[i] = 'R';
				r--;
			}
		}
		for (int i = 0; i < n; i++) {
			if (kek[i] == 'a') {
				if (p > 0) {
					kek[i] = 'P';
					p--;
				}
				else {
					if (s > 0) {
						kek[i] = 'S';
						s--;
					}
					else
						kek[i] = 'R';
				}
			}
		}
		if (cnt >= (n + 1) / 2) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) cout << kek[i];
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}