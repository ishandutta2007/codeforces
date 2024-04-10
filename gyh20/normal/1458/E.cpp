#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,ans[100002],rt,ls[2000002],rs[2000002],sz[2000002],tot,od,pos,inf=1e9,ia;
inline void ins(re int&p,re int l,re int r,re int x){
	if(!p)p=++tot;
	if(l==r){sz[p]=1;return;}
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);sz[p]=sz[ls[p]]+sz[rs[p]];
}
inline int ask(re int p,re int l,re int r,re int x){
	if(r<=x)return sz[p];
	re int mid=l+r>>1,s=ask(ls[p],l,mid,x);
	if(x>mid)s+=ask(rs[p],mid+1,r,x);
	return s;
}
map<pair<int,int>,int>V;
map<int,int>Mn;
struct node{
	int x,y,id;
	bool operator <(const node A)const{return x==A.x?id<A.id:x<A.x;}
}p[200002];
inline int find(re int x,re int y){
	re int l=x,r=inf,pp=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(mid-x-(ask(rt,0,inf,mid)-ask(rt,0,inf,x))>=y)pp=mid,r=mid-1;
		else l=mid+1;
	}
	return pp;
}
inline void Mov(re int x){
	if(x^od)ia=1;
	pos=find(pos,x-od),od=x;
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i)p[i].x=read(),p[i].y=read(),V[make_pair(p[i].x,p[i].y)]=1;
	for(re int i=1;i<=m;++i)p[i+n].x=read(),p[i+n].y=read(),p[i+n].id=i;
	sort(p+1,p+n+m+1);
	for(re int i=1;i<=n+m;++i){
		Mov(p[i].x);
		if(!p[i].id){
			if(p[i].y<pos&&ia)--pos,ia=0;
			if(!Mn.count(p[i].x))Mn[p[i].x]=p[i].y;
			else Mn[p[i].x]=min(Mn[p[i].x],p[i].y);
			ins(rt,0,inf,p[i].y);
		}
		else{
			if(V.count(make_pair(p[i].x,p[i].y)))ans[p[i].id]=1;
			else if(Mn.count(p[i].x)&&Mn[p[i].x]<p[i].y)ans[p[i].id]=0;
			else if(p[i].y==pos)ans[p[i].id]=1;
		}
	}
	for(re int i=1;i<=m;++i)puts(ans[i]?"LOSE":"WIN");
}