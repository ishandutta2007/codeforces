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


int n;
int p[100001];
int c[100001];


int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		c[p[i] - 1] = i;
	}
	int ans = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)  {
		if (i != 0 && c[i] < c[i - 1]) {
			cnt = 0;
		}
		cnt++;
		ans = max(ans, cnt);
	}
	cout << n - ans << endl;
	return 0;
}