#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXR=110;
const int MAXC=10010;

//char table[MAXR][MAXC];
int best[MAXR][MAXC];
int rows, cols;

char table[MAXC*2];
int pl[MAXC*2], pr[MAXC*2];
void solve() {
	scanf("%d%d", &rows, &cols);
	for(int i=1; i<=rows; ++i) {
		scanf("%s", table+1);
		for(int j=1; j<=cols; ++j)
			table[j+cols]=table[j];
		pl[0]=-1;
		for(int j=1; j<=cols*2; ++j)
			if(table[j]=='1') pl[j]=j;
			else pl[j]=pl[j-1];
		if(pl[cols*2]<0) {
			printf("-1\n"); return;
		}
		pr[cols*2+1]=-1;
		for(int j=cols*2; j>=1; --j)
			if(table[j]=='1') pr[j]=j;
			else pr[j]=pr[j+1];
		for(int j=1; j<=cols*2; ++j) {
			int cur=1<<30;
			if(pl[j]>0) cur=min(cur, j-pl[j]);
			if(pr[j]>0) cur=min(cur, pr[j]-j);
			if(j<=cols) best[i][j]=cur;
			else best[i][j-cols]=min(best[i][j-cols], cur);
		}
	}
	int ans=1<<30;
	for(int j=1; j<=cols; ++j) {
		int tmp=0;
		for(int i=1; i<=rows; ++i)
			tmp+=best[i][j];
		ans=min(ans, tmp);
	}
	printf("%d\n", ans);
}
int main() {
	solve();
	return 0;
}