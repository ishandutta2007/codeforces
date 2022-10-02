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


int W, B;
map<pair<int, int>, double> m;


double win(int w, int b) {
	if (w <= 0) {
		return 0;
	}
	if (b <= 0) {
		return 1;
	}
	pair<int, int> p = make_pair(w, b);
	if (m.find(p) != m.end()) {
		return m[p];
	}
	double vervg = w * 1.0 / (w + b);
	double verpr = b * 1.0 / (w + b);
	b--;
	verpr *= b * 1.0 / (w + b);
	b--;
	if (verpr > 0.0000000001) {
		double pb = win(w, b - 1) * (b * 1.0 / (w + b));
		double pw = win(w - 1, b) * (w * 1.0 / (w + b));
		vervg += verpr * (pb + pw);
	} 
	m[p] = vervg;
	return vervg;
}


int main() {
	cin >> W >> B;
	printf("%.10lf\n", win(W, B));
	return 0;	
}