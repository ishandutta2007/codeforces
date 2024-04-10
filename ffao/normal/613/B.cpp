#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


int n, a, cf, cm;
long long m;

pair<int, int> sk[110000];
int ans[110000];
long long eq[110000];

void solve() {
	scanf("%d %d %d %d %lld", &n, &a, &cf, &cm, &m);
	REP(i,n) scanf("%d", &sk[i].first);
	REP(i,n) sk[i].second = i;
	sort(sk, sk+n);

	eq[0] = eq[1] = 0;
	for (int i = 2; i <= n; i++) {
		eq[i] = eq[i-1] + (i-1) * 1ll * (sk[i-1].first - sk[i-2].first);
	}

	reverse(sk, sk+n);

	long long best = 0;
	int best_ma = 0;
	long long best_mi = 0;
	long long need = 0;
	int can_eq = n;

	for (int ma = 0; ma <= n; ma++) {
		if (ma != 0) need += a - sk[ma-1].first;
		if (need > m) break;
		long long have = m - need;
		
		while (can_eq + ma > n || eq[can_eq] > have) can_eq--;
		have -= eq[can_eq];
		long long st;
		if (can_eq) st = min((long long)a, sk[n - can_eq].first + have / can_eq);
		else st = a;

		long long cur = st * 1ll * cm + ma * 1ll * cf;
		if (cur > best) {
			best = cur;
			best_ma = ma;
			best_mi = st;
		}
	}

	REP(i, best_ma) sk[i].first = a;
	REP(i, n) ans[ sk[i].second ] = max(sk[i].first, (int)best_mi);

	printf("%lld\n", best);
	REP(i,n) printf("%d ", ans[i]);
	printf("\n");
}


int main() {
    solve();
}