#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, k;
int c[510000];

void solve() {
	scanf("%d %d", &n, &k);
	REP(i,n) scanf("%d", &c[i]);

	sort(c,c+n);

	long long tot = 0;
	REP(i,n) tot += c[i];
	int rem = tot % n;
	tot /= n;

	long long av = 0;
	long long nd = 0;
	int ot = (tot + !(!rem));

	REP(i,n) {
		if (c[i] > ot) av += c[i]-ot;
		if (c[i] < tot) nd += tot-c[i];
	}

	if (nd <= k && av <= k) {
		printf("%d\n", rem ? 1 : 0);
		return;
	}

	int st = 0, ed = 1000000000;
	while (st < ed) {
		int m = (st+ed)/2;
		nd = 0;
		REP(i,n) {
			if (c[i] > m) nd += c[i]-m;
		}

		if (nd <= k) ed = m;
		else st = m+1;
	}

	int ans = st;
	st = 0, ed = 1000000000;
	while (st < ed) {
		int m = (st+ed+1)/2;
		nd = 0;
		REP(i,n) {
			if (c[i] < m) nd += m-c[i];
		}

		if (nd <= k) st = m;
		else ed = m-1;
	}

	printf("%d\n", ans-st);
}

int main() {
    solve();
}