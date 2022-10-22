#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n;ll a[N],d,m;
int main() {
	for(scanf("%d",&T);T--;){
		scanf("%d%lld",&n,&m),d=0;
		for(int i=1;i<=n;i++)scanf("%lld",a+i);
		for(int i=2;i<=n;i++)d=__gcd(d,a[i]-a[i-1]);
		puts((m-a[1])%d==0?"YES":"NO");
	}
	return 0;
}