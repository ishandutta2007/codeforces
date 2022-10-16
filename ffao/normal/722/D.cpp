#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

typedef vector<int> vi;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int n;
vi a;
set<int> represented;

bool can_represent(int lim) {
	represented.clear();

	vector<int> b = a;

	while (!b.empty()) {
		vector<int> c;
		for (int x : b) {
			if (x > lim || represented.count(x)) {
				if (x == 1) return false;	
				c.push_back(x/2);
			}
			else represented.insert(x);
		}
		swap(b,c);
	}

	return true;
}

void solve() {
	scanf("%d", &n);

	a.resize(n);
	REP(i,n) scanf("%d", &a[i]);

	int st = 1, ed = 1000000000;
	while (st < ed) {
		int md = (st+ed)/2;
		if (can_represent(md)) ed = md;
		else st = md+1;
	}

	can_represent(st);
	for (int x : represented) {
		printf("%d ", x);
	}
	printf("\n");
}


int main() {
    solve();
}