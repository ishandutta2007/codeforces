#include<bits/stdc++.h>
#define SZ(x) ((int)x.size())
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
const int N=400005,inf=0x3f3f3f3f;
typedef std::pair<int,int> pi;
char s[N];
std::vector<pi> v[N];
struct edge{int v,nxt;}c[N<<2];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int dfn[N],low[N],id,st[N],top,bel[N],COL,dg[N];
void tarjan(int x){
	dfn[x]=low[x]=++id,st[++top]=x;
	for(int i=front[x];i;i=c[i].nxt){
		int v=c[i].v;
		if(!dfn[v])tarjan(v),chmin(low[x],low[v]);
		else if(!bel[v])chmin(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		bel[x]=++COL;
		while(st[top]!=x)bel[st[top--]]=COL;
		--top;
	}
}
int main(){
	int n,m;read(n,m);
	int id=0;
	for(int i=n;i>=1;--i){
		read_str(s+1);
		for(int j=1;j<=m;++j)if(s[j]=='#')v[j].pb({i,++id});
	}
	for(int i=1;i<=m;++i)std::sort(v[i].begin(),v[i].end());
	for(int i=1;i<=m;++i){
		for(int j=0;j<SZ(v[i]);++j){
			int x=v[i][j].first,y=v[i][j].second;
			if(j+1<SZ(v[i])&&v[i][j+1].first==x+1)addedge(y,v[i][j+1].second);
			if(j)addedge(y,v[i][j-1].second);
			auto it=std::upper_bound(v[i-1].begin(),v[i-1].end(),pi{x,inf});
			if(it!=v[i-1].begin())addedge(y,(--it)->second);
			it=std::upper_bound(v[i+1].begin(),v[i+1].end(),pi{x,inf});
			if(it!=v[i+1].begin())addedge(y,(--it)->second);
		}
	}
	for(int i=1;i<=id;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=id;++i)for(int _=front[i];_;_=c[_].nxt)if(bel[i]!=bel[c[_].v])++dg[bel[c[_].v]];
	int ans=0;for(int i=1;i<=COL;++i)ans+=dg[i]==0;
	printf("%d\n",ans);
	return 0;
}