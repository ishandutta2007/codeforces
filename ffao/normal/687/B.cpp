#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int n, k;

void solve() {
	scanf("%d %d", &n, &k);	
	
	int d = 1;

	REP(i,n) {
		int v;
		scanf("%d", &v);
		v /= gcd(v, d);
		d *= gcd(k/d, v);
	}

	printf("%s\n", (d==k ? "Yes" : "No"));
}

int main() {
    solve();
}