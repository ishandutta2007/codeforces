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

using namespace std;

int xx[100002], yy[100002], zz[100002];
int n, l[100002], r[100002], m;

int main() {
	string s;
	cin >> s >> m;
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i];
	}
	n = s.size();
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'x'){
			xx[i] += 1;
		}
		if(s[i - 1] == 'y'){
			yy[i] += 1;
		}
		if(s[i - 1] == 'z'){
			zz[i] += 1;
		}
		if(i > 1){
			xx[i] += xx[i - 1];
			yy[i] += yy[i - 1];
			zz[i] += zz[i - 1];
		}
	}
	for(int i = 0; i < m; i++){
		if(r[i] - l[i] + 1 < 3){
			cout << "YES\n";
			continue;
		}
		int x, y, z;
		x = xx[r[i]] - xx[l[i] - 1];
		y = yy[r[i]] - yy[l[i] - 1];
		z = zz[r[i]] - zz[l[i] - 1];
		if(abs(x - z) >= 2 || abs(y - z) >= 2 || abs(x - y) >= 2){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	return 0;
}