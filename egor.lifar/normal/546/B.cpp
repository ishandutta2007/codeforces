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
int a[100000];
bool used[1000000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	set<int> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (used[a[i]]) {
			a[i]++;
			ans++;
		}
		used[a[i]] = true;
	}
	cout << ans << endl;
	return 0;
}