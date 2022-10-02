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


#define INF 1000000000


int n;
int a[100001];
int d[400001], d1[400001];


void change(int i, int x) {
	d[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i] = min(d[i * 2], d[i * 2 + 1]);
	}
}


void change1(int i, int x) {
	d1[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		d1[i] = max(d1[i * 2], d1[i * 2 + 1]);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ss = 1;
	while (ss < n) {
		ss *= 2;
	} 
	for (int i = 1; i < 2 * ss; i++) {
		change(i, INF);
	}
	int l = -1;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		while (l + 1 < n) {
			change(ss + l + 1, a[l + 1]);
			change1(ss + l + 1, a[l + 1]);
			if (abs(d[1] - d1[1]) <= 1) {
				l++;
				continue;
			}
			change(ss + l + 1, INF);
			change1(ss + l + 1, 0);
			break;
		}
		ans = max(ans, l - i + 1);
		change(ss + i, INF);
		change1(ss + i, 0);
	}
	cout << ans << endl;
	return 0;
}