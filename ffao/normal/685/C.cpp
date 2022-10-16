#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int t, n;

long long sm[4];
long long bg[4];
long long val[4];
long long mx[4];

bool verif(long long mid, bool parity) {
	REP(i,4) {
		val[i] = bg[i]-mid;
		if ((val[i]%2 == 0) ^ parity) val[i]++;
		if (val[i] > sm[i]+mid) return false;

		mx[i] = sm[i]+mid;
		if ((mx[i]%2 == 0) ^ parity) mx[i]--;
		mx[i] = (mx[i]-val[i]);
	}

	long long cur_F = val[0]-val[1]+val[2];
	if (cur_F < val[3]) {
		//printf("mid %lld ADJ LOW\n", mid);
		long long nd = (val[3]-cur_F);
		if (nd <= mx[0]+mx[2] ) {
			long long i0 = min(nd,mx[0]);
			val[0] += i0;
			val[2] += nd-i0; 
			return true;
		}
		else return false;
	}
	else if (cur_F > val[3]+mx[3]) {
		//printf("ADJ HIGH\n");
		long long nd = (cur_F - val[3] - mx[3]);
		if (nd <= mx[1]) {
			val[1] += nd;
			return true;
		}
		else return false;
	}
	else {
		return true;
	}
}

void solve() {
	for (scanf("%d", &t); t; t--) {
		scanf("%d", &n);

		//x+y+z=C
		//x-y+z=D
		//x-y-z=E
		//x+y-z=F

		//F = C-D+E
		REP(i,n) {
			long long x,y,z;
			scanf("%lld %lld %lld", &x, &y, &z);
			val[0]=x+y+z;
			val[1]=x-y+z;
			val[2]=x-y-z;
			val[3]=x+y-z;

			REP(j,4) {
				if (i == 0 || sm[j] > val[j]) sm[j] = val[j];
				if (i == 0 || bg[j] < val[j]) bg[j] = val[j];
			}
		}

		long long st = 0, ed = 3000000000000000000LL;
		while (st < ed) {
			long long mid = st+(ed-st)/2;

			if (verif(mid,true) || verif(mid,false)) ed = mid;
			else st = mid+1;
		}

		bool ok = verif(st,true) || verif(st,false);
		if (ok) {
			//x = (C+E)/2 y = (C-D)/2 z = (D-E)/2
			//printf("st = %lld val1 = %lld val2 = %lld\n", st,val[1], val[2] );
			//assert(val[0] % 2 == val[1] % 2);
			//assert(val[1] % 2 == val[2] % 2);
			printf("%lld %lld %lld\n", (val[0]+val[2])/2, (val[0]-val[1])/2, (val[1]-val[2])/2 );
		}
	}
}

int main() {
    solve();
}