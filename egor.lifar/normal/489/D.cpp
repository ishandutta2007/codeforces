#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n, m;
vector<int> v[100000];
long long ans = 0;
bool b[3000][3000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b1;
		cin >> a >> b1;
		v[a - 1].push_back(b1 - 1);
		b[b1 - 1][a - 1] = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int t = 0;
				for (int k = 0; k < v[i].size(); k++) {
					int x = v[i][k];
					if (x != j && b[j][x]) {
						t++;
					}
				}
				ans += (t * (t - 1)) / 2;
			}
		}
	}
	cout << ans << endl;
    return 0;
}