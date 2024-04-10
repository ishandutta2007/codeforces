#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#define N 10050

using namespace std;

inline void ut(int &x,int y) { x = max(x,y); }
int A[5],B[5];
int a[N],p[N],g[10],cnt,u,v;

bool beautiful(int x) {
	memset(g,0,sizeof(g));
	for (int _=1;_<=4;_++) {
		if (g[x%10]) return 0;
		g[x%10] = 1;
		x /= 10;
	}
	return 1;
}

int q(int x) {
	int tot = 0 , ans = 0;
	for (int _=1;_<=4;_++) A[_] = x % 10 , x /= 10;
	memset(g,0,sizeof(g));
	for (int _=1;_<=4;_++) g[ A[_] ]++;
	
	
	int ret[5][5]; memset(ret,0,sizeof(ret));
	
	for (int i=1;i<=cnt;i++) if (p[i]){
		int t = a[i]; tot++;
		for (int _=1;_<=4;_++) B[_] = t % 10 , t /= 10; 
		
		int u = 0 ,v = 0;
		for (int _=1;_<=4;_++) u += A[_] == B[_] , v += g[ B[_] ];
		v -= u;
		ret[u][v]++;
	}
	
	for (int i=0;i<=4;i++) for (int j=0;i+j<=4;j++) ut(ans , ret[i][j]);
	return tot - ans;
}

bool solve() {
	
//	for (int i=1;i<=10;i++) if (p[i]) printf("%d\n",a[i]);
	int cur = -1 , ans = 0;
	for (int i=1;i<=cnt;i++) if (p[i]) {
		int tmp = q(a[i]);
		if (tmp > cur) cur = tmp , ans = a[i];
	}
	assert(ans);
	if (ans < 1000) printf("0");
	printf("%d\n",ans); fflush(stdout);
	scanf("%d%d",&u,&v);
	if (u==4) return 0;
	for (int _=1;_<=4;_++) A[_] = ans % 10 , ans /= 10;
	
	memset(g,0,sizeof(g));
	for (int _=1;_<=4;_++) g[ A[_] ]++;
	
	for (int i=1;i<=cnt;i++) 
		if (p[i]) {
		int uu = 0 , vv = 0 , x = a[i]; 
		for (int _=1;_<=4;_++) B[_] = x % 10 , x /= 10;
		
		for (int _=1;_<=4;_++) uu += (A[_] == B[_]) , vv += g[ B[_] ];
		vv -= uu;
		p[i] = ( u == uu && v == vv );
	}
	return 1;
}

int main() {
	for (int i=123;i<=9876;i++) if (beautiful(i)) a[++cnt] = i , p[cnt] = 1;
	while (solve());
	return 0;
}