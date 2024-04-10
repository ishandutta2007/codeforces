#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

#include <vector>
#include <utility>


#include <algorithm>


char s[210000];
char t[210000];
int n;

int idx[30][30];

void solve() {
	scanf("%d", &n);
	scanf("%s %s", s, t);

	memset(idx,-1,sizeof(idx));

	int dist = 0;
	REP(i,n) {
		if (s[i] != t[i]) {
			idx[ s[i] - 'a' ][t[i] - 'a'] = i+1;
			dist++;
		}
	}

	int ans = dist;
	int idx1 = -1, idx2 = -1;

	REP(i, 26) REP(j, 26) REP(k, 26) {
		if (idx[i][j] != -1 && idx[j][k] != -1) {
			idx1 = idx[i][j];
			idx2 = idx[j][k];
			ans = min(ans,dist-1);
		}

		if (idx[i][j] != -1 && idx[j][i] != -1) {
			printf("%d\n", dist-2);
			printf("%d %d\n", idx[i][j], idx[j][i]);
			return;
		}
	}

	printf("%d\n", ans);
	printf("%d %d\n", idx1, idx2);
}


int main() {
    solve();
}