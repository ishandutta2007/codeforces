#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0;char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=1e6+1;
ll ans;
int n,m,k,tot;
int c[N],dfn[N];
int fa[N],siz[N],co[N],tag[N];
int FA[N],SIZ[N],rev[N];
vector<int>e[N];
struct edge{
	int x,y;
	V input(){
		x=getint(),y=getint();
		if(c[x]>c[y])swap(x,y);
		if(c[x]==c[y]){
			e[x].push_back(y);
			e[y].push_back(x);
		}
	}
	I operator==(const edge&u)const{
		return c[x]==c[u.x]&&c[y]==c[u.y];
	}
	I operator<(const edge&u)const{
		return c[x]==c[u.x]?c[y]<c[u.y]:c[x]<c[u.x];
	}
}a[N];
V input(){
	n=getint(),m=getint(),k=getint();
	FOR(i,1,n)c[i]=getint(),co[i]=-1;
	FOR(i,1,m)a[i].input();
}
V dfs(int u,int p=0){
	co[u]=p;
	for(int v:e[u])
		if(~co[v])tag[c[u]]&=co[u]!=co[v];
		else dfs(v,p^1);
}
V init(int x){if(dfn[x]!=tot)fa[x]=FA[x],siz[x]=SIZ[x],dfn[x]=tot,rev[x]=0;}
I find(int x){return init(x),x==fa[x]?x:find(fa[x]);}
V merge(int x,int y){
	if((x=find(x))==(y=find(y)))return;
	if(siz[x]>siz[y])swap(x,y);
	fa[x]=y,siz[y]+=siz[x];
}
V init(){
	sort(a+1,a+1+m);
	FOR(i,1,k)tag[i]=1;
	FOR(i,1,n)if(co[i]==-1)dfs(i);
	FOR(i,1,k)ans+=tag[i];
	ans=ans*(ans-1)/2;
	FOR(i,1,n)siz[i]=1,fa[i]=i;
	FOR(i,1,m)if(c[a[i].x]==c[a[i].y])
		merge(a[i].x,a[i].y);
	FOR(i,1,n)FA[i]=fa[i],SIZ[i]=siz[i];
}
I ask(int x){
	int out=co[x];
	while(init(x),fa[x]!=x)out^=rev[x],x=fa[x];
	return out;
}
I link(int x,int y){
	int flag=ask(x)==ask(y);
	if((x=find(x))==(y=find(y)))return flag;
	if(siz[x]>siz[y])swap(x,y);
	if(flag)rev[x]=flag;
	fa[x]=y,siz[y]+=siz[x];
	return 0;
}
V work(){
	for(int l=1,r;l<=m;l=r+1){
		for(r=l;a[r+1]==a[l];r++);
		if(c[a[l].x]==c[a[l].y]||!tag[c[a[l].x]]||!tag[c[a[l].y]])
			continue;
		tot++;
		FOR(i,l,r)if(link(a[i].x,a[i].y)){
			ans--;break;
		}
	}
	cout<<ans;
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}