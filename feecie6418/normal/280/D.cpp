#include<bits/stdc++.h>
using namespace std;
struct Q {
	int l,r,sum;
}cl[25],u;
Q operator +(Q a,Q b) {
	return {a.l,b.r,a.sum+b.sum};
}
bool operator <(Q a,Q b) {
	return a.sum<b.sum;
}
struct P {
	Q mxl,mxr,mxans,mil,mir,mians,sum;
} t[400005];
P operator +(P a,P b) {
	P ret;
	ret.mxl=max(a.mxl,a.sum+b.mxl),ret.mxr=max(b.mxr,a.mxr+b.sum),ret.sum=a.sum+b.sum;
	ret.mil=min(a.mil,a.sum+b.mil),ret.mir=min(b.mir,a.mir+b.sum);
	ret.mxans=max(max(a.mxans,b.mxans),a.mxr+b.mxl),ret.mians=min(min(a.mians,b.mians),a.mir+b.mil);
	return ret;
}
int n,m,a[100005],tag[400005],cc;
void Build(int p,int l,int r) {
	if(l==r) {
		u={l,l,a[l]},t[p]={u,u,u,u,u,u,u};
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void Tag(int p){
	tag[p]^=1,swap(t[p].mxans,t[p].mians),swap(t[p].mxl,t[p].mil),swap(t[p].mxr,t[p].mir);
	t[p].mxans.sum*=-1,t[p].mxl.sum*=-1,t[p].mxr.sum*=-1,t[p].sum.sum*=-1;
	t[p].mians.sum*=-1,t[p].mil.sum*=-1,t[p].mir.sum*=-1;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2),Tag(p*2+1),tag[p]=0;
}
P Query(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(y<=mid)return Query(p*2,l,mid,x,y);
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	return Query(p*2,l,mid,x,y)+Query(p*2+1,mid+1,r,x,y);
}
void Update(int p,int l,int r,int x){
	if(l==r) {
		u={l,l,a[l]},t[p]={u,u,u,u,u,u,u};
		return ;
	}
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Update(p*2,l,mid,x);
	else Update(p*2+1,mid+1,r,x);
	t[p]=t[p*2]+t[p*2+1];
}
void Rev(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return Tag(p),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Rev(p*2,l,mid,x,y);
	if(y>mid)Rev(p*2+1,mid+1,r,x,y);
	t[p]=t[p*2]+t[p*2+1];
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	Build(1,1,n),cin>>m;
	for(int i=1,opt,x,y,k,ans; i<=m; i++) {
		scanf("%d%d%d",&opt,&x,&y);
		if(!opt)a[x]=y,Update(1,1,n,x);
		else {
			cc=ans=0,scanf("%d",&k);
			for(int j=1;j<=k;j++){
				P p=Query(1,1,n,x,y);
				if(p.mxans.sum<=0)break;
				ans+=p.mxans.sum,Rev(1,1,n,p.mxans.l,p.mxans.r),cl[++cc]={p.mxans.l,p.mxans.r,0};
			}
			printf("%d\n",ans);
			while(cc)Rev(1,1,n,cl[cc].l,cl[cc].r),cc--;
		}
	}
}