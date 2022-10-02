#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int x, k;
set<int> s;
vector<int> v;
int ans, ans1;



int main() {
	cin >> x >> k;
	for (int i = 0; i < k; i++) {
		int t;
		cin >> t;
		if (t == 2) {
			int num;
			cin >> num;
			s.insert(num);
		} else {
			int num, num1;
			cin >> num >> num1;
			s.insert(num);
			s.insert(num1);
		}
	}
	for (int i = 1; i < x; i++) {
		if (s.find(i) == s.end()) {
			v.push_back(i);
		}
	}
	ans1 = v.size();
	int l = 0;
	while (l < v.size()) {
		if (l < v.size() - 1 && v[l] + 1 == v[l + 1]) {
			ans++;
			l += 2;
		} else {
			l++;
			ans++;
		}
	}
	cout << ans << ' ' << ans1 << endl;
	return 0;
}