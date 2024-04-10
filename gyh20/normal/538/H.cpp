#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define re register
using namespace std;
const int Mxdt=100000;
inline char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
inline char pc(char ch,bool bj){
	static char buf[Mxdt],*p1=buf,*p2=buf+Mxdt;
	return (bj||(*p1++=ch)&&p1==p2)&&fwrite(p1=buf,1,p1-buf,stdout),0;
}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
int n,m,L,R,l[100002],r[100002],c[100002],A,B,ia=1,head[100002],cnt;
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x){
	for(re int i=head[x];i&&ia;i=e[i].next)
		if(!c[e[i].to])c[e[i].to]=3-c[x],dfs(e[i].to);
		else ia&=(c[x]==3-c[e[i].to]);
}
int main(){
	A=read(),B=read(),L=1e9,n=read(),m=read();
	for(re int i=1;i<=n;++i)R=max(R,l[i]=read()),L=min(L,r[i]=read());
	if(L+R>B)L=B-R;
	if(L+R<A)R=A-L;
	if(L<0||R<0)return puts("IMPOSSIBLE"),0;
	for(re int i=1;i<=n;++i){
		re int p1=(l[i]<=L&&L<=r[i]),p2=(l[i]<=R&&R<=r[i]);
		if(!p1&&!p2)return puts("IMPOSSIBLE"),0;
		if(!p1)c[i]=2;
		if(!p2)c[i]=1;
	}
	for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x);
	for(re int i=1;i<=n;++i)if(c[i])dfs(i);
	for(re int i=1;i<=n;++i)if(!c[i])c[i]=1,dfs(i);
	if(!ia)return puts("IMPOSSIBLE"),0;
	puts("POSSIBLE");
	printf("%d %d\n",L,R);
	for(re int i=1;i<=n;++i)pc(c[i]+'0',0);
	pc('o',1);
}