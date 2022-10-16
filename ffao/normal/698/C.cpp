#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n,k;
double p[30];
double pb[1<<21];
double ans[30];

bool in(int a, int b) {
	return (1<<b)&a;
}

void solve() {
	scanf("%d %d", &n, &k);
	REP(i,n) scanf("%lf", &p[i]);

	pb[0] = 1;
	for (int i = 0; i < (1<<n); i++) {
		double s = 0;
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (!in(i,j)) {
				s += p[j];
				cnt++;
			}
		}

		for (int j = 0; j < n; j++) if (!in(i,j) && s > 0) {
			if (__builtin_popcount(i) < k) ans[j] += pb[i] * (p[j]/s);
			pb[i|(1<<j)] += pb[i] * (p[j]/s);
		}
	}

	REP(i,n) printf("%.15f ", ans[i]);
	printf("\n");
}

int main() {
    solve();
}