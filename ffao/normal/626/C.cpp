#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int n,m;

bool check(int n, int m, int md) {
	int m6 = md/6;
	int m2 = md/2 - m6;
	int m3 = md/3 - m6;

	n = max(0,n-m2);
	m = max(0,m-m3);

	return n+m <= m6;
}

int main(){
	scanf("%d %d", &n, &m);

	int st = 0, ed = 100000000;

	while (st < ed) {
		int md = (st+ed)/2;
		if (check(n,m,md)) ed = md;
		else st = md+1;
	}
	
	printf("%d\n", st);
}