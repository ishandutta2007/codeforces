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
#include <unordered_map>


using namespace std;


int n;
int b[100001];
int d[4001][4001];
int t[4001][4001];
map<int, int> h;



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			t[i][j] = h[b[j]] - 1;
		}
		h[b[i]] = i + 1;
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t[i][j] != -1) {
				d[i][j] = 1 + d[t[i][j]][i];
			} else {
				d[i][j] = 2;
			}
			ans = max(ans, d[i][j]);
		}
	}
	cout << ans << endl;
    return 0;
}