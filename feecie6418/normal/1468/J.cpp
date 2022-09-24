#include<bits/stdc++.h>
using namespace std;
struct Edge2 {
	int from,to,value,ont;
	bool operator <(const Edge2 yy) const {
		return value<yy.value;
	}
} e[300005];
int n,m,k,fa[200005];
int gf(int x) {
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=m; i++)scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].value);
		sort(e+1,e+m+1);
		for(int i=1; i<=n; i++)fa[i]=i;
		long long ans=0,flag=0;
		for(int i=1; i<=m; i++) {
			int fx=gf(e[i].from),fy=gf(e[i].to);
			if(fx==fy)continue;
			fa[fx]=fy;
			if(e[i].value>=k)flag=1,ans+=e[i].value-k;
		}
		if(flag)printf("%lld\n",ans);
		else {
			ans=1e18;
			for(int i=1; i<=m; i++) {
				if(e[i].value>=k)ans=min(ans,0ll+e[i].value-k);
				else ans=min(ans,0ll+k-e[i].value);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}