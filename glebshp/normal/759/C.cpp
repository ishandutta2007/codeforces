#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int rms = (1 << 20) - 1;
const int hrms = rms / 2;
const int size = 1000 * 1000 + 10;

struct element {
	int toclose, toopen;

	element() {}

	element(int c, int o) : toclose(c), toopen(o) {}
};

element rmq[rms + 1];
int x[size];

element operator + (const element& a, const element& b) {
	element result;
	result.toclose = a.toclose + max(0, b.toclose - a.toopen);
	result.toopen = b.toopen + max(0, a.toopen - b.toclose);

	return result;
}

void change(int p, element val) {
	p += hrms + 1;
	rmq[p] = val;
	while (p > 1) {
		p /= 2;
		rmq[p] = rmq[p * 2] + rmq[p * 2 + 1];
	}
}

int getposition() {
	int p = 1;
	int k = 0;
	if (rmq[p].toopen == 0) {
		return -1;
	}

	while (p <= hrms) {
		if (rmq[p * 2 + 1].toopen > k) {
			p = p * 2 + 1; 	
		} else {
			k -= rmq[p * 2 + 1].toopen;
			k += rmq[p * 2 + 1].toclose;
			p = p * 2;
		}
	}

	return p - hrms - 1;
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

	for (int i = 0; i <= rms; i++) {
		rmq[i] = element(0, 0);
	}

    int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int p, tp;
		scanf("%d%d", &p, &tp);
		p--;
		if (tp == 1) {
			scanf("%d", &x[p]);
			change(p, element(0, 1));
		} else {
			change(p, element(1, 0));
		}

		int ans = getposition();
		if (ans != -1) {
			ans = x[ans];
		}
		printf("%d\n", ans);
	}

    return 0;
}