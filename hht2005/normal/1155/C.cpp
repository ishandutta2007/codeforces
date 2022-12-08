#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
long long x[maxn],y[maxn];
inline int gcd(int x,int y) {
	if(!x||!y)return x^y;
	while(y^=x^=y^=x=x%y);
	return x;
}
signed main() {
	int n,m,g=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",x+i);
	for(int i=1;i<=m;i++)scanf("%lld",y+i);
	for(int i=2;i<=n;i++)g=gcd(g,x[i]-x[i-1]);
	for(int i=1;i<=m;i++)
		if(g%y[i]==0) {
			printf("YES\n%lld %lld\n",x[1],i);
			return 0;
		}
	puts("NO");
	return 0;
}