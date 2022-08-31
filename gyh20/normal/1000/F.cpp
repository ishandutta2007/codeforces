#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define re register
const int Mxdt=500000;	// 
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[500002],ans[500002],bl[500002],m,k,l,r,c[500002],stk[500002],tp,pos[500002];
struct query{
	int l,r,id;
	bool operator <(const query x)const{
		return bl[l]==bl[x.l]?(bl[l]&1?r<x.r:r>x.r):l<x.l;
	}
}p[500002];
inline void add(int t){t=a[t];
    ++c[t];
	if(c[t]==1){
		stk[++tp]=t;
		pos[t]=tp;
	}else if(c[t]==2){
		stk[pos[t]]=stk[tp];
		pos[stk[tp]]=pos[t];
		stk[tp--]=pos[t]=0;
	}
}
inline void del(int t){t=a[t];
    --c[t];
	if(c[t]==1){
		stk[++tp]=t;
		pos[t]=tp;
	}else if(!c[t]){
		stk[pos[t]]=stk[tp];
		pos[stk[tp]]=pos[t];
		stk[tp--]=pos[t]=0;
	}
}
int main(){
	n=read();m=sqrt(n);
	for(re int i=1;i<=n;++i)a[i]=read(),bl[i]=(i-1)/m+1;
	k=read();for(re int i=1;i<=k;++i)p[i].id=i,p[i].l=read(),p[i].r=read();
	sort(p+1,p+k+1);l=1;
	for(re int i=1;i<=k;++i){
		while(r<p[i].r)add(++r);
		while(l>p[i].l)add(--l);
		while(r>p[i].r)del(r--);
		while(l<p[i].l)del(l++);
		ans[p[i].id]=stk[tp];
	}
	for(re int i=1;i<=k;++i)printf("%d\n",ans[i]);
}