#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=20010;

int vx[MAXN], vy[MAXN];
int n, m, modnum;

bool ansup[MAXN*2]; int anslen;

int f(int a, int b) {
	return (vx[a]+vy[b])%modnum;
}

LL f1[MAXN], f2[MAXN], f0[MAXN];

void cal(int x1, int y1, int x2, int y2) {
	if(x1==x2) {
		while(y1<y2) {
			ansup[++anslen]=true;
			++y1;
		}
		return;
	}
	int mx=(x1+x2)/2;
	f1[y1]=f(x1, y1);
	for(int y=y1+1; y<=y2; ++y) f1[y]=f1[y-1]+f(x1, y);
	for(int x=x1+1; x<=mx; ++x) {
		memmove(f0, f1, sizeof(f1));
		f1[y1]=f0[y1]+f(x, y1);
		for(int y=y1+1; y<=y2; ++y) f1[y]=max(f1[y-1], f0[y])+f(x, y);
	}
	f2[y2]=f(x2, y2);
	for(int y=y2-1; y>=y1; --y) f2[y]=f2[y+1]+f(x2, y);
	for(int x=x2-1; x>=mx+1; --x) {
		memmove(f0, f2, sizeof(f2));
		f2[y2]=f0[y2]+f(x, y2);
		for(int y=y2-1; y>=y1; --y) f2[y]=max(f2[y+1], f0[y])+f(x, y);
	}
	int by=y1; LL ans=0;
	for(int y=y1; y<=y2; ++y) {
		LL tmp=f1[y]+f2[y];
		if(tmp>ans) ans=tmp, by=y;
	}
//printf("%d %d  %d %d   mx=%d by=%d\n",x1,y1,x2,y2, mx,by);
	cal(x1, y1, mx, by);
	ansup[++anslen]=false;
	cal(mx+1, by, x2, y2);
}

int main() {
	scanf("%d%d%d", &n,&m,&modnum);
	for(int i=1; i<=n; ++i) scanf("%d", vx+i);
	for(int i=1; i<=m; ++i) scanf("%d", vy+i);
	anslen=0;
	cal(1, 1, n, m);
	LL ans=f(1, 1);
	for(int i=1, a=1, b=1; i<=anslen; ++i) {
		if(ansup[i]) ++b; else ++a;
		ans+=f(a, b);
	}
	cout<<ans<<endl;
	for(int i=1; i<=anslen; ++i) printf("%c", ansup[i]?'S':'C');
	printf("\n");
	return 0;
}