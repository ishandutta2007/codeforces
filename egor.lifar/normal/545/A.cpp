#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n;
bool good[100];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			if (a == 1 || a == 3) {
				good[i] = true;
			}
			if (a == 2 || a == 3) {
				good[j] = true;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (!good[i]) {
			ans.push_back(i + 1);
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}