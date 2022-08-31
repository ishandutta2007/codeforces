#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read() {
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
int n,ch[100002][26],tot,m,num[100002],qq,q[100002],hd,tl,f[100002],dp[100002],head[100002],cnt,dfn[100002],siz[100002],ans1[100002],tim,c[100002],w[100002],ed[100002],T,l[100002],r[100002],pos[100002],p[100002];
long long ans[202][100002];
vector<int>v[100002],g[100002];
struct edge{
	int to,next;
}e[100002];
inline void add(re int x,re int y){
	e[++cnt]=(edge){y,head[x]};
	head[x]=cnt;
}
inline void dfs(re int x,re int y){
	dfn[x]=++tim,siz[x]=1;
	for(re int i=head[x];i;i=e[i].next)if(e[i].to^y)dfs(e[i].to,x),siz[x]+=siz[e[i].to];
}
inline void add(re int x){for(;x<=tot;x+=x&(-x))++c[x];}
inline void del(re int x){for(;x<=tot;x+=x&(-x))--c[x];}
inline int ask(re int x){re int sum=0;for(;x;x-=x&(-x))sum+=c[x];return sum;}
char s[100002];
int main(){
	n=read();qq=read();
	for(re int j=1; j<=n; ++j) {
		scanf("%s",s+1);
		m=strlen(s+1);
		re int nw=0;v[j].clear();
		for(re int i=1; i<=m; ++i) {
			if(!ch[nw][s[i]-'a'])ch[nw][s[i]-'a']=++tot;
			nw=ch[nw][s[i]-'a'];v[j].push_back(nw);
		}ed[j]=nw;
	}
	hd=1;tl=0;
	for(re int i=0; i<26; ++i)if(ch[0][i])q[++tl]=ch[0][i];
	while(hd<=tl) {
		for(re int i=0; i<26; ++i)
			if(ch[q[hd]][i]) {
				q[++tl]=ch[q[hd]][i];
				f[ch[q[hd]][i]]=ch[f[q[hd]]][i];
			} else ch[q[hd]][i]=ch[f[q[hd]]][i];
		++hd;
	}
	for(re int i=1;i<=tot;++i)add(f[i],i);
	dfs(0,0);++tot;T=200;
	for(re int i=1;i<=qq;++i)l[i]=read(),r[i]=read(),pos[i]=read();cnt=0;
	for(re int i=1;i<=n;++i){
		if(v[i].size()>T){
			memset(c,0,sizeof(c));p[i]=++cnt;
			for(re int j=0;j<v[i].size();++j)add(dfn[v[i][j]]);
			for(re int j=1;j<=n;++j)ans[cnt][j]=ask(dfn[ed[j]]+siz[ed[j]]-1)-ask(dfn[ed[j]]-1),ans[cnt][j]+=ans[cnt][j-1];
		}
	}
	for(re int i=1;i<=qq;++i){
		if(v[pos[i]].size()<=T){
			g[l[i]-1].push_back(i);
			g[l[i]-1].push_back(-1);
			g[r[i]].push_back(i);
			g[r[i]].push_back(1);
		}
	}memset(c,0,sizeof(c));
	for(re int i=1;i<=n;++i){
		add(dfn[ed[i]]),del(dfn[ed[i]]+siz[ed[i]]);
		for(re int j=0;j<g[i].size();j+=2){
			re int x=g[i][j],y=pos[g[i][j]],z=g[i][j+1];
			for(re int k=0;k<v[y].size();++k)ans1[x]+=ask(dfn[v[y][k]])*z;
		}
	}
	for(re int i=1;i<=qq;++i){
	if(p[pos[i]])printf("%lld\n",ans[p[pos[i]]][r[i]]-ans[p[pos[i]]][l[i]-1]);
	else printf("%d\n",ans1[i]);}
}