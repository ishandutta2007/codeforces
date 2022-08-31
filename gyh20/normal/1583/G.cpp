#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(re int&x,re int y){(x+=y)>=M?x-=M:x;}
int n,m,a[200002],b[200002],R[400002],f[400002],c[400002],ans;
char tg[400002];
inline void Add(re int x,re int y){for(;x;x^=x&(-x))add(c[x],y);}
inline int ask(re int x,re int s=0){for(;x<=m;x+=x&(-x))add(s,c[x]);return s;}
int main(){
	n=read(),m=n+n;
	for(re int i=1;i<=n;++i)a[i]=read(),R[b[i]=read()]=a[i];
	for(re int i=1;i<=m;++i)if(R[i])f[i]=ask(R[i])+1,Add(R[i],f[i]);
	n=read(),memset(c,0,sizeof(c));
	while(n--)tg[b[read()]]=1;
	for(re int i=m;i;--i){
		if(tg[i])Add(R[i],1);
		if(R[i]&&ask(R[i]))add(ans,f[i]);
	}printf("%d",ans);
}