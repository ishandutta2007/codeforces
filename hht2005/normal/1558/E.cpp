#include<bits/stdc++.h>
using namespace std;
const int N=1010;
vector<int>S[N];
int a[N],b[N],c[N],q[N],pre[N],n;
long long p[N];
int check(int init) {
	memset(c,0,sizeof(c));
	c[1]=1;
	long long pow=init;
	while(1) {
		memset(pre,0,sizeof(pre));
		int h=1,e=0;
		for(int i=1;i<=n;i++)
			if(c[i])q[++e]=-i,p[e]=pow;
		int s=0,t=0;
		while(h<=e) {
			int f=q[h]>0;
			int x=abs(q[h]);
			long long v=p[h++];
			for(int y:S[x]) {
				if(pre[x]==y||v<=a[y])continue;
				if(pre[y]||(c[y]&&f)) {
					s=x,t=y;
					break;
				}
				if(c[y])continue;
				pre[y]=x;
				q[++e]=y,p[e]=v+b[y];
			}
			if(s)break;
		}
		if(!s)break;
		while(!c[s])c[s]=1,pow+=b[s],s=pre[s];
		while(!c[t])c[t]=1,pow+=b[t],t=pre[t];
	}
	for(int i=1;i<=n;i++)
		if(!c[i])return 0;
	return 1;
}
signed main() {
	int T,x,y,m;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)S[i].clear();
		for(int i=2;i<=n;i++)scanf("%d",a+i);
		for(int i=2;i<=n;i++)scanf("%d",b+i);
		for(int i=1;i<=m;i++) {
			scanf("%d%d",&x,&y);
			S[x].push_back(y);
			S[y].push_back(x);
		}
		int l=2,r=1e9;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",r+1);
	}
	return 0;
}