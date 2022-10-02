#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


#define INF 1000000007


int n;
int a[500];
map<int, int> m;



void get(int x) {
	int s = (int)sqrt(x);
	for (int i = 2; i <= s; i++) {
		if (x % i == 0) {
			while (x % i == 0) {
				x /= i;
				m[i]++;
			}
		}
		if (x == 1) {
			break;
		}
	}
	if (x != 1) {
		m[x]++;
	}
}



long long c[20001][501];



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		get(a[i]);
	}
	for (int i = 0; i <= 20000; i++) {
		if (i == 0) {
			c[i][0] = 1;
			continue;
		}
		for (int j = 0; j <= 500; j++) {
			if (j == 0){
				c[i][j] = 1;
				continue;
			}
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % INF;
		}
	}
	long long ans = 0;
	bool b = true;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		int s = (*it).second;
		if (s != 0) {
			b = false;
		}
		if (ans == 0) {
			ans = c[s + n - 1][n - 1];
		} else {
			ans = (ans * c[s + n - 1][n - 1]) % INF;
		}
	}
	if (b) {
		ans = 1;
	}
	cout << ans << endl;
	return 0;
}