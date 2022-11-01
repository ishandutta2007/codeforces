#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct triplet {
	int l, r, w;
};
int main() {
	int n;
	cin >> n;
	vector <triplet> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].l >> a[i].r >> a[i].w;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i].w;
	int f = a[0].l;
	int cur_pos = 0;
	int cur_roads = 1;
	int cur_sum = 0;
	while (cur_roads < n) {
		bool tf = false;
		for (int i = 0; i < n; i++)
			if (a[i].l == a[cur_pos].r) {
				tf = true;
				cur_pos = i;
				cur_roads++;
				break;
			}
		if (tf)
			continue;
		for (int i = 0; i < n; i++)
			if (a[i].r == a[cur_pos].r && i != cur_pos) {
				swap(a[i].r, a[i].l);
				cur_pos = i;
				cur_roads++;
				cur_sum += a[i].w;
			}
	}
	cout << min(cur_sum, sum - cur_sum);
	return 0;
}