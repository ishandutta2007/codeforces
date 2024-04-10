#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>	
using namespace std;


const int MaxN = 100001;
const int MD = 60;


int a[MaxN];
int rmq[4 * MaxN][MD];


void ver1(int x, int* ans) {
	for (int i = 0; i < MD; i++) {
		if (i % x == 0) {
			ans[i] = 2;
		} else {
			ans[i] = 1;
		}
	}
}


void merge(int* n1, int* n2, int* ans) {
	for (int i = 0; i < MD; i++) {
		ans[i] = n1[i] + n2[(i + n1[i]) % MD];
	}
}


int lv, rv;


void get_rmq(int v, int l, int r, int* ans) {
	if ((lv <= l) && (r <= rv)) {
		for (int i = 0; i < MD; i++) {
			ans[i] = rmq[v][i];
		}
	} else {
		int md = (l + r) / 2;
		if (rv <= md) {
			get_rmq(v * 2 + 1, l, md, ans);
		} else if (lv > md) {
			get_rmq(v * 2 + 2, md + 1, r, ans);
		} else {
			int a1[MD], a2[MD];
			get_rmq(v * 2 + 1, l, md, a1);
			get_rmq(v * 2 + 2, md + 1, r, a2);
			merge(a1, a2, ans);
		}
	}
}


void modify_rmq(int v,  int l, int r) {
	if (l == r)	{
		ver1(rv, rmq[v]);
	} else {
	    if (lv <= (l + r) / 2) {
	    	modify_rmq(v * 2 + 1, l, (l + r) / 2);
	    } else {
	    	modify_rmq(v * 2 + 2, (l + r) / 2 + 1, r);
	    }
		merge(rmq[v * 2 + 1], rmq[v * 2 + 2], rmq[v]);
	}
}


void create_rmq(int v, int l, int r) {
	if (l == r) {
		ver1(a[l], rmq[v]);
	} else {
		create_rmq(v * 2 + 1, l, (l + r) / 2);
		create_rmq(v * 2 + 2, (l + r) / 2 + 1, r);
	    merge(rmq[v * 2 + 1], rmq[v * 2 + 2], rmq[v]);
	}
}


int n, q;
int av[MaxN];


int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	create_rmq(0, 1, n);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		char c, d;
		scanf("%c %c %d %d", &d, &c, &lv, &rv);
		if (c == 'C') {
			modify_rmq(0, 1, n);
		} else {
			rv--;
			get_rmq(0, 1, n, av);
			printf("%d\n", av[0]);
		}
	}
	return 0;
}