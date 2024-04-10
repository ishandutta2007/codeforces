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

int n;
pair<pii, int> pt[110000];

bool ar(pii a, pii b, pii c) {
	return (a.first - c.first) * 1ll * (b.second - a.second) != (a.first - b.first) * 1ll * (c.second - a.second); 
}


int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		pt[i].second = i;
		scanf("%d %d", &pt[i].first.first, &pt[i].first.second);
	}

	sort(pt,pt+n);

	for (int i = 2; i < n; i++) {
		if (ar(pt[0].first, pt[1].first, pt[i].first)) {
			printf("%d %d %d\n", pt[0].second+1, pt[1].second+1, pt[i].second+1);
			return 0;
		}
	}
}