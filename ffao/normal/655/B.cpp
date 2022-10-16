#include <bits/stdc++.h>

 
using namespace std;


#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int n, k;
long long a;

void solve() {
	scanf("%d %d", &n, &k);
	REP(i, min(n/2,k)) {
		a += 2*(n-2*(i+1))+1;
	}
	printf("%lld\n", a);
}

int main() {
    solve();
}