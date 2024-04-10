#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
using namespace std;
#define re register
const int Mxdt=100000;	//
inline char gc() {
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline int read() {
	re int t=0;
	re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,a[500002],ans[500002],bl[500002],m,k,l,r,c[500002],stk[500002],tp,pos[500002],g[500002],h[500002],t,mex,w[500002],qa[500002],rr[500002],ttt;
struct query{
	int l,r,id,t;
	bool operator <(const query x)const {
		return bl[l]==bl[x.l]?(bl[r]==bl[x.r]?(bl[r]&1?t<x.t:t>x.t):r<x.r):l<x.l;
	}
}p[500002];
inline void add1(re int x){
	++w[x];
}
inline void del1(re int x){
	--w[x];
	if(!w[x])mex=min(mex,x);
}
inline void add(re int x){if(c[x])del1(c[x]);++c[x];add1(c[x]);}
inline void del(re int x){del1(c[x]);--c[x];if(c[x])add1(c[x]);}
inline void cg(re int x,re int y,re int z){
	if(g[z]>=x&&g[z]<=y)del(a[g[z]]),add(h[z]);
	swap(a[g[z]],h[z]);
}
int main(){
	n=read();k=read();
	m=pow(n,0.67);
	for(re int i=1; i<=n; ++i)rr[i]=a[i]=read(),bl[i]=(i-1)/m+1;ttt=n;
	for(re int i=1; i<=k; ++i) {
		if(read()==1)p[i].id=i,p[i].l=read(),p[i].r=read(),p[i].t=t,qa[i]=1;
		else g[++t]=read(),h[t]=read(),rr[++ttt]=h[t];
	}
	sort(rr+1,rr+ttt+1);
	for(re int i=1;i<=n;++i)a[i]=lower_bound(rr+1,rr+ttt+1,a[i])-rr;
	for(re int i=1;i<=t;++i)h[i]=lower_bound(rr+1,rr+ttt+1,h[i])-rr;
	sort(p+1,p+k+1),l=1,t=0,mex=1;
	for(re int i=1; i<=k; ++i) {
		if(!p[i].id)continue;
		while(r<p[i].r)add(a[++r]);
		while(l>p[i].l)add(a[--l]);
		while(r>p[i].r)del(a[r--]);
		while(l<p[i].l)del(a[l++]);
		while(t>p[i].t)cg(l,r,t--);
		while(t<p[i].t)cg(l,r,++t);
		while(w[mex])++mex;
		ans[p[i].id]=mex;
	}
	for(re int i=1; i<=k; ++i)if(qa[i])printf("%d\n",ans[i]);
}