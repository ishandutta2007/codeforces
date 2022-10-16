#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


int ax,ay,bx,by,tx,ty;

double dd[110000][3];
double s;
double ans;
int n;

double bst[110000][2];

double getdd(int x, int y, int x2, int y2) {
	double dx = x2-x;
	double dy = y2-y;
	return sqrt(dx*dx+dy*dy);
}

void solve() {
	scanf("%d %d %d %d %d %d", &ax,&ay,&bx,&by,&tx,&ty);	

	scanf("%d", &n);
	REP(i,n) {
		int x, y;
		scanf("%d %d", &x, &y);
		dd[i][0] = getdd(x,y,ax,ay);
		dd[i][1] = getdd(x,y,bx,by);
		dd[i][2] = getdd(x,y,tx,ty);
		s += 2 * dd[i][2];
	}

	ans = 1e100;
	REP(i,n) {
		bst[i+1][0] = min(bst[i-1][0], dd[i][0]-dd[i][2]);
	}
	for (int i = n-1; i >= 0; i--) {
		bst[i][1] = min(bst[i+1][1], dd[i][1]-dd[i][2]);
	}
	for (int i = 0; i <= n; i++) {
		if (bst[i][0] < 0 || bst[i][1] < 0) ans = min(s + bst[i][0] + bst[i][1], ans);
	}

	REP(i,n) {
		bst[i+1][0] = min(bst[i-1][0], dd[i][1]-dd[i][2]);
	}
	for (int i = n-1; i >= 0; i--) {
		bst[i][1] = min(bst[i+1][1], dd[i][0]-dd[i][2]);
	}
	for (int i = 0; i <= n; i++) {
		if (bst[i][0] < 0 || bst[i][1] < 0) ans = min(s + bst[i][0] + bst[i][1], ans);
	}

	for (int i = 0; i < n; i++) {
		ans = min(ans, s + dd[i][0]-dd[i][2]);
		ans = min(ans, s + dd[i][1]-dd[i][2]);
	}

	printf("%.15f\n", ans);

}

int main() {
    solve();
}