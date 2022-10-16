#include <stdio.h>
#include <bits/stdc++.h>

 
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int a[610000];
int L[610000];

void solve() {
	int n;
	scanf("%d", &n);
	
	long long sum = 0;
	REP(i,n) {
		scanf("%d", &a[i]);	
		sum += a[i];
	}

	if (sum % 3 != 0) {
		printf("0\n");
		return;
	}
	sum /= 3;

	long long ans = 0;
	long long cur_sum = 0;
	REP(i,n) {
		cur_sum += a[i];
		L[i+2] = L[i+1] + (cur_sum == sum);
	}

	cur_sum = 0;
	for (int i = n-1; i >= 0; i--) {
		cur_sum += a[i];
		if (cur_sum == sum) ans += L[i];
	}

	printf("%lld\n", ans);
}


int main() {
    solve();
}