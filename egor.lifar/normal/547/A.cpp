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


#define y1 yyy1


long long M, h1, a1, x1, y1, h2, a2, x2, y2;


int main() {
	cin >> M >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	int t = h1;
	int l = -1;
	for (int j = 0; j <= M + 1; j++) {
		if (t == a1) {
			l = j;
			break;
		}
		t = (1LL * t * x1 + 1LL * y1) % M;
	}
	if (l == -1) {
		cout << l << endl;
		return 0;
	} 
	int t1 = h2;
	int l1 = -1;
	for (int j = 0; j <= M + 1; j++) {
		if (t1 == a2) {
			l1 = j;
			break;
		}
		t1 = (1LL * t1 * x2 + 1LL * y2) % M;
	}
	if (l1 == -1) {
		cout << l1 << endl;
		return 0;
	} 
	if (l == l1) {
		cout << l << endl;
		return 0;
	}
	//cout << l << ' ' << l1 << endl; 
	int k = 0;
	t = a1;
	for (int i = 0; i <= M + 1; i++) {
		t = (1LL * t * x1 + 1LL * y1) % M;
		if (t == a1) {
			k = i + 1;
			break;
		}
	}
	int k1 = 0;
	t1 = a2;
	for (int i = 0; i <= M + 1; i++) {
		t1 = (1LL * t1 * x2 + 1LL * y2) % M;
		if (t1 == a2) {
			k1 = i + 1;
			break;
		}
	}
	//cout << k << endl;
	long long lll = l;
	for (int i = 0; i <= 3000000; i++) {
		if (lll >= 1LL * l1 && (lll == l1 || (k1 != 0 && (lll - 1LL * l1) % (1LL * k1) == 0))) {
			cout << lll << endl;
			return 0;
		}
		lll += 1LL * k;
	}
	cout << -1 << endl;
	return 0;	
}////