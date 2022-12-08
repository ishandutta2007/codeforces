#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=1e9;
int sum[N*20],Max[N*20],ls[N*20],rs[N*20],pos[N],ans[N],f[N],rt,tot;
struct node {
	int r,a,id;
	int operator<(const node &a)const {
		return r<a.r;
	}
}p[N];
struct nod {
	int x,y,id;
	int operator<(const nod &a)const {
		return max(p[pos[x]].r,p[pos[y]].r)<max(p[pos[a.x]].r,p[pos[a.y]].r);
	}
}q[N];
void add(int &p,int l,int r,int x,int v) {
	if(!p) {
		p=++tot;
		ls[p]=rs[p]=sum[p]=Max[p]=0;
	}
	sum[p]+=v;
	Max[p]=max(Max[p],v);
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(ls[p],l,mid,x,v);
	else add(rs[p],mid+1,r,x,v);
}
int qry_max(int p,int l,int r,int x,int y) {
	if(!p)return 0;
	if(x<=l&&r<=y)return Max[p];
	int mid=(l+r)>>1,Maxx=0;
	if(x<=mid)Maxx=max(Maxx,qry_max(ls[p],l,mid,x,y));
	if(y>mid)Maxx=max(Maxx,qry_max(rs[p],mid+1,r,x,y));
	return Maxx;
}
int qry_sum(int p,int l,int r,int x,int y) {
	if(!p)return 0;
	if(x<=l&&r<=y)return sum[p];
	int mid=(l+r)>>1,Sum=0;
	if(x<=mid)Sum+=qry_sum(ls[p],l,mid,x,y);
	if(y>mid)Sum+=qry_sum(rs[p],mid+1,r,x,y);
	return Sum;
}
int main() {
	int n,k,m;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&p[i].r);
	for(int i=1;i<=n;i++)scanf("%d",&p[i].a);
	for(int i=1;i<=n;i++)p[i].id=i;
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) {
		int l=i,r=i;
		while(r<n&&p[r].r==p[r+1].r)r++;
		for(int j=l;j<=r;j++)pos[p[j].id]=j,add(rt,1,M,p[j].a,1);
		for(int j=l;j<=r;j++)f[j]=qry_sum(1,1,M,p[j].a-k,p[j].a+k);
		i=r;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&q[i].x,&q[i].y);
		q[i].id=i;
	}
	rt=tot=0;
	sort(q+1,q+m+1);
	int j=m;
	for(int i=n;i>=1;i--) {
		int r=i,l=i;
		while(l>1&&p[l].r==p[l-1].r)l--;
		while(j) {
			int a=pos[q[j].x],b=pos[q[j].y];
			if(max(p[a].r,p[b].r)<=p[l].r)break;
			ans[q[j].id]=qry_max(1,1,M,max(p[a].a,p[b].a)-k,min(p[a].a,p[b].a)+k);
			j--;
		}
		for(int j=l;j<=r;j++)add(rt,1,M,p[j].a,f[j]);
		i=r;
	}
	while(j) {
		int a=pos[q[j].x],b=pos[q[j].y];
		ans[q[j].id]=qry_max(1,1,M,max(p[a].a,p[b].a)-k,min(p[a].a,p[b].a)+k);
		j--;
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]<2?-1:ans[i]);
	return 0;
}