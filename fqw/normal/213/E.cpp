#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const unsigned QQ=9119113;
const int MAXN=200010;

unsigned mq[MAXN];
unsigned tr[MAXN*4];
int size[MAXN*4];

void modify(int x, int s, int t, int ind, unsigned key, int deg) {
	if(s==t) {
		tr[x]=key;
		size[x]=deg;
		return;
	}
	int m=(s+t)/2;
	if(ind<=m) modify(x*2, s, m, ind, key, deg);
	else modify(x*2+1, m+1, t, ind, key, deg);
	size[x]=size[x*2]+size[x*2+1];
	tr[x]=tr[x*2]*mq[size[x*2+1]]+tr[x*2+1];
}

int posi[MAXN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	unsigned ha=0, add=0;
	for(int i=1, x; i<=n; ++i)
		scanf("%d", &x), ha=ha*QQ+x, add=add*QQ+1;
	for(int i=1, x; i<=m; ++i)
		scanf("%d", &x), posi[x]=i;
	mq[0]=1; for(int i=1; i<=m; ++i) mq[i]=mq[i-1]*QQ;
	int ans=0;
	memset(tr, 0, sizeof(tr));
	memset(size, 0, sizeof(size));
	for(int i=1; i<=n; ++i)
		modify(1, 1, m, posi[i], i, 1);
	//printf("tr=%u ha=%u\n", tr[1], ha);
	if(tr[1]==ha) ++ans;
	for(int i=n+1; i<=m; ++i) {
		modify(1, 1, m, posi[i], i, 1);
		modify(1, 1, m, posi[i-n], 0, 0);
		//printf("i=%d tr=%u ha=%u\n", i, tr[1], (ha+add*(i-n)));
		if(tr[1]==(ha+add*(i-n))) ++ans;
	}
	printf("%d\n", ans);
	return 0;
}