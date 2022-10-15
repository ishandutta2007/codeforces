#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	vector<int> usb, ps;
	for (int i = 0; i < n; i++) {
		int n; string s;
		cin >> n >> s;
		if (s == "USB") {
			usb.push_back(n);
		} else {
			ps.push_back(n);
		}
	}
	sort(usb.begin(), usb.end(), greater<int>());
	sort(ps.begin(), ps.end(), greater<int>());
	int cnt = 0;
	int64_t cost = 0;
	for (int i = 0; i < a; i++) {
		if (!usb.empty()) {
			cnt++;
			cost += usb.back();
			usb.pop_back();
		}
	}
	for (int i = 0; i < b; i++) {
		if (!ps.empty()) {
			cnt++;
			cost += ps.back();
			ps.pop_back();
		}
	}
	for (int i = 0; i < c; i++) {
		int usbVal = usb.empty() ? INT_MAX : usb.back();
		int psVal = ps.empty() ? INT_MAX : ps.back();
		if (usbVal < psVal) {
			cnt++;
			cost += usb.back();
			usb.pop_back();
		} else if (psVal != INT_MAX) {
			cnt++;
			cost += ps.back();
			ps.pop_back();
		}
	}
	cout << cnt << " " << cost << endl;
	return 0;
}