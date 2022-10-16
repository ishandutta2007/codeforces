#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int a[1100];
int n;

void solve() {
	scanf("%d", &n);
	REP(i,n) {
		scanf("%d", &a[i]);
	}

	sort(a,a+n);
	n = unique(a, a+n) - a;
	for (int i = 0; i+2 < n; i++) {
		if (a[i] == a[i+1]-1 && a[i] == a[i+2]-2) {
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main() {
    solve();
}