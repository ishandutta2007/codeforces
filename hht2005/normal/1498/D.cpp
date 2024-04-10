#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int f[maxn],g[maxn];
signed main() {
	int n,m,op,x,y;
	memset(f,-1,sizeof(f));
	f[0]=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1)x=(x-1)/100000+1;
		for(int j=0;j<=m;j++) {
			if(f[j]==-1)continue;
			if(f[j]==i&&g[j]>=y)continue;
			long long nxt;
			if(op==1)nxt=j+x;
			else nxt=ceil(1.0*j*x/100000);
			if(nxt<=m&&f[nxt]==-1) {
				f[nxt]=i;
				if(f[j]==i)g[nxt]=g[j]+1;
				else g[nxt]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",f[i]);
	return 0;
}