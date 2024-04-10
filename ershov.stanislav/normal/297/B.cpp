#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define mod 1000000007

int n, m, k;
vector<pair<int, int> > all;

int main() {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		int a;
		cin >> a;
		all.push_back(make_pair(a, 1));
	}
	for (int i=0; i<m; i++) {
		int a;
		cin >> a;
		all.push_back(make_pair(a, -1));
	}
	sort(all.begin(), all.end());
	for (int i=all.size()-1, s=0; i>=0; ) {
		int c=all[i].first;
		while (i>=0&&all[i].first==c) s+=all[i].second, i--;
		if (s>0) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}