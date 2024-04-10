#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;
#define N 10050
#define ls p<<1
#define rs p<<1|1
#define bs bitset<N>
int n,m,can[N],ans[N];
vector<int>vt[N<<2];
void update(int l,int r,int x,int y,int v,int p) {
	if(x<=l&&y>=r) {
		vt[p].push_back(v); return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid) update(l,mid,x,y,v,ls);
	if(y>mid) update(mid+1,r,x,y,v,rs);
}
void dfs(int l,int r,int p,bs b) {
	int lim=vt[p].size(),i;
	for(i=0;i<lim;i++) b|=(b<<vt[p][i]);
	if(l==r) {
		for(i=1;i<=n;i++) if(b[i]) can[i]=1;
		return ;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,ls,b);
	dfs(mid+1,r,rs,b);
}
int main() {
	scanf("%d%d",&n,&m);
	int i,l,r,x;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&x);
		update(1,n,l,r,x,1);
	}
	bs s; s[0]=1;
	dfs(1,n,1,s);
	for(i=1;i<=n;i++) if(can[i]) ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for(i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	puts("");
}