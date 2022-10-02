#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
int a[5000], b[5000];
pair<int, int> p[5000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		p[i] = make_pair(a[i], b[i]);
	}
	sort(p, p + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans <= p[i].second) {
			ans = p[i].second;
		} else {
			ans = p[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}