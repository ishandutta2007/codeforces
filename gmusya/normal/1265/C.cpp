#include <iostream>
#include <vector>

using namespace std;

struct ans {
	int g, s, b;
	int sum;
};

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		vector < pair <int, int>> solv;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int cnt = 1;
		int val = a[0];
		for (int i = 1; i < n; i++) {
			if (val != a[i]) {
				solv.push_back({ val, cnt });
				cnt = 0;
				val = a[i];
			}
			cnt++;
		}
		solv.push_back({ val, cnt });
		if (solv.size() < 3) {
			cout << "0 0 0" << endl;
			continue;
		}
		int g = solv[0].second, s = solv[1].second, b = solv[2].second;
		int ans1_g, ans1_b, ans1_s;
		int ans2_g, ans2_b, ans2_s;
		int limit = 0;
		cnt = 0;
		for (int i = 0; i < solv.size(); i++) {
			cnt += solv[i].second;
			if (cnt > n / 2) {
				limit = cnt - solv[i].second;
				break;
			}
		}
		for (int i = 2; i < solv.size(); i++) {
			s += solv[i].second;
			if (s >= limit - g - s) {
				ans1_g = g;
				ans1_s = s;
				ans1_b = limit - s - g;
				ans2_g = g;
				ans2_s = s - solv[i].second;
				ans2_b = limit - g - ans2_s;
				if (ans1_g < ans1_b && ans1_g < ans1_s) {
					cout << ans1_g << " " << ans1_s << " " << ans1_b << endl;
					break;
				}
				else if (ans2_g < ans2_b && ans2_g < ans2_s) {
					cout << ans2_g << " " << ans2_s << " " << ans2_b << endl;
					break;
				}
				else {
					cout << "0 0 0" << endl;
					break;
				}
			}
		}
	}
	return 0;
}