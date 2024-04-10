#include <stdio.h>
#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int dd[4];

void solve() {
	int a,b,c,d,n;
	REP(i,4) scanf("%d", &dd[i]);
	scanf("%d", &n);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int a = 0;
		REP(j,4) a += !(i % dd[j]);
		if (a) ans++;
	}
	printf("%d\n", ans);
}


int main() {
    solve();
}