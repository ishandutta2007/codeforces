#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int head[1200002],sz[100002],stkx[100002],stky[100002],fa[100002],n,m,cnt,a[300002],b[300002],c[300002],O,D[100002],tp,rk[300002],ans[300002];
struct node{
	int z,id;
	bool operator <(const node a)const{return z<a.z;}
}p[300002];
inline int root(re int x){while(x^fa[x])x=fa[x];return x;}
inline void merge(re int x,re int y){
	x=root(x),y=root(y);
	if(x==y)return;
	if(sz[x]>sz[y])x^=y^=x^=y;
	stkx[++tp]=x,stky[tp]=y,D[tp]=0;
	if((sz[x]&1)&&(sz[y]&1))O-=2,D[tp]=2;
	fa[x]=y,sz[y]+=sz[x];
}
inline void undo(re int o){while(tp^o)O+=D[tp],fa[stkx[tp]]=stkx[tp],sz[stky[tp]]-=sz[stkx[tp]],--tp;}
inline void solve(re int l,re int r,re int x,re int y){
	if(l>r)return;
	re int mid=l+r>>1,o=tp;
	for(re int i=l;i<=mid;++i)if(rk[i]<x)merge(a[i],b[i]);
	re int ss=tp;
	for(re int i=x;i<=y;++i){
		if(p[i].id<=mid)merge(a[p[i].id],b[p[i].id]);
		if(!O){
			ans[mid]=i;
			break;
		}
	}
	undo(ss);
	if(!ans[mid]){
		solve(mid+1,r,x,y);
		return undo(o);
	}
	solve(mid+1,r,x,ans[mid]);
	undo(o);
	for(re int i=x;i<ans[mid];++i)if(p[i].id<l)merge(a[p[i].id],b[p[i].id]);
	solve(l,mid-1,ans[mid],y);
	undo(o);
}
int main(){
	O=n=read(),m=read(),p[0].z=-1;
	for(re int i=1;i<=m;++i)a[i]=read(),b[i]=read(),p[i]=(node){c[i]=read(),i};
	sort(p+1,p+m+1);
	for(re int i=1;i<=m;++i)rk[p[i].id]=i;
	for(re int i=1;i<=n;++i)sz[fa[i]=i]=1;
	solve(1,m,1,m);
	for(re int i=1;i<=m;++i)printf("%d\n",p[ans[i]].z);
}