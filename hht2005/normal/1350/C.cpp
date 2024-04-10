#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int a[maxn];
int gcd(int x,int y) {
	if(!x||!y)return x^y;
	while(y^=x^=y^=x%=y);
	return x;
}
signed main() {
	int n,ans=0,g=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	g=a[1];
	for(int i=2;i<=n;i++) {
		int t=a[i]*g/gcd(a[i],g);
		ans=gcd(ans,t);
		g=gcd(g,a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}