#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n, m;
int a[100001];
int b[100001];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int l = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (l < m && b[l] < a[i]) {
			l++;
		}
		if (l >= m) {
			ans++;
		}	
		l++;
	}
	cout << ans << endl;
    return 0;
}