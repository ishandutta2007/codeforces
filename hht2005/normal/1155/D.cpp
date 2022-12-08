#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=3e5+10;
int f[3];
signed main() {
	int n,k,ans=0,t;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&t);
		f[0]=t+f[0];if(f[0]<0)f[0]=0;
		f[1]=max(f[0],f[1]+t*k);
		f[2]=max(f[2]+t,f[1]);
		ans=max(ans,f[2]);
	}
	printf("%lld\n",ans);
	return 0;
}