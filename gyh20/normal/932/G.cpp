#include<bits/stdc++.h>
using namespace std;
#define re register
const int M=1e9+7;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
char s[1000002],t[1000002];
int n,m,sl[1000002],ch[1000002][26],len[1000002],f[1000002],tot,l,g[1000002],h[1000002],tp[1000002],d[1000002];
inline int F(re int x,re int k){
	while(s[k]^s[k-len[x]-1])x=f[x];
	return x;
}
inline int ins(re int x){
	re int y=F(l,x);
	if(!ch[y][s[x]]){
		len[++tot]=len[y]+2,f[tot]=ch[F(f[y],x)][s[x]],ch[y][s[x]]=tot,d[tot]=len[tot]-len[f[tot]];
		sl[tot]=(d[tot]==d[f[tot]])?(tp[tot]=tp[f[tot]],sl[f[tot]]):(tp[tot]=len[tot],f[tot]);
	}
	return l=ch[y][s[x]];
}
int main(){
	scanf("%s",t+1),n=strlen(t+1),f[0]=g[0]=tot=1,len[1]=-1;s[0]=111;
	for(re int i=1;i<=(n>>1);++i)s[(i<<1)-1]=t[i]-'a';
	for(re int i=(n>>1)+1;i<=n;++i)s[n+n-(i<<1)+2]=t[i]-'a';
	for(re int i=1;i<=n;++i)
		for(re int j=ins(i);len[j]>0;j=sl[j]){
			h[j]=g[i-tp[j]];
			if(sl[j]^f[j])add(h[j],h[f[j]]);
			if(!(i&1))add(g[i],h[j]);
		}
	printf("%d",g[n]);
}