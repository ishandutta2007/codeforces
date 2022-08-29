#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t; 
}
int t,n,m,a[1000002],ans[1000002],c[1000002];
inline void add(re int x){
	for(;x<=n;x+=x&(-x))++c[x];
}
inline int ask(re int x){
	int sum=0;
	for(;x;x-=x&(-x))sum+=c[x];
	return sum;
}
vector<int>qry[1000002],b[1000002],id[1000002];
bool vis[300002];
int mn[1200002],mnp[1200002],pos,sans,tg[1200002];
inline void del(re int p,re int x){
	tg[p]+=x;mn[p]-=x;
}
inline void pd(re int p){
	if(tg[p]){
		del(p<<1,tg[p]),del(p<<1|1,tg[p]);
		tg[p]=0; 
	}
}
inline void ins(re int p,re int l,re int r,re int x,re int y){
	if(l==r){
		mn[p]=y;mnp[p]=l;
		return;
	}pd(p);
	re int mid=l+r>>1;
	if(x<=mid)ins(p<<1,l,mid,x,y);
	else ins(p<<1|1,mid+1,r,x,y);
	if(mn[p<<1]<mn[p<<1|1])mn[p]=mn[p<<1],mnp[p]=mnp[p<<1];
	else mn[p]=mn[p<<1|1],mnp[p]=mnp[p<<1|1];
}
inline void query(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		if(mn[p]<sans)sans=mn[p],pos=mnp[p];
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)query(p<<1,l,mid,x,y);
	if(y>mid)query(p<<1|1,mid+1,r,x,y);
}
inline void del(re int p,re int l,re int r,re int x,re int y){
	if(l>=x&&r<=y){
		del(p,1);
		return;
	}
	pd(p);
	re int mid=l+r>>1;
	if(x<=mid)del(p<<1,l,mid,x,y);
	if(y>mid)del(p<<1|1,mid+1,r,x,y);
	if(mn[p<<1]<mn[p<<1|1])mn[p]=mn[p<<1],mnp[p]=mnp[p<<1];
	else mn[p]=mn[p<<1|1],mnp[p]=mnp[p<<1|1];
}
int main(){
	re int bs=0;
	memset(mn,0x3f,sizeof(mn));
	n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=i-read();
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();
		qry[x+1].push_back(n-y);
		id[x+1].push_back(i);
	}
	for(re int i=n;i;--i){
		if(!a[i])add(i),del(1,1,n,i+1,n);
		else if(a[i]>0)ins(1,1,n,i,a[i]);
		while(1){
			sans=1e9;
			query(1,1,n,1,n);
			if(sans<=0){
				add(pos);
				ins(1,1,n,pos,1e9);
				del(1,1,n,pos+1,n);
			}
			else break;
		}
		//for(re int j=i+1;j<=n;++j)if((!vis[j]))&&a[j]>0&&a[j]<=ask(j))add(j); 
		for(re int j=0;j<qry[i].size();++j)ans[id[i][j]]=ask(qry[i][j]);
	}
	for(re int i=1;i<=m;++i)printf("%d\n",ans[i]);
}