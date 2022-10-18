#include <bits/stdc++.h>

int n,x[10],y[10];
int atcorner(int x,int y) {
	return ( (x == 1) || (x == n) ) && ( (y == 1) || (y == n) );
}

void solve() {
	scanf("%d",&n);
	int sx = 0, sy = 0, xx = 0, yy = 0;
	for (int i = 1; i <= 3; ++ i) {
		scanf("%d%d",&x[i],&y[i]);
		sx += x[i]; xx ^= x[i];
		sy += y[i]; yy ^= y[i];
	} int cx = (sx - xx) / 2;
	int cy = (sy - yy) / 2;
	int tx,ty;
	scanf("%d%d",&tx,&ty);
	for (int i = 1; i <= 3; ++ i) {
		if ( (x[i] == tx && y[i] == ty) ) { puts("YES"); return ; }
	}
	if (atcorner(cx,cy)  ) { 
	
		if ( (tx == cx ) || (ty  == cy ) ) puts("YES");
		else puts("NO");
	} else {
		if ( (tx % 2 == cx % 2) || (ty % 2 == cy % 2) ) puts("YES");
		else puts("NO");
	}
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}