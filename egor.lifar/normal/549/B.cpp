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
int a[200000];
vector<int> v[101];
bool flag[200000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			int t;
			t = s[j] - '0';
			if (t == 1) {
				v[i].push_back(j);
			}
		}
	}
	int g = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		g += (a[i] == 0);
	}
	if (g == 0) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[j] && a[j] == 0) {
				ans.push_back(j + 1);
				flag[j] = true;
				for (int g = 0; g < (int)v[j].size(); g++) {
					int h = v[j][g];
					a[h]--;
				}
				break;
			}
		}
	}	
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i] << endl;
	}
 	return 0;
}