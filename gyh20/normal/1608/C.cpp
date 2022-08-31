#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],b[1000002],A,B,p[1000002],ans[1000002],head[1000002],cnt,tot,bl[1000002],dfn[1000002],low[1000002],blk,stk[1000002],ist[1000002],tim,tp;
char s[1000002],u[1000002];
struct edge{
	int to,next;
}e[2000002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline bool cmp(re int x,re int y){return a[x]<a[y];}
inline bool cmp1(re int x,re int y){return b[x]<b[y];}
inline void tj(re int x){
	dfn[x]=low[x]=++tim,stk[++tp]=x,ist[x]=1;
	for(re int i=head[x];i;i=e[i].next)
			if(!dfn[e[i].to]){
				tj(e[i].to);
				low[x]=min(low[x],low[e[i].to]);
			}
			else if(ist[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x]){
		++blk;
		do{
			bl[stk[tp]]=blk;
			ist[stk[tp]]=0;
		}while(stk[tp--]^x);
	}
}
int main(){
	t=read();
	while(t--){
		n=read();
		re int mxa=0,mxb=0;
		for(re int i=1;i<=n;++i)a[i]=read(),mxa=max(mxa,a[i]);
		for(re int i=1;i<=n;++i)b[i]=read(),mxb=max(mxb,b[i]),p[i]=i,ans[i]=0;
		tot=n;
		sort(p+1,p+n+1,cmp);
		for(re int i=1;i<=n;++i){
			++tot;
			if(i>1)add(tot,tot-1),add(p[i],tot-1);
			add(tot,p[i]);
		}
		sort(p+1,p+n+1,cmp1);
		for(re int i=1;i<=n;++i){
			++tot;
			if(i>1)add(tot,tot-1),add(p[i],tot-1);
			add(tot,p[i]);
		}
		for(re int i=1;i<=tot;++i)if(!dfn[i])tj(i); 
		for(re int i=1;i<=tot;++i)
			if(i!=n+n&&i!=n+n+n)
			for(re int j=head[i];j;j=e[j].next)
				if(bl[i]^bl[e[j].to])u[bl[e[j].to]]=1;
		for(re int i=1;i<=n;++i)printf("%d",u[bl[i]]^1);puts("");
		cnt=0;
		for(re int i=1;i<=tot;++i)head[i]=dfn[i]=0;
		for(re int i=1;i<=blk;++i)u[i]=0;
		blk=0;
	}
}