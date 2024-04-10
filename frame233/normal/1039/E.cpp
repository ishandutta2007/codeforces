#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,S=350;
int ch[N][2],fa[N],siz[N];
inline void pushup(int u){siz[u]=siz[ch[u][0]]+siz[ch[u][1]]+1;}
inline bool nroot(int u){return u==ch[fa[u]][0]||u==ch[fa[u]][1];}
inline void rotate(int x){
	int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][!k];
	ch[y][k]=w,ch[x][!k]=y;if(nroot(y))ch[z][y==ch[z][1]]=x;
	fa[x]=z,fa[y]=x;if(w)fa[w]=y;
	pushup(y),pushup(x);
}
void splay(int x){for(int y=fa[x];nroot(x);rotate(x),y=fa[x])if(nroot(y))rotate((y==ch[fa[y]][1])==(x==ch[y][1])?y:x);}
void access(int x){for(int y=0;x;x=fa[y=x])splay(x),ch[x][1]=y,pushup(x);}
inline void link(int x,int y){access(x),splay(x),access(y),splay(y),fa[x]=y;}
inline void cut(int x,int y){access(x),splay(y),ch[y][1]=0,fa[x]=0,pushup(y);}
int a[N],mn[N],mx[N],m,ans[N],f[N][20],g[N][20],t[N];
struct qry{int w,id;inline bool operator < (const qry &o)const{return w<o.w;}}q[N];
std::vector<int> v[N];
void push(int x,int id){v[std::lower_bound(q+1,q+m+1,(qry){x,0})-q].push_back(id);}
int main(){
	int n,_;read(n,_,m);
	for(int i=1;i<=n;++i)read(a[i]),f[i][0]=g[i][0]=a[i];
	for(int i=1,x;i<=m;++i)read(x),q[i]={_-x,i};
	std::sort(q+1,q+m+1);
	for(int i=1;i<=n;++i)t[i]=i+1,mn[i]=std::min(a[i],a[i+1]),mx[i]=std::max(a[i],a[i+1]),push(0,i),fa[i]=i+1;
	for(int i=1;i<=n+1;++i)siz[i]=1;
	for(int i=n;i>=1;--i)for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)f[i][j]=std::max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=n;i>=1;--i)for(int j=1;j<20&&i+(1<<(j-1))<=n;++j)g[i][j]=std::min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=m;++i){
		int w=q[i].w;
		for(auto it:v[i]){
			cut(it,t[it]);
			while(t[it]<=n&&t[it]<=it+S&&mx[it]-mn[it]<=w)++t[it],mx[it]=std::max(mx[it],a[t[it]]),mn[it]=std::min(mn[it],a[t[it]]);
			if(t[it]<=it+S){link(it,t[it]);if(t[it]<=n)push(mx[it]-mn[it],it);}
		}
		std::vector<int>().swap(v[i]);
		int u=1,ans=0;
		while(u<=n){
			access(u),ans+=siz[u]-1;while(ch[u][0])u=ch[u][0];if(u>n)break;
			int mn=1e9+5,mx=0;++ans;
			for(int i=19;i>=0;--i)if(u+(1<<i)<=n+1&&std::max(mx,f[u][i])-std::min(mn,g[u][i])<=w)mx=std::max(mx,f[u][i]),mn=std::min(mn,g[u][i]),u+=1<<i;
		}
		::ans[q[i].id]=ans;
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]-1);
	return 0;
}