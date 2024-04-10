#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 310;

int f[MAXN*2][MAXN][MAXN];
int a[MAXN][MAXN];
int n;

void update(int &x, int y) {
	if(y>x) x=y;
}

int v(int x1, int y1, int x2, int y2) {
	if(x1==x2 && y1==y2) return a[x1][y1];
	return a[x1][y1]+a[x2][y2];
}

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) scanf("%d", &a[i][j]);
	memset(f, 200, sizeof(f));
	f[0][0][0]=a[0][0];
	for(int steps=0; steps<(n-1)*2; ++steps)
		for(int x1=0; x1<n; ++x1)
			for(int x2=0; x2<n; ++x2) {
				int curval=f[steps][x1][x2];
				int y1=steps-x1; if(y1<0 || y1>=n) continue;
				int y2=steps-x2; if(y2<0 || y2>=n) continue;
				if(x1+1<n && x2+1<n) update(f[steps+1][x1+1][x2+1], curval+v(x1+1, y1, x2+1, y2));
				if(x1+1<n && y2+1<n) update(f[steps+1][x1+1][x2], curval+v(x1+1, y1, x2, y2+1));
				if(y1+1<n && x2+1<n) update(f[steps+1][x1][x2+1], curval+v(x1, y1+1, x2+1, y2));
				if(y1+1<n && y2+1<n) update(f[steps+1][x1][x2], curval+v(x1, y1+1, x2, y2+1));
			}
	printf("%d\n", f[(n-1)*2][n-1][n-1]);
	return 0;
}