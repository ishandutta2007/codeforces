#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair <int, int> a, pair <int, int> b) {
	return (a.first < b.first || (a.first == b.first && a.second <= b.second));
}

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), cmp);
	int cur = a[0].second;
	for (int i = 1; i < n; i++) {
		if (cur <= a[i].second) {
			cur = a[i].second;
			continue;
		}
		cur = a[i].first;
	}
	cout << cur;
	return 0;
}