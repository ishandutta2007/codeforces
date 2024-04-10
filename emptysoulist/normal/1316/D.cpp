#include<bits/stdc++.h>
using namespace std ;
int fx[5] = {0, 0, 1, -1};
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
#define N 1005
int fy[5] = {1, -1, 0, 0};
char a[5] = {'L', 'R', 'U', 'D'};
int n, X[N][N], Y[N][N], co, pax, px, py;
char ans[N][N];
void dfs(int x, int y) {
	rep(i, 0, 3) {
		if(ans[(x + fx[i])][(y + fy[i])] || Y[(x + fx[i])][(y + fy[i])] != py || (y + fy[i]) > n || (x + fx[i]) < 1 || (y + fy[i]) < 1 || (x + fx[i]) > n || X[(x + fx[i])][(y + fy[i])] != px) continue;
		ans[(x + fx[i])][(y + fy[i])] = a[i], dfs((x + fx[i]), (y + fy[i]));
	}
	++ pax;
}
void check() {
	rep(i, 1, n) rep(j, 1, n) {
		if(ans[i][j] != 'X') continue;
		if(X[i][j] != i || Y[i][j] != j) return puts("INVALID"), void();
		px = i, py = j, dfs(i, j);
	}
	rep(i, 1, n) rep(j, 1, n) {
		if(!ans[i][j] && Y[i][j] != -1 && X[i][j] != -1) return puts("INVALID"), void();
		else if(!ans[i][j]) {
			px = py = -1, pax = 0, dfs(i, j);
			if(pax == 1) return puts("INVALID"), void();
		}
	}
	printf("VALID\n");
	rep(i, 1, n) {
		rep(j, 1, n) printf("%c", ans[i][j]);
		cout << endl;
	}
}
signed main() {
	n = gi();
	rep(i, 1, n) rep(j, 1, n) {
		X[i][j] = gi(), Y[i][j] = gi();
		if(X[i][j] != -1) ans[X[i][j]][Y[i][j]] = 'X';
	}
	check();
	return 0;
}