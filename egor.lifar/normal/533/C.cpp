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


int x, y, x1, y11;


void get() {
	int t = x1 - x;
	if (t <= 0) {
		return;
	}
	int v = max(0, y11 - t);
	int t1 = y - v;
	if (t1 <= t) {
		printf("Polycarp\n");
		exit(0);
	}
}


int main() {
	cin >> x >> y >> x1 >> y11;
	get();
	swap(x, y);
	swap(x1, y11);
	get();
	printf("Vasiliy\n");
    return 0;
}