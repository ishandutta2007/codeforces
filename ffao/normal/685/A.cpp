#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, m;
int sn[10];

void solve() {
	scanf("%d %d", &n, &m);

	int dn = 0, dm = 0;
	int tn =n-1, tm=m-1;
	while (tn) {
		tn /= 7;
		dn++;
	}
	while (tm) {
		tm /= 7;
		dm++;
	}
	if (n == 1) dn++;
	if (m == 1) dm++;

	if (dn + dm > 7) {
		printf("0\n");
		return;
	}

	int ans = 0;
	REP(i,n) {
		REP(j,m) {
			REP(k,7) sn[k]=0;
			
			int ti = i;
			int dd = dn+dm;
			
			while (ti) {
				sn[ti % 7]++;
				ti /= 7;
				dd--;
			}

			ti = j;
			while (ti) {
				sn[ti % 7]++;
				ti /= 7;
				dd--;
			}

			REP(k,dd) sn[0]++;

			bool ok = true;
			REP(k,7) if (sn[k]>1) ok=false;
			ans += ok;
		}
	}

	printf("%d\n", ans);
}

int main() {
    solve();
}