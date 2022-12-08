#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN=100010;
const int MAXQ=MAXN*2;

int qp[MAXQ], qx[MAXQ], qt[MAXQ];
int ss, tt;
char wall[2][MAXN];
bool visit[2][MAXN];
int n, k;

bool update(int p, int x, int t) {
	//printf("up\n");
	if(x<0 || x<t) return false;
	if(x>=n) return true;
	if(visit[p][x] || wall[p][x]=='X') return false;
	visit[p][x]=true;
	++tt; qp[tt]=p, qx[tt]=x; qt[tt]=t;
	//printf("tt=%d add %d %d %d\n",tt,p,x,t);
	//printf("++\n");
	return false;
}

bool compute() {
	ss=0, tt=0;
	memset(visit, false, sizeof(visit));
	update(0, 0, 0);
	//qp[tt]=0, qx[tt]=0, qt[tt]=0;
	while(ss<tt) {
		++ss;
		int p=qp[ss], x=qx[ss], t=qt[ss];
		//printf("ss=%d p=%d x=%d t=%d\n", ss,p, x, t);
		if(update(p, x-1, t+1)) return true;
		if(update(p, x+1, t+1)) return true;
		if(update(1-p, x+k, t+1)) return true;
	}
	return false;
}

int main() {
	scanf("%d%d%s%s", &n, &k, wall[0], wall[1]);
	printf("%s\n", compute()?"YES":"NO");
	return 0;
}