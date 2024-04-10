#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct triplet {
	int left_val, right_val, num;
};

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	vector <triplet> hm;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int cur_left = 0;
	for (int i = 0; i < n - 1; i++)
		if (a[i] >= a[i + 1]) {
			hm.push_back({ cur_left, i, i - cur_left + 1 });
			cur_left = i + 1;
		}
	hm.push_back({ cur_left, n - 1, n - cur_left});
	int ans = 0;
	for (int i = 0; i < hm.size(); i++)
		ans = max(ans, hm[i].num);
	for (int i = 0; i < hm.size() - 1; i++) {
		if (hm[i].num == 1 || hm[i + 1].num == 1)
			continue;
		if (hm[i].num != 1 && a[hm[i].right_val] < a[hm[i + 1].left_val + 1] || a[hm[i].right_val - 1] < a[hm[i + 1].left_val])
			ans = max(ans, hm[i].num + hm[i + 1].num - 1);
	}
	cout << ans;
	return 0;
}