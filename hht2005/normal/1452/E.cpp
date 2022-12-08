#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int sum[maxn<<2],f[maxn<<2],l[maxn],r[maxn];
vector<int>p[maxn];
void tag(int p,int v,int l) {
	sum[p]+=v*l;
	f[p]+=v;
}
void pushdown(int p,int l) {
	if(f[p]) {
		tag(p<<1,f[p],l/2+l%2);
		tag(p<<1|1,f[p],l/2);
		f[p]=0;
	}
}
void add(int p,int l,int r,int x,int y,int v) {
	if(x<=l&&r<=y)return tag(p,v,r-l+1);
	pushdown(p,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
	sum[p]=sum[p<<1]+sum[p<<1|1];
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return sum[p];
	pushdown(p,r-l+1);
	int mid=(l+r)>>1,sum=0;
	if(x<=mid)sum+=qry(p<<1,l,mid,x,y);
	if(y>mid)sum+=qry(p<<1|1,mid+1,r,x,y);
	return sum;
}
int main() {
	int n,m,k,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",l+i,r+i);
	for(int i=1;i<=n-k+1;i++) {
		memset(sum,0,sizeof(sum));
		memset(f,0,sizeof(f));
		for(int j=1;j<=n;j++)p[j].clear();
		int sum=0;
		for(int j=1;j<=m;j++)
			if(r[j]<=i+k-1)sum+=max(0,min(i+k-1,r[j])-max(i,l[j])+1);
			else if(l[j]<=i&&i+k<=r[j])sum+=k;
			else if(l[j]>=i+k)add(1,1,n,l[j],r[j],1);
			else {
				add(1,1,n,l[j],r[j],1);
				p[r[j]-(i+k-l[j])+1].push_back(j);
			}
		for(int j=i;j<=n-k+1;j++) {
			for(int a:p[j]) {
				add(1,1,n,l[a],r[a],-1);
				sum+=i+k-l[a];
			}
			ans=max(ans,sum+qry(1,1,n,j,j+k-1));
		}
	}
	printf("%d\n",ans);
	return 0;
}