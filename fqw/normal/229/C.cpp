#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=1000010;

LL c[MAXN];
int n;
int main() {
	int e; scanf("%d%d", &n, &e);
	if(n<=2) {
		printf("0\n"); return 0;
	}
	memset(c, 0, sizeof(c));
	for(int i=1; i<=e; ++i) {
		int a, b; scanf("%d%d", &a,&b);
		c[a]++, c[b]++;
	}
	LL ans=0;
	for(int i=1; i<=n; ++i) {
		LL x=c[i], y=n-1-x;
		ans+=x*y;
	}
	ans/=2;
	LL tot=(LL)n*(LL)(n-1)*(LL)(n-2)/6;
	ans=tot-ans;
	cout<<ans<<endl;
	return 0;
}