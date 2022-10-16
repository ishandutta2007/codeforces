#include <stdio.h>
#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


void solve() {
	int n;
	long long x1, y1;
	long long x2, y2;

	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%d", &n);

	int ans = 0;
	REP(i,n) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		long long ff = a * x1 + b * y1 + c;
		long long ss = a * x2 + b * y2 + c;

		if ((ff > 0) ^ (ss > 0)) ans++;
	}

	printf("%d\n", ans);
}


int main() {
    solve();
}