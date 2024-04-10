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


int n;
int a[100000][2];
string s, s1;


int main() {
	cin >> s >> s1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		char c, c1;
		int r;
		scanf("%d %c %d %c", &t, &c, &r, &c1);
		if (c == 'h') {
			if (a[r][0] != -1) {
				a[r][0]++;
			}
		} else {
			if (a[r][1] != -1) {
				a[r][1]++;
			}
		}
		if (c == 'h') {
			if ((a[r][0] == 2 || c1 == 'r') && (a[r][0] != -1)) {
				cout << s << ' ' << r << ' ' << t << endl;
				a[r][0] = -1;
			}
		} else {
			if ((a[r][1] == 2 || c1 == 'r') && (a[r][1] != -1)) {
				cout << s1 << ' ' << r << ' ' << t << endl;
				a[r][1] = -1;
			}
		}
	}
    return 0;
}