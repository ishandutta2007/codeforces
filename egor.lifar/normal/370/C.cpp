#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, m;
int a[100000];
int b[100000];
vector<pair<int, int> > v;
vector<pair<int, int> > ans;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(make_pair(b[a[i]], a[i]));
	}
	sort(v.rbegin(), v.rend());
	int s = v[0].first;
	for (int i = 0; i < n; i++) {
		ans.push_back(make_pair(v[i].second, v[(i + s) % n].second));
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i].first != ans[i].second) {
			k++;
		}
	}
	cout << k << endl;
	for (int i = 0; i < n; i++) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
	return 0;
}