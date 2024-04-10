#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int color[5010][5010];
int dom[5010][5010];
int cnt[5010];
int n;

void solve() {
	scanf("%d", &n);
	REP(i,n) {
		int c;
		scanf("%d", &c); c--;

		REP(j,n) color[j][i+1]=color[j][i];
		color[c][i+1]++;

		dom[i][i] = c;
		cnt[c]++;
	}

	for (int st = 0; st < n; st++) {
		for (int ed = st+1; ed < n; ed++) {
			pair<int, int> cand1 = {color[dom[st][ed-1]][ed+1] - color[dom[st][ed-1]][st], -dom[st][ed-1]};
			pair<int, int> cand2 = {color[dom[ed][ed]][ed+1] - color[dom[ed][ed]][st], -dom[ed][ed]};
			dom[st][ed] = -max(cand1,cand2).second;
			cnt[dom[st][ed]]++;
		}
	}

	REP(i,n) printf("%d ", cnt[i]);
	printf("\n");
}

int main() {
    solve();
}