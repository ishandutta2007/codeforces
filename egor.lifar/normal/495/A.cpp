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
#include <assert.h>
#include <stdlib.h>


using namespace std;


int n;



int main() {
	cin >> n;
	int a = n / 10;
	int b = n % 10;
	int ans = 0;
	for (int i = 0; i <= 99; i++) {
		int c = i / 10;
		int d = i % 10;
		bool bb = true;
		if (c != a) {
			bb = false;
			if (c == 6 && a == 5) {
				bb = true;
			}
			if (c == 8) {
				bb = true;
			}
			if (c == 9 && a != 2 && a != 6 && a != 8 && a != 0) {
				bb = true;
			}
			if (c == 0 && a == 1) {
				bb = true;
			}
			if (c == 3 && a == 1) {
				bb = true;
			}
			if (c == 7 && a== 1) {
				bb = true;
			}
			if (c == 9 && a == 1) {
				bb = true;
			}
			if (c == 4 && a == 1) {
				bb = true;
			}
			if (c == 0 && a == 7) {
				bb = true;
			}
			if (c == 3 && a == 7) {
				bb = true;
			}
		}	
		bool b1 = true;
		if (d != b) {
			b1 = false;
			if (d == 6 && b == 5) {
				b1 = true;
			}
			if (d == 8) {
				b1 = true;
			}
			if (d == 9 && b != 2 && b != 6 && b != 8 && b != 0) {
				b1 = true;
			}
			if (d == 0 && b == 1) {
				b1 = true;
			}
			if (d == 3 && b == 1) {
				b1 = true;
			}
			if (d == 7 && b == 1) {
				b1 = true;
			}
			if (d == 9 && b == 1) {
				b1 = true;
			}
			if (d == 0 && b == 7) {
				b1 = true;
			}
			if (d == 3 && b == 7) {
				b1 = true;
			}
			if (d == 4 && b == 1) {
				b1 = true;
			}
		}
		if (b1 && bb) {
			//cout << i << endl;
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}