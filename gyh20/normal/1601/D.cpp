#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int x,y;
	bool operator <(const node A)const{return y==A.y?x<A.x:y<A.y;}
}p[500002];
int n,m,P[500002],f[500002],mx[2000002],tg[2000002];
inline void Add(re int p,re int x){
	tg[p]+=x,mx[p]+=x;
}
inline void pd(re int p){
	if(tg[p]){
		Add(p<<1,tg[p]),Add(p<<1|1,tg[p]);
		tg[p]=0;
	}
}
inline void add(re int p,re int l,re int r,re int x,re int y,re int z){
	if(l>=x&&r<=y)return Add(p,z);
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,z);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,z);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
}
inline int ask(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y)return mx[p];
	pd(p);
	re int mid=l+r>>1,s=0;
	if(x<=mid)s=max(s,ask(p<<1,l,mid,x,y));
	if(y>mid)s=max(s,ask(p<<1|1,mid+1,r,x,y));
	return s;
}
inline bool cmp(re int x,re int y){return p[x].x<p[y].x;}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		p[i].x=read(),p[i].y=read();
		if(p[i].x<m)--i,--n;
	}
	if(!n)return puts("0"),0;
	sort(p+1,p+n+1);
	for(re int i=1;i<=n;++i)P[i]=i;
	sort(P+1,P+n+1,cmp);
	re int p1=1,ans=0;
	p[0].x=-1;
	for(re int i=1;i<=n;++i){
		while(p1<=n&&p[P[p1]].x<p[i].y){
			if(P[p1]<i)add(1,0,n,0,P[p1]-1,-1);
			++p1;
		}
		re int pos=upper_bound(p+1,p+n+1,(node){2000000000,p[i].x})-p-1;
		f[i]=ask(1,0,n,0,pos)+1;
		add(1,0,n,i,i,f[i]);
		if(p[i].x>p[P[p1-1]].x)add(1,0,n,0,i-1,1);
		ans=max(ans,f[i]);
	}
	printf("%d",ans);
}