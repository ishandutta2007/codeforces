#include <iostream>
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
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <string.h>



using namespace std;


const int MaxN = 101000;
int n, p, q, a[MaxN], b[MaxN];


long double ff(long double x) {
	long double mv = 1;
	for (int i = 0; i < n; i++) {
		mv = min(mv, (1 - b[i] * x) / a[i]);
	}
	return mv * p + x * q;
}


int main() {
	scanf("%d %d %d", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	long double l = 0, r = 1. / (*max_element(b, b + n));
	for (int i = 0; i < 200; i++) {
		long double fl = (l + l + r) / 3, fr = (r + r + l) / 3;
		if (ff(fl) > ff(fr)) {
			r = fr; 
		} else {
			l = fl;
		}
	}
	printf("%.10f\n", (double)ff((l + r) / 2));
	return 0;
}