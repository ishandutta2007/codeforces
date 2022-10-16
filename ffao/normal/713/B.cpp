#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;


int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);

	int ans;
	scanf("%d", &ans);
	return ans;
}

void pp( pii p) {
	printf(" %d %d", p.first, p.second);
}

void answer(pair< pii, pii > rect1, pair <pii, pii> rect2) {
	printf("!");
	pp(rect1.first);
	pp(rect1.second);
	pp(rect2.first);
	pp(rect2.second);
	printf("\n");
	fflush(stdout);
}


pair< pii, pii > find (int left, int down, int right, int up) {
	// search left
	int st = left, ed = right;
	while (st < ed) {
		int md = (st+ed+1)/2;
		if (query(md, down, right, up) == 1) st = md;
		else ed = md-1;
	}
	left = st;

	// search right 
	st = left, ed = right;
	while (st < ed) {
		int md = (st+ed)/2;
		if (query(left, down, md, up) == 1) ed = md;
		else st = md+1;
	}
	right = st;

	// search down
	st = down, ed = up;
	while (st < ed) {
		int md = (st+ed+1)/2;
		if (query(left, md, right, up) == 1) st = md;
		else ed = md-1;
	}
	down = st;

	// search up 
	st = down, ed = up;
	while (st < ed) {
		int md = (st+ed)/2;
		if (query(left, down, right, md) == 1) ed = md;
		else st = md+1;
	}
	up = st;

	return {{left, down}, {right, up}};
}

int n;
void solve() {
	scanf("%d", &n);

	int st = 1, ed = n;
	while (st < ed) {
		int md = (st+ed)/2;
		if (query(1, 1, md, n) == 0) st = md+1;
		else ed = md;
	}	

	if (query(1,1,st,n) == 1 && query(st+1,1,n,n) == 1) {
		pair< pii, pii > rect1 = find(1,1,st,n);
		pair< pii, pii > rect2 = find(st+1,1,n,n);
		answer(rect1, rect2);
		return;
	}

	st = 1;
	ed = n;
	while (st < ed) {
		int md = (st+ed)/2;
		if (query(1, 1, n, md) == 0) st = md+1;
		else ed = md;
	}	

	pair< pii, pii > rect1 = find(1,1,n,st);
	pair< pii, pii > rect2 = find(1,st+1,n,n);
	answer(rect1, rect2);
}


int main() {
    solve();
}