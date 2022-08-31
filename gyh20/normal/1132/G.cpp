#include<bits/stdc++.h>
#define re register
using namespace std;
char rbuf[20000002],wbuf[20000002];
int pt=-1,pt1=-1;
inline int read(){
	re int t=0;re char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
inline void write(re int x){
	if(x>9)write(x/10);
	wbuf[++pt1]=x%10+'0';
}
int n,m,rt,ls[10000002],rs[10000002],mx[10000002],tg[10000002],X,Y,tot,a[1000002],stk[1000002],tp,typ,la,L[1000002];
inline void add(re int &p,re int l,re int r){
	if(!p)++tot,tg[tot]=tg[p],mx[tot]=mx[p],ls[tot]=ls[p],rs[tot]=rs[p],p=tot;
	if(l>=X&&r<=Y){
		++tg[p],++mx[p];
		return;
	}
	re int mid=l+r>>1;
	if(X<=mid)add(ls[p],l,mid);
	if(Y>mid)add(rs[p],mid+1,r);
	mx[p]=max(mx[ls[p]],mx[rs[p]])+tg[p];
}
inline int ask(re int p,re int l,re int r){
	if(!p)return 0;
	if(l>=X&&r<=Y)return mx[p];
	re int mid=l+r>>1,s=0;
	if(X<=mid)s=max(s,ask(ls[p],l,mid));
	if(Y>mid)s=max(s,ask(rs[p],mid+1,r));
	return s+tg[p];
}
int main(){
	fread(rbuf,1,20000000,stdin),n=read(),m=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		while(tp&&a[i]>a[stk[tp]])--tp;
		L[i]=stk[tp]+1,stk[++tp]=i;
	}
	for(re int i=1;i<m;++i)X=L[i],Y=i,add(rt,1,n);
	for(re int ii=1;ii<=n-m+1;++ii){
		re int l=ii,r=ii+m-1;
		X=L[r],Y=r,add(rt,1,n);
		if(l>r)swap(l,r);X=l,Y=r;
		write(la=ask(rt,1,n)),wbuf[++pt1]=' ';
	}fwrite(wbuf,1,pt1+1,stdout);
}