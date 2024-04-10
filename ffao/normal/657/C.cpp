#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


vector<int> vals[5];

int n,k,b,c;
int le[5], rr[5];
int cost5;

long long get_cost(int idx, int tgt, int kk=-1) {
	if (kk == -1) kk = le[idx];
	int cur = vals[idx][kk];
	long long cc = 0;

	while (((cur%5)+5)%5 != ((tgt%5)+5)%5) {
		cc += c;
		cur++;
	}

	return cc + cost5 * 1ll * ((tgt-cur)/5);
}

void solve() {
	scanf("%d %d %d %d", &n, &k, &b, &c);

	cost5 = min(b, c*5);

	REP(i,n) {
		int a;
		scanf("%d", &a);
		vals[((a%5)+5)%5].push_back(a);
	}
	REP(i,5) sort(vals[i].begin(), vals[i].end());

	long long best = 1000000000000000000LL;
	for (int init = 0; init < 5; init++) {
		REP(i,5) le[i]=rr[i]=0;

		int curlen = 0;
		long long curct = 0;
		int tgt = init;

		while (1) {
			int midx = -1;
			REP(i,5) {
				if (rr[i] != (int)vals[i].size()) {
					if (midx == -1 || vals[midx][rr[midx]] > vals[i][rr[i]]) {
						midx = i;
					}
				}
			}
			if (midx == -1) break;

			int new_addt = vals[midx][rr[midx]];
			int new_tgt = new_addt;
			while (((new_tgt%5)+5)%5 != init) new_tgt++;

			int diff = new_tgt - tgt;
			curct += curlen * 1ll * cost5 * 1ll * (diff/5);
			curct += get_cost(midx, new_tgt, rr[midx]);
			tgt = new_tgt;

			rr[midx]++;
			curlen++;

			if (curlen > k) {
				int midx = -1;
				REP(i,5) {
					if (le[i] != rr[i]) {
						if (midx == -1 || get_cost(i,tgt) > get_cost(midx,tgt)) {
							midx = i;
						}
					}
				}

				curct -= get_cost(midx, tgt);
				le[midx]++;
				curlen--;
			}

			//printf("mod %d up to %d gives %lld diff %d mi %d \n", init, tgt, curct,diff,midx);
			if (curlen == k) best = min(best, curct);
		}
	}

	printf("%lld\n", best);
}

int main() {
    solve();
}