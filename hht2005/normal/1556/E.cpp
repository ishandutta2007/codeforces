#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int Log[N],a[N],b[N],c[N],Min[20][N],Max[20][N];
int get_min(int l,int r) {
	int L=Log[r-l+1];
	return min(Min[L][l],Min[L][r-(1<<L)+1]);
}
int get_max(int l,int r) {
	int L=Log[r-l+1];
	return max(Max[L][l],Max[L][r-(1<<L)+1]);
}
signed main() {
	int n,q,l,r;
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)scanf("%lld",b+i);
	Log[1]=0;
	for(int i=2;i<=n;i++)
		Log[i]=Log[i>>1]+1;
	for(int i=1;i<=n;i++) {
		c[i]=b[i]-a[i]+c[i-1];
		Max[0][i]=Min[0][i]=c[i];
	}
	for(int i=1;i<20;i++)
		for(int j=1;j+(1<<i)-1<=n;j++) {
			Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<(i-1))]);
			Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<(i-1))]);
		}
	while(q--) {
		scanf("%lld%lld",&l,&r);
		if(c[r]!=c[l-1]||get_min(l,r)<c[l-1])puts("-1");
		else printf("%lld\n",get_max(l,r)-c[l-1]);
	}
	return 0;
}