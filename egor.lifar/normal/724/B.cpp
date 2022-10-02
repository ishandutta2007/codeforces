#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int n, m;
int a[31][31];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i1 = 0; i1 < m; i1++) {
		for (int j1 = i1; j1 < m; j1++) {
			for (int i = 0; i < n; i++) {
				swap(a[i][i1], a[i][j1]);
			}
			bool b = 1;
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				for (int j = 0; j < m; j++) {
					if (a[i][j] != j + 1) {
						cnt++;
					}
				}
				if (cnt > 2) {
					b = 0;
				}
			}
			if (b) {
				printf("YES\n");
				return 0;
			}
			for (int i = 0; i < n; i++) {
				swap(a[i][i1], a[i][j1]);
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}