#include<bits/stdc++.h>
using namespace std;
#define re register
#define gc getchar
int ch[200002][26],n,m,f[200002],tot,head[200002],cnt,ed[200002],cnt1,head1[200002],ans[500002],dfn[200002],siz[200002],a[200002],L[200002],R[200002],num,c[200002],tim;
queue<int>q;
inline void add(re int x){for(;x<=tot;x+=x&(-x))++c[x];}
inline int ask(re int x){
	re int s=0;
	for(;x;x-=x&(-x))s+=c[x];
	return s;
}
struct node{int x,id,o;};
struct edge{node to;int next;}e[1000002];
struct edge1{int to,next;}e1[200002];
inline void add1(re int x,re int y){e1[++cnt1]=(edge1){y,head1[x]},head1[x]=cnt1;}
inline void add(re int x,re node y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline int read(){
	re int t=0;re char v=gc();
	while(v<'0')v=gc();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=gc();
	return t;
}
inline void dfs(re int x){
	dfn[x]=++tim,siz[x]=1;
	for(re int i=head1[x];i;i=e1[i].next)dfs(e1[i].to),siz[x]+=siz[e1[i].to];
}
char s[200002];
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;++i){
		scanf("%s",s+1);
		L[i]=num+1;
		re int k=strlen(s+1),nw=0;
		for(re int j=1;j<=k;++j){
			if(!ch[nw][s[j]-'a'])ch[nw][s[j]-'a']=++tot;
			nw=ch[nw][s[j]-'a'],a[++num]=nw;
		}
		ed[i]=nw,R[i]=num;
	}
	for(re int i=0;i<26;++i)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		re int x=q.front();q.pop();
		for(re int i=0;i<26;++i)
			if(ch[x][i]){
				f[ch[x][i]]=ch[f[x]][i];
				q.push(ch[x][i]);
			}
			else ch[x][i]=ch[f[x]][i];
	}
	for(re int i=1;i<=tot;++i)add1(f[i],i);
	dfs(0);
	for(re int i=1,x,y,z;i<=m;++i){
		x=read(),y=read(),z=read();
		add(x-1,(node){z,i,-1}),add(y,(node){z,i,1});
	}++tot;
	for(re int i=1;i<=n;++i){
		for(re int j=L[i];j<=R[i];++j)add(dfn[a[j]]);
		for(re int j=head[i];j;j=e[j].next)ans[e[j].to.id]+=e[j].to.o*(ask(dfn[ed[e[j].to.x]]+siz[ed[e[j].to.x]]-1)-ask(dfn[ed[e[j].to.x]]-1));
	}
	for(re int i=1;i<=m;++i)printf("%d\n",ans[i]);
}