#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline int nc(){
	re char v=getchar();
	while(v!='C'&&v!='V')v=getchar();
	return v=='C';
}
char s[402],c[402],ans[402],R[402];
int n,m,head[402],cnt,bl[402],dfn[402],low[402],tim,l,ia=1,stk[402],tp,v[402],blk,col[402],a[402],LST,vis[402],ck;
struct edge{int to,next;}e[360002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline void tj(re int x){
	dfn[x]=low[x]=++tim,stk[++tp]=x,v[x]=1;
	for(re int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to])tj(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(v[e[i].to])low[x]=min(low[x],dfn[e[i].to]);
	if(dfn[x]==low[x]){
		++blk;
		do{
			bl[stk[tp]]=blk;
			v[stk[tp]]=0,--tp;
		}while(x^stk[tp+1]);
	}
}
inline void dfss(re int x,re int y){
	if(x<=n&&vis[x+n]==y){
		ck=0;
		return;
	}
	if(x>n&&vis[x-n]==y){
		ck=0;
		return;
	}
	if(vis[x])return;
	vis[x]=y;
	if(x>n)col[x-n]=2;
	else col[x]=1;
	for(re int i=head[x];i&&ck;i=e[i].next)dfss(e[i].to,y);
}
inline void clr(re int x,re int y){
	if(vis[x]!=y)return;
	vis[x]=0;
	if(x>n)col[x-n]=0;
	else col[x]=0;
	for(re int i=head[x];i;i=e[i].next)clr(e[i].to,y);
}
inline void dfs(re int i,re bool ia){
	if(i==n+1){
		for(re int i=1;i<=n;++i)R[i]=ans[i];
		printf("%s",R+1);
		exit(0);
		return;
	}
	re int st=1,pos=0;
	if(ia)st=c[i]-'a'+1;tim=i;
	if(!col[i]){
		if(a[st]==1)ck=1,dfss(i,i),pos=i;
		if(!ck)clr(i,i);
		if(!ck||a[st]==2){
			ck=1,dfss(i+n,i),pos=i+n;
			if(!ck)clr(i+n,i);	
		}
		if(a[st]==2&&(!ck)){
			ck=1,dfss(i,i),pos=i;
			if(!ck)clr(i,i);
		}
	}
	if(!col[i])return;
	while(st<=l&&a[st]!=col[i])++st;
	ans[i]=st+'a'-1;
	if(st<=l)dfs(i+1,ia&(ans[i]==c[i]));
	if(pos)clr(pos,i);
	if(ia&&ans[i]==c[i]){
		re int st=1,pos=0;
		if(ia)st=c[i]-'a'+1;
		++st;tim=i;
		if(!col[i]){
			if(a[st]==1)ck=1,dfss(i,i),pos=i;
			if(!ck)clr(i,i);
			if(!ck||a[st]==2){	
				ck=1,dfss(i+n,i),pos=i+n;
				if(!ck)clr(i+n,i);	
			}
		}
		if(!col[i])return;
		while(st<=l&&a[st]!=col[i])++st;
		ans[i]=st+'a'-1;
		if(st<=l)dfs(i+1,ia&(ans[i]==c[i]));
		if(pos)clr(pos,i);
	}
}
int main(){
	scanf("%s",c+1),l=strlen(c+1);
	for(re int i=1;i<=l;++i)a[i]=(c[i]=='C')+1;
	n=read(),m=read();
	for(re int i=1;i<=m;++i){
		re int x=read()+nc()*n,y=read()+nc()*n;
		add(x,y);
		if(x>n)x-=n;
		else x+=n;
		if(y>n)y-=n;
		else y+=n;
		add(y,x);
	}
	for(re int i=1;i<=n+n;++i)if(!dfn[i])tj(i);
	for(re int i=1;i<=n;++i)if(bl[i]==bl[i+n])return puts("-1"),0;
	scanf("%s",c+1),dfs(1,1);
	puts("-1");
}