#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
std::vector<pi> v[N],all;
struct edge{int v,nxt;}c[N<<2];
int front[N],edge_cnt;
inline void addedge(int u,int v){c[++edge_cnt]=(edge){v,front[u]},front[u]=edge_cnt;}
int dfn[N],low[N],id,st[N],top,bel[N],COL,dep[N],eq[N],a[N],b[N],tol[N],tor[N];
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
std::vector<int> nd[N];
int val[N];
int main(){
	int n,m;read(n,m);
	int id=0;
	for(int i=n;i>=1;--i){
		read_str(s+1);
		for(int j=1;j<=m;++j)if(s[j]=='#')v[j].pb({i,++id}),dep[id]=i,b[id]=j;
	}
	for(int i=1;i<=m;++i)read(a[i]);
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
	for(int i=1;i<=id;++i)nd[bel[i]].pb(i);
	for(int i=1;i<=COL;++i){
		for(auto x:nd[i])val[b[x]]=0;
		for(auto x:nd[i])if(dep[x]>dep[val[b[x]]])val[b[x]]=x;
		for(auto x:nd[i])eq[x]=val[b[x]];
	}
	for(int i=1;i<=m;++i){
		for(int j=SZ(v[i])-1;j>=0;--j){
			int x=v[i][j].first,y=v[i][j].second;
			if(eq[y]!=y)tol[y]=tol[eq[y]];
			else{
				if(j+1<a[i])tol[y]=i+1;
				else{
					auto it=std::upper_bound(v[i-1].begin(),v[i-1].end(),(pi){x,inf});
					if(it==v[i-1].begin())tol[y]=i;
					else tol[y]=tol[(--it)->second];
				}
			}
		}
	}
	for(int i=m;i>=1;--i){
		for(int j=SZ(v[i])-1;j>=0;--j){
			int x=v[i][j].first,y=v[i][j].second;
			if(eq[y]!=y)tor[y]=tor[eq[y]];
			else{
				if(j+1<a[i])tor[y]=i-1;
				else{
					auto it=std::upper_bound(v[i+1].begin(),v[i+1].end(),(pi){x,inf});
					if(it==v[i+1].begin())tor[y]=i;
					else tor[y]=tor[(--it)->second];
				}
			}
		}
	}
	for(int i=1;i<=id;++i)if(tol[i]<=tor[i])all.pb({tol[i],tor[i]});
	std::sort(all.begin(),all.end());
	int cur=0,pos=0,r=0,ans=0;
	while(cur<=m&&!a[cur+1])++cur;
	while(cur<=m){
		++ans;
		while(pos<SZ(all)&&all[pos].first<=cur+1)chmax(r,all[pos++].second);
		cur=r;while(cur<=m&&!a[cur+1])++cur;
	}
	printf("%d\n",ans);
	return 0;
}