#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int c[510];
int kn[2][510][510];
int n,k;

void solve() {
	scanf("%d %d", &n, &k);

	REP(i,n) scanf("%d", &c[i]);

	kn[0][0][0]=1;
	for (int i = 1; i <= n; i++) {
		int coin = c[i-1];

		int ti = i&1;
		int pi = ti^1;

		for (int v1 = 0; v1 <= k; v1++) {
			for (int v2 = 0; v2 <= k; v2++) {
				kn[ti][v1][v2] = kn[pi][v1][v2];
				if (v1 >= coin && kn[pi][v1-coin][v2]) kn[ti][v1][v2]=1;
				else if (v2 >= coin && kn[pi][v1][v2-coin]) kn[ti][v1][v2]=1;
			}
		}
	}

	vector<int> ans;
	for (int v = 0; v <= k; v++) if (kn[n&1][v][k-v]) {
		ans.push_back(v);
	}

	printf("%d\n", ans.size());
	for (int x : ans) printf("%d ", x);
	printf("\n");
}

int main() {
    solve();
}