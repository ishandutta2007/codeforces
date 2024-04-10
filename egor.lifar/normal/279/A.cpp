#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
 

using namespace std;


int a, b;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main() {
	int x = 0;
	int y = 0;
	cin >> a >> b;
	int t = 1;
	int k = 0;
	int p = 0;
	int s = 0;
	while (true) {
		k++;
		if (k == 3) {
			k = 1;
			t++;
		}
		for (int i = 0; i < t; i++) {
			if (x == a && y == b) {
				cout << p << endl;
				return 0;
			}
			x += dx[s];
			y += dy[s];
		}
		if (x == a && y == b) {
			cout << p << endl;
			return 0;
		}
		p++;
		s++;
		s %= 4;
	}
	return 0;
}