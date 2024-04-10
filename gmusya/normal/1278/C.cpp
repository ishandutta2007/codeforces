#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int red = 0, blue = 0;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 1)
				red++;
			else
				blue++;
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			if (b[i] == 1)
				red++;
			else
				blue++;
		}
		int k = abs(red - blue);
		reverse(a.begin(), a.end());
		if (red < blue) {
			for (int i = 0; i < n; i++)
				a[i] = 3 - a[i];
			for (int i = 0; i < n; i++)
				b[i] = 3 - b[i];
		}
		int cnt1 = 0, cnt2 = 0;
		vector <int> suma;
		vector <int> sumb;
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
				cnt1++;
			if (a[i] == 2)
				cnt1--;
			if (cnt1 > 0 && cnt1 > suma.size())
				suma.push_back(i + 1);
		}
		for (int i = 0; i < n; i++) {
			if (b[i] == 1)
				cnt2++;
			if (b[i] == 2)
				cnt2--;
			if (cnt2 > 0 && cnt2 > sumb.size())
				sumb.push_back(i + 1);
		}
		int cnt = 10000000;
		if (suma.size() >= k && k > 0)
			cnt = min(suma[k - 1], cnt);
		if (sumb.size() >= k && k > 0)
			cnt = min(sumb[k - 1], cnt);
		for (int i = 0; i < suma.size(); i++) {
			if (i + 1 + sumb.size() < k || k - i - 2 < 0)
				continue;
			cnt = min(cnt, suma[i] + sumb[k - i - 2]);
		}
		for (int i = 0; i < sumb.size(); i++) {
			if (i + 1 + suma.size() < k || k - i - 2 < 0)
				continue;
			cnt = min(cnt, sumb[i] + suma[k - i - 2]);
		}
		if (k == 0)
			cout << 0 << endl;
		else {
			cout << cnt << endl;
		}
	}
	return 0;
}