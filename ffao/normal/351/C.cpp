#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int n, m;
int open[21];
int closed[21];

int mincost[52][52];
long long mat[41][41];
long long temp[41][41];
long long costs[41];
long long nw_costs[41];

void rec(int idx, int curr, int need, int cost) {
	if (idx == n) {
		mincost[need][curr+22] = min(mincost[need][curr+22], cost);
		return;
	}

	rec(idx+1, curr+1, need, cost + open[idx]);
	rec(idx+1, curr-1, max(need, -curr+1), cost + closed[idx]);
}

void solve() {
	scanf("%d %d", &n, &m);
	REP(i,n) scanf("%d", &open[i]);
	REP(i,n) scanf("%d", &closed[i]);

	REP(i,52) REP(j,52) mincost[i][j] = 10000000;
	rec(0, 0, 0, 0);

	REP(from, 41) REP(to, 41) {
		mat[from][to] = -1;

		int diff = to-from;
		if (abs(diff) > 20) continue;
		REP(need, from+1) if (mincost[need][diff+22] != 10000000) {
			if (mat[from][to] == -1 || mat[from][to] > mincost[need][diff+22]) {
				//printf("upd %d %d %d %d %d\n", from,to,need,diff, mincost[need][diff+22]);
				mat[from][to] = mincost[need][diff+22];
			}
		}
	}

	costs[0] = 0;
	for (int i = 1; i <= 40; i++) costs[i] = -1;

	//printf("%lld\n", mat[22][2]);
	//printf("%d\n", mincost[22][2]);
	while (m) {
		if (m&1) {
			for (int i = 0; i <= 40; i++) nw_costs[i] = -1;

			for (int from = 0; from <= 40; from++) {
				for (int to = 0; to <= 40; to++) {
					if (mat[from][to] != -1 && costs[from] != -1 && (nw_costs[to] == -1 || mat[from][to] + costs[from] < nw_costs[to])) {
						nw_costs[to] = mat[from][to] + costs[from]; 	
					}
				}
			}

			memcpy(costs, nw_costs, sizeof(costs));
		}

		/*printf(">>>\n");
		REP(i,40) {
			REP(j,40) printf("%lld ", mat[i][j]);
			printf("\n");
		}
		printf("<<<\n");
		*/

		for (int from = 0; from <= 40; from++) {
			for (int to = 0; to <= 40; to++) temp[from][to] = -1;
			for (int inter = 0; inter <= 40; inter++) {
				for (int to = 0; to <= 40; to++) {
					if (mat[from][inter] != -1 && mat[inter][to] != -1 && (temp[from][to] == -1 || mat[from][inter] + mat[inter][to] < temp[from][to])) {
						temp[from][to] = mat[from][inter] + mat[inter][to];
					}
				}
			}
		}

		memcpy(mat, temp, sizeof(temp));
		m >>= 1;
	}

	printf("%lld\n", costs[0]);
}


int main() {
    solve();
}