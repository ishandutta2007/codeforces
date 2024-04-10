#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct edge{int to,next;}e[200002];
int cnt,head[200002],n,dfn[200002],top[200002],tot,ff[200002],siz[200002],son[200002],fa[200002],dep[200002],pl[200002],tim,rt[200002],ed[200002],L[4000002],R[4000002],ls[4000002],rs[4000002];
long long ans,sum[4000002];
char s[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
struct SAM{
	int ch[200002][26],tot=1,len[200002],fa[200002],lst=1;
	inline int ins(re char c){
		re int p=lst,np=++tot;len[tot]=len[p]+1,lst=tot;
		for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
		if(!p)fa[np]=1;
		else{
			re int q=ch[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				re int nq=++tot;fa[nq]=fa[q],len[nq]=len[p]+1;
				for(re int i=0;i<26;++i)ch[nq][i]=ch[q][i];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
			}
		}
		return len[np]-len[fa[np]];
	}
	inline void build(){for(re int i=2;i<=tot;++i)add(fa[i],i);}
}S1,S2;
inline void dfs1(re int x,re int y){
	siz[x]=1,dep[x]=dep[y]+S1.len[x]-S1.len[S1.fa[x]],fa[x]=y;
	for(re int i=head[x];i;i=e[i].next){
		dfs1(e[i].to,x),siz[x]+=siz[e[i].to];
		if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
	}
}
inline void dfs2(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs2(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^son[x])dfs2(e[i].to,e[i].to);
}
inline int lca(re int x,re int y){
	if(!x||!y)return 0;
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])y=fa[top[y]];
		else x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline void pu(re int p){
	L[p]=L[ls[p]]?L[ls[p]]:L[rs[p]];
	R[p]=R[rs[p]]?R[rs[p]]:R[ls[p]];
	sum[p]=sum[ls[p]]+sum[rs[p]]-dep[lca(pl[R[ls[p]]],pl[L[rs[p]]])];
}
inline void ins(re int &p,re int l,re int r,re int x){
	if(!p)p=++tot;
	if(l==r){
		L[p]=R[p]=x,sum[p]=dep[pl[x]];
		return;
	}
	re int mid=l+r>>1;
	if(x<=mid)ins(ls[p],l,mid,x);
	else ins(rs[p],mid+1,r,x);
	pu(p); 
}
inline int merge(re int p,re int q){
	if(!p||!q)return p+q;
	ls[p]=merge(ls[p],ls[q]),rs[p]=merge(rs[p],rs[q]);
	pu(p);
	return p;
}
inline void dfs(re int x){
	for(re int i=head[x];i;i=e[i].next)dfs(e[i].to),rt[x]=merge(rt[x],rt[e[i].to]);
	ans+=1ll*(S2.len[x]-S2.len[S2.fa[x]])*sum[rt[x]];
}
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	for(re int i=n;i;--i){
		re int ss=S1.ins(s[i]-'a');ans+=ss;
		if(i^1)ans+=ss;ed[i]=S1.lst;
	} 
	S1.build();
	dfs1(1,0),dfs2(1,1),memset(head,0,sizeof(head)),cnt=0;
	for(re int i=1;i<=n;++i){
		re int ss=S2.ins(s[i]-'a');
		if(i^n)ans+=ss;ff[i]=S2.lst;
	}
	S2.build();
	for(re int i=1;i<=n-2;++i)ins(rt[ff[i]],1,S1.tot,dfn[ed[i+2]]);
	dfs(1);
	printf("%lld",ans+2);
}