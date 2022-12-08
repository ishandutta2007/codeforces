#include<bits/stdc++.h>
using namespace std;
#define int long long
int x[4],y[4],p[4];
signed main() {
	int T;
	scanf("%lld",&T);
	while(T--) {
		for(int i=0;i<4;i++) {
			scanf("%lld%lld",x+i,y+i);
			p[i]=i;
		}
		int ans=1e11;
		do {
			int lx1=min(x[p[0]],x[p[1]]),rx1=max(x[p[0]],x[p[1]]);
			int lx2=min(x[p[2]],x[p[3]]),rx2=max(x[p[2]],x[p[3]]);
			int ly1=min(y[p[0]],y[p[2]]),ry1=max(y[p[0]],y[p[2]]);
			int ly2=min(y[p[1]],y[p[3]]),ry2=max(y[p[1]],y[p[3]]);
			int dxl=max({lx1-rx2,lx2-rx1,0ll}),dxr=max({rx2-lx1,rx1-lx2,0ll});
			int dyl=max({ly1-ry2,ly2-ry1,0ll}),dyr=max({ry2-ly1,ry1-ly2,0ll});
			ans=min(ans,rx1-lx1+rx2-lx2+ry1-ly1+ry2-ly2+2*max(0ll,max(dxl,dyl)-min(dxr,dyr)));
		}while(next_permutation(p,p+4));
		printf("%lld\n",ans);
	}
	return 0;
}