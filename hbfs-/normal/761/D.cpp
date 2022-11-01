#include <iostream>
#include <cstdio>
#define INF (1<<30)

#define N 1000050

using namespace std;
int n,l,r;
int a[N],b[N],c[N],d[N];
int main() {
	scanf("%d%d%d",&n,&l,&r);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]) , d[ c[i] ] = i;
	int cur = INF;
	for (int i=1;i<=n;i++) {
		b[ d[i] ] = max(a[ d[i] ]-cur+1,l);
		if (b[ d[i] ] > r) { puts("-1"); return 0; }
		cur = a[ d[i] ] - b[ d[i] ];
	}
	for (int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	return 0;
}