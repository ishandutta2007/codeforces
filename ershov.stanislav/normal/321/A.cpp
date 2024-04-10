#include <cstdio>
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

string s;
int a, b;

int main() {
	cin >> a >> b >> s;
	int x=0, y=0, xx=0, yy=0;
	for (int i=0; i<(int)s.length(); i++) {
		if (s[i]=='U') y++;
		else if (s[i]=='D') y--;
		else if (s[i]=='R') x++;
		else if (s[i]=='L') x--;
	}
	for (int i=0; i<(int)s.length(); i++) {
		if (xx==a&&yy==b) {
			cout << "Yes";
			return 0;
		}
		if (x!=0&&y==0&&yy==b) {
			if ((a-xx)%x==0&&(a-xx)/x>=0) {
				cout << "Yes";
				return 0;
			}
		}
		if (y!=0&&x==0&&xx==a) {
			if ((b-yy)%y==0&&(b-yy)/y>=0) {
				cout << "Yes";
				return 0;
			}
		}
		if (x!=0&&y!=0) {
			if ((a-xx)%x==0&&(b-yy)%y==0&&(a-xx)/x==(b-yy)/y&&(a-xx)/x>=0) {
				cout << "Yes";
				return 0;
			}
		}
		if (s[i]=='U') yy++;
		else if (s[i]=='D') yy--;
		else if (s[i]=='R') xx++;
		else if (s[i]=='L') xx--;
	}
	cout << "No";
	return 0;
}