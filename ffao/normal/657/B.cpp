#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, k;

long long rep[310000];
long long ren[310000];
long long re[310000];
long long a[310000];

void simp(long long* a) {
	long long ca = 0;
	REP(i,300000) {
		a[i] += ca;
		ca = a[i]/2;
		a[i] -= 2*ca;
	}
}

void comp(long long *r) {
	REP(i,300000) r[i] = 1-r[i];
	r[0]++;
	simp(r);
}

void ad(long long *a, long long *b, long long *r) {
	REP(i,300000) r[i] = a[i]+b[i];
	simp(r);
}

void pu(long long *r, int i, vector<int>& v) {
	REP(x, v.size()) {
		r[i+x] += v[x];
	}
}

bool down;

bool check(int i, int la) {
	long long na = 0;
	long long po = 1;
	for (int j = i; j <= la; j++) {
		na += po * re[j];
		po <<= 1;
	}
	//printf("to change %d, change %lld\n", i, na);
	long long diff = (down ? a[i]-na : a[i]+na);
	//printf("diff=%lld\n", diff);
	if (diff < 0) diff = -diff;
	return diff <= k && (i != n || diff);
}

void solve() {
	scanf("%d %d", &n, &k);

	REP(i,n+1) { 
		scanf("%lld", &a[i]);
		bool neg = false;
		long long taa = a[i];
		if (taa < 0) {
			neg = true;
			taa = -taa;
		}

		vector<int> v;
		while (taa != 0) {
			v.push_back(taa&1);
			taa/=2;
		}
		//printf("hi\n");

		if (neg) pu(ren, i, v);
		else pu(rep, i, v);
	}

	simp(ren); simp(rep);
	comp(ren);
	ad(rep,ren,re);

	down = true;
	if (re[299999] == 1) {
		down = false;
		comp(re);
	}
	/*printf("down = %d\n", down);
	REP(i, 20) {
		printf("%lld ", re[i]);
	}
	printf("\n");
*/
	int la = 0;
	REP(i, 300000) {
		if (re[i]) la = i;
	}

	
	int ans = 0;
	REP(i, n+1) {
		if (la-i <= 50) {
			ans += check(i, la);
		}

		if (re[i]) break;
	}

	printf("%d\n", ans);
}

int main() {
    solve();
}