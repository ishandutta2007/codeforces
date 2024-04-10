#include<bits/stdc++.h>
#define re register
using namespace std;
int n,m,sum,dfn[100002],A[100002],c[100002],ans[100002],pos[100002],a[100002],sss,head[100002],top[100002],st[100002],ed[100002],siz[100002],son[100002],cnt,fa[100002],dep[100002],tim,pl[100002],bl[100002],tot;
unsigned short num[100002][602];
char rbuf[10000002],wbuf[10000002];
int pt=-1,pt1=-1;
inline void write(re int x){
	if(x>9)write(x/10);
	wbuf[++pt1]=(x%10)+'0';
}
inline int read(){
	re int t=0;re char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
struct edge{int to,next;}e[200002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void dfs(re int x,re int y){
	siz[x]=1,dep[x]=dep[y]+1;
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^y){
			dfs(e[i].to,x),siz[x]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[x]])son[x]=e[i].to;
		}
}
inline void rebuild(re int x){
	re int y=300-pos[x];sum-=ans[x];
	for(re int j=st[x];j<=ed[x];++j)A[j]+=y;
	pos[x]=300,ans[x]=0,memset(num[x],0,sizeof(num[x]));
	for(re int j=st[x];j<=ed[x];++j){
		if(A[j]>=-300&&A[j]<=300)++num[x][A[j]+300];
		if(A[j]<0)++ans[x];
	}
	sum+=ans[x];
}
inline void add1(re int x){
	ans[x]-=num[x][pos[x]-1];
	sum-=num[x][pos[x]-1];
	--pos[x];
	if(pos[x]<1)rebuild(x);
}
inline void del1(re int x){
	ans[x]+=num[x][pos[x]];
	sum+=num[x][pos[x]];
	++pos[x];
	if(pos[x]>599)rebuild(x);
}
inline void add1(re int l,re int r){
	while(bl[l]^bl[r])add1(bl[l]),l=ed[bl[l]]+1;
	for(re int j=l;j<=r;++j)++A[j];
	rebuild(bl[r]);
}
inline void del1(re int l,re int r){
	while(bl[l]^bl[r])del1(bl[l]),l=ed[bl[l]]+1;
	for(re int j=l;j<=r;++j)--A[j];
	rebuild(bl[r]);
}
inline void dfs1(re int x,re int y){
	top[x]=y,dfn[x]=++tim,pl[tim]=x;
	if(son[x])dfs1(son[x],y);
	for(re int i=head[x];i;i=e[i].next)
		if(e[i].to^fa[x]&&e[i].to^son[x])
			dfs1(e[i].to,e[i].to);
}
int main(){
	fread(rbuf,1,10000000,stdin);
	n=read(),m=read();
	for(re int i=2;i<=n;++i)add(fa[i]=read(),i);
	for(re int i=1;i<=n;++i)a[i]=read();
	dfs(1,1),dfs1(1,1);
	for(re int i=1;i<=n;++i)
		if(!son[i]){ 
			re int B=1.1*sqrt(dfn[i]-dfn[top[i]])+1;
			for(re int j=dfn[top[i]];j<=dfn[i];++j)bl[j]=(j-dfn[top[i]])/B+1+tot;
			tot=bl[dfn[i]];
		}
	for(re int i=1;i<=tot;++i)st[i]=1e9,pos[i]=300;
	for(re int i=1;i<=n;++i)st[bl[i]]=min(st[bl[i]],i),ed[bl[i]]=max(ed[bl[i]],i),A[dfn[i]]=a[i];
	for(re int i=1;i<=tot;++i)rebuild(i);fa[1]=0;
	while(m--){
		re int x=read(),y=c[x],z=x;
		if(c[x])A[dfn[x]]-=1e9;
		else A[dfn[x]]+=1e9;
		rebuild(bl[dfn[x]]);
		while(x){
			y?add1(dfn[top[x]],dfn[x]):del1(dfn[top[x]],dfn[x]);
			x=fa[top[x]];
		}
		c[z]^=1;
		write(sum),wbuf[++pt1]=' ';
	}
	fwrite(wbuf,1,pt1+1,stdout);
}