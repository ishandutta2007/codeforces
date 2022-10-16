#include <bits/stdc++.h>

 
using namespace std;

typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int p[1100000];
int phi[1100000];
int hm[1100000];

long long C[310000];
long long r[310000];
int n, k, q;
const int m = 1000000007;
vector<pii> divi;
long long tot = 0;

void mark_divisors(int idx=0, int cur=1) {
	if (idx == (int)divi.size()) {
		//printf("marking %d, ct->%d, cm->%lld\n", cur, hm[cur]+1, C[hm[cur]+1]);
		tot = (((tot - phi[cur] * 1ll * C[hm[cur]]) % m) + m) % m;
		hm[cur]++;
		tot = (tot + phi[cur] * 1ll * C[hm[cur]]) % m;
		return;
	}

	int fa = 1;
	for (int i = 0; i <= divi[idx].second; i++) {
		mark_divisors(idx+1, cur*fa);
		fa *= divi[idx].first;
	}
}

void solve() {

	for (int i = 2; i < 1100; i++) {
		if (!p[i]) {
			for (int j = i*i; j <= 1001000; j+=i) p[j] = i;
		}
	}

	phi[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		phi[i] = i;
		
		int ti = i;
		while (ti != 1) {
			int pf = p[ti];
			if (pf == 0) pf = ti;
			while (ti % pf == 0) ti /= pf;
			phi[i] /= pf;
			phi[i] *= pf-1; 
		}
	}


	r[1] = 1; for (int i=2; i<300000; ++i) r[i] = (m - (m/i) * r[m%i] % m) % m;

	scanf("%d %d %d", &n ,&k, &q);
	C[k] = 1;
	for (int i = k+1; i <= n+q+10; i++) {
		C[i] = (C[i-1] * 1ll * i) % m;
		C[i] = (C[i] * 1ll * r[i-k]) % m;
	}
	
	REP(i, n+q) {
		int f;
		scanf("%d", &f);
		divi.clear();

		while (f != 1) {
			int pf = p[f];
			if (pf == 0) pf = f;
			int ct = 0;
			while (f % pf == 0) {f /= pf; ct++;}
			divi.emplace_back(pf,ct);
		}

		mark_divisors();
		if (i >= n) printf("%lld\n", tot);
	}
}

int main() {
    solve();
}