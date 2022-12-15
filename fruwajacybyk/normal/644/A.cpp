#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i < (b); i++) 

using namespace std;

int ans[105][105];

int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int os = (a*b+1)/2;
	int es = (a*b)/2;
	int o = (n+1)/2;
	int e = n/2;
	if (os < o || es < e) {
		printf("-1\n");
	} else {
		FOR(i,0,a) FOR(j,0,b) ans[i][j] = 0;
		int no = 1, ne = 2;
		FOR(i,0,a) FOR(j,0,b) {
			if ( (i+j)%2==1 && ne <= n) {
				ans[i][j] = ne; ne+=2;
			}
			if ( (i+j)%2==0 && no <= n) {
				ans[i][j] = no; no+=2;
			}
		}		
		FOR(i,0,a) {
			FOR(j,0,b) printf("%d ", ans[i][j]);
			printf("\n");
		}
	}
}