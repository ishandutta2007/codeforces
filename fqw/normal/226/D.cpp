#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=110;

int a[MAXN][MAXN];
int sx[MAXN], sy[MAXN];
int n, m;

bool rx[MAXN], ry[MAXN];
int lst[MAXN*2], ln;
int main() {
	scanf("%d%d", &n, &m);
	memset(sx, 0, sizeof(sx));
	memset(sy, 0, sizeof(sy));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d", &a[i][j]), sx[i]+=a[i][j], sy[j]+=a[i][j];
	memset(rx, false, sizeof(rx));
	memset(ry, false, sizeof(ry));
	srand(12354354);
	while(1) {
		ln=0;
		for(int i=1; i<=n; ++i) if(sx[i]<0) lst[++ln]=i;
		for(int j=1; j<=m; ++j) if(sy[j]<0) lst[++ln]=-j;
		if(ln==0) break;
		int k=lst[rand()%ln+1];
		if(k>0) {
			int i=k;
			rx[i]=!rx[i];
			sx[i]=-sx[i];
			for(int j=1; j<=m; ++j)
				a[i][j]=-a[i][j], sy[j]+=2*a[i][j];
		} else {
			int j=-k;
			ry[j]=!ry[j];
			sy[j]=-sy[j];
			for(int i=1; i<=n; ++i)
				a[i][j]=-a[i][j], sx[i]+=2*a[i][j];
		}
	}
	ln=0;
	for(int i=1; i<=n; ++i) if(rx[i]) lst[++ln]=i;
	printf("%d", ln); for(int i=1; i<=ln; ++i) printf(" %d", lst[i]); printf("\n");
	ln=0;
	for(int j=1; j<=m; ++j) if(ry[j]) lst[++ln]=j;
	printf("%d", ln); for(int i=1; i<=ln; ++i) printf(" %d", lst[i]); printf("\n");
	return 0;
}