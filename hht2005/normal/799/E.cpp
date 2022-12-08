#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long lll;
#define lb(x) (lower_bound(c+1,c+M+1,x)-c)
int v[N],f[N][2],c[N],siz[N<<2];
lll val[N<<2];
vector<int>a[2][2];
vector<lll>sum[2][2];
void add(int p,int l,int r,int x,int v) {
	val[p]+=c[x]*v;
	siz[p]+=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,v);
	else add(p<<1|1,mid+1,r,x,v);
}
lll qry(int p,int l,int r,int x) {
	if(l==r)return 1ll*c[l]*x;
	int mid=(l+r)>>1;
	if(x<=siz[p<<1])return qry(p<<1,l,mid,x);
	else return val[p<<1]+qry(p<<1|1,mid+1,r,x-siz[p<<1]);
}
int main() {
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i),c[i]=v[i];
	sort(c+1,c+n+1);
	int M=unique(c+1,c+n+1)-c-1;
	for(int i=0;i<2;i++) {
		int q,x;
		scanf("%d",&q);
		while(q--) {
			scanf("%d",&x);
			f[x][i]=1;
		}
	}
	for(int i=1;i<=n;i++)
		a[f[i][0]][f[i][1]].push_back(v[i]);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++) {
			sort(a[i][j].begin(),a[i][j].end());
			lll las=0;
			for(int k:a[i][j]) {
				las+=k;
				sum[i][j].push_back(las);
			}
		}
	for(int i=k;i<(int)(a[0][1].size());i++)add(1,1,M,lb(a[0][1][i]),1);
	for(int i=k;i<(int)(a[1][0].size());i++)add(1,1,M,lb(a[1][0][i]),1);
	for(int i:a[0][0])add(1,1,M,lb(i),1);
	for(int i:a[1][1])add(1,1,M,lb(i),1);
	lll ans=1e18;
	for(int i=0;i<=(int)(a[1][1].size())&&i<=k;i++) {
		int S=k-i,FL=0;
		if(S<=(int)(a[0][1].size()))FL++;
		if(S<=(int)(a[1][0].size()))FL++;
		if(FL==2&&i+S+S<=m) {
			lll t=i?sum[1][1][i-1]:0;
			t+=S?sum[0][1][S-1]:0;
			t+=S?sum[1][0][S-1]:0;
			ans=min(ans,t+qry(1,1,M,m-i-S-S));
		}
		if(i<(int)(a[1][1].size()))add(1,1,M,lb(a[1][1][i]),-1);
		if(S&&S<=(int)(a[0][1].size()))add(1,1,M,lb(a[0][1][S-1]),1);
		if(S&&S<=(int)(a[1][0].size()))add(1,1,M,lb(a[1][0][S-1]),1);
	}
	if(ans<1e17)printf("%lld\n",ans);
	else puts("-1");
	return 0;
}