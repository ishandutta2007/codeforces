#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
 

using namespace std;


int n;
int s[100];
vector<int> v[100];
int ans = 0;
int ans1 = 0;
vector<int> t;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < s[i]; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
			if (j < s[i] / 2) {
				ans += v[i][j];
			} else {
				if (j >= (s[i] + 1) / 2) {
					ans1 += v[i][j];
				} else {
					t.push_back(v[i][j]);
				}
			}
		}
	}
	sort(t.begin(), t.end());
	reverse(t.begin(), t.end());
	for (int i = 0; i < (int)t.size(); i++) {
		if (i % 2 == 0) {
			ans += t[i];
		} else {
			ans1 += t[i];
		}
	}
	cout << ans << ' ' << ans1 << endl;
	return 0;
}