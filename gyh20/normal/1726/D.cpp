#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],A,B,fa[1000002],usd[1000002],ans[1000002],O[1000002];
char s[1000002];
struct edge{
	int x,y,id;
}E[1000002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline void Reset(){
	for(re int i=1;i<=n;++i)fa[i]=i;
}
inline int Try(){
	Reset();
	for(re int i=1;i<=m;++i)usd[i]=0;
	for(re int i=1;i<=m;++i)
		if(O[i]==0&&(root(E[i].x)^root(E[i].y))) 
			usd[i]=1,fa[root(E[i].x)]=root(E[i].y);
	Reset();
	for(re int i=1;i<=m;++i)
		if(!usd[i]){
			if(root(E[i].x)==root(E[i].y))return i;
			fa[root(E[i].x)]=root(E[i].y),O[i]=1;
		}
	for(re int i=1;i<=m;++i)ans[E[i].id]=usd[i];
	for(re int i=1;i<=m;++i)printf("%d",ans[i]);puts("");
	return 0;
}
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=m;++i)E[i].x=read(),E[i].y=read(),E[i].id=i,O[i]=0;
		re int x=Try();
		if(x){
			swap(E[x],E[1]);
			assert(Try()==0);
		}
	}
}