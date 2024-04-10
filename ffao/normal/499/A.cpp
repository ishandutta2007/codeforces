#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int l[110], r[110];


void solve() {
	int n, x;
	scanf("%d %d", &n, &x);

	int lim = 0;
	REP(i, n) {
		scanf("%d %d", &l[i], &r[i]);
		lim = max(lim, r[i]);
	}

	int tot = 0;
	for (int tm = 1; tm <= lim; tm++) {
		int lm = tm+x;

		for (int i = 0; i < n; i++) {
			if (l[i] <= tm && r[i] >= tm) lm = tm;
			if (l[i] > tm) lm = min(lm, l[i]); 
		}

		if (lm == tm+x) tm += x-1;
		else {
			tot += lm-tm+1; 
			tm = lm;
		}
	}

	printf("%d\n", tot);
}


int main() {
    solve();
}