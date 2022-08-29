#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],ans,A,B,p1,p2,b[1000002],c[1000002],p[1000002],fa[1000002],dfn[1000002],low[1000002],stk[1000002],tp,tim,head[1000002],cnt;
char s[1000002],ist[1000002];
struct edge{
	int to,next;
}e[1000002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]},head[x]=cnt;
}
vector<int>G[200002],H[200002];
inline int root(re int x){return x==fa[x]?x:fa[x]=root(fa[x]);}
inline bool cmp(re int x,re int y){return a[x]<a[y];}
inline bool cmp1(re int x,re int y){return root(x)<root(y);}
inline void tj(re int x){
	stk[++tp]=x,ist[x]=1,dfn[x]=low[x]=++tim;
	for(re int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x]){
		re int num=0;
		do{
			ist[stk[tp]]=0,++num;
		}while(stk[tp--]^x);
		if(num>1)ans=0;
	}
} 
int main(){
	t=read();
	while(t--){
		n=read(),ans=1,cnt=0;
		for(re int i=1;i<=n;++i)a[i]=read(),c[i]=dfn[i]=head[i]=0;
		for(re int i=1;i<=n;++i)b[i]=read(),++c[b[i]];
		re int pos=0;
		for(re int i=1;i<=n;++i)if(c[i]>c[pos])pos=i;
		for(re int i=1;i<=n;++i)
			if(a[i]!=pos&&b[i]!=pos){
				if(a[i]==b[i])ans=0;
				add(a[i],b[i]);
			}
		for(re int i=1;i<=n;++i)if(!dfn[i])tj(i);
		puts(ans?"AC":"WA");
	}
}