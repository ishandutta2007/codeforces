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



int n, m, k;
bool b[1000], b1[1000];
int ans[1000];
int a[1000][1000];



int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < max(m, k); i++) {
		ans[i] = -1;
		b[i] = true;
		b1[i] = true;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[j][i];
		}
	}
	for (int i = 0; i < n; i++) {
		vector<int> v[1000];
		for (int j = 0; j < m; j++) {
			if (a[i][j] > 0 && b[j]) {
				a[i][j]--;
				if (!b1[a[i][j]]) {
					if (ans[j] == -1) {
						ans[j] = i;
						b[j] = false;
					}
				} else {
					v[a[i][j]].push_back(j);
				}
			}
		}
		for (int j = 0; j < k; j++) {
			if (v[j].size() > 1) {
				b1[j] = false;
				for (int g = 0; g < v[j].size(); g++) {
					if (ans[v[j][g]] == -1) {
						ans[v[j][g]] = i;
						b[v[j][g]] = false;
					}
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] + 1 << endl;
	}
	return 0;
}