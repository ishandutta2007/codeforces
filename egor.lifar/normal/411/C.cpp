#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int a[2], b[2], c[2], d[2];


int main() {
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];
	cin >> d[0] >> d[1];
	if (a[0] > c[1] && b[1] > d[0]) {
		if (a[0] > d[1] && b[1] > c[0]) {
			cout << "Team 1" << endl;
			return 0;
		}
	}
	if (b[0] > c[1] && a[1] > d[0]) {
		if (b[0] > d[1] && a[1] > c[0]) {
			cout << "Team 1" << endl;
			return 0;
		}
	}
	if ((c[0] > a[1] && d[1] > b[0]) || (d[0] > a[1] && c[1] > b[0])) {

	if ((c[0] > b[1] && d[1] > a[0]) || (d[0] > b[1] && c[1] > a[0])) {
		cout << "Team 2" << endl;
		return 0;
	}
}
	cout << "Draw" << endl;
	return 0;
}