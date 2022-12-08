#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char s[N];
int o[N][2],e[N][2],sum[N],f[N],g[N];
signed main() {
	int n,m;
	scanf("%d%s%d",&n,s+1,&m);
	for(int i=1;i<=n;i++) {
		o[i][0]=o[i-1][0];
		o[i][1]=o[i-1][1];
		e[i][0]=e[i-1][0];
		e[i][1]=e[i-1][1];
		sum[i]=sum[i-1];
		if(s[i]=='?')sum[i]++;
		else if(i&1)o[i][s[i]=='b']++;
		else e[i][s[i]=='b']++;
		if(i<m)continue;
		if(((i-m)%2==0&&o[i][1]-o[i-m][1]==0&&e[i][0]-e[i-m][0]==0)
		||((i-m)%2==1&&o[i][0]-o[i-m][0]==0&&e[i][1]-e[i-m][1]==0))
			f[i]=f[i-m]+1,g[i]=g[i-m]+sum[i]-sum[i-m];
		if(f[i]<f[i-1])f[i]=f[i-1],g[i]=g[i-1];
		else if(f[i]==f[i-1])g[i]=min(g[i],g[i-1]);
	}
	printf("%d\n",g[n]);
	return 0;
}