#include <bits/stdc++.h>
#define N 155
using namespace std;
char mp[N][N],s[N],ans[N][N];
int n,flag,tot;
inline int rd() {int r;scanf("%d",&r);return r;}
int g(int x,int y) {
	int ret = 0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (mp[i][j] == 1) {
			if (i+x>=1 && i+x<=n && j+y>=1 && j+y<=n && !mp[i+x][j+y]) return 0;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (mp[i][j] == 1) {
			if (i+x>=1 && i+x<=n && j+y>=1 && j+y<=n && mp[i+x][j+y]==2) 
				tot--, mp[i+x][j+y] = -1;
	}
	return 1;
}

int main() {
	n = rd();
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=n;j++) {
			if (s[j] == 'o') mp[i][j] = 1;
			if (s[j] == 'x') mp[i][j] = 2, tot++;
		}
	}

	for (int i=-n+1;i<=n-1;i++)
		for (int j=-n+1;j<=n-1;j++) if (i || j) {
			if (g(i,j))
				ans[i+n][j+n] = 'x';
			else
				ans[i+n][j+n] = '.';
		} else ans[i+n][j+n] = 'o';
	
	puts(!tot?"YES":"NO");
	if (tot) return 0;
	for (int i=1;i<=2*n-1;i++) {
		for (int j=1;j<=2*n-1;j++) putchar(ans[i][j]);
		puts("");
	}
	return 0;
}