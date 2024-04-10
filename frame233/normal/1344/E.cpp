#include<bits/stdc++.h>
#define pb push_back
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;typedef std::pair<int,int> pi;
std::vector<pi> e[N];ll dep[N];int Fa[N];
int ch[N][2],fa[N];ll tag[N],val[N];
inline bool nroot(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
inline void rotate(int x){
	int y=fa[x],z=fa[y],k=x==ch[y][1],w=ch[x][!k];
	ch[y][k]=w,ch[x][!k]=y;if(nroot(y))ch[z][y==ch[z][1]]=x;
	fa[y]=x,fa[x]=z;if(w)fa[w]=y;
}
inline void upd(int u,ll C){if(u)tag[u]=C,val[u]=C;}
inline void pushdown(int u){if(~tag[u])upd(ch[u][0],tag[u]),upd(ch[u][1],tag[u]),tag[u]=-1;}
void splay(int x){
	static int st[N];int y,top;st[top=1]=y=x;while(nroot(y))st[++top]=y=fa[y];
	while(top)pushdown(st[top--]);
	for(y=fa[x];nroot(x);rotate(x),y=fa[x])if(nroot(y))rotate((x==ch[y][1])==(y==ch[fa[y]][1])?y:x);
}
struct node{
	ll l,r;
	inline bool operator < (const node &o)const{return l<o.l;}
}a[N*40];int pos;
inline void push(ll l,ll r){a[++pos]={l,r};}
void access(int x,ll t){
	int y=0;for(;x;x=fa[y=x]){
		splay(x);if(y)ch[x][1]=y;
		if(fa[x])splay(fa[x]),push(val[fa[x]]+dep[fa[x]]+1,t+dep[fa[x]]);
		upd(ch[x][0],t);if(y)val[x]=t;
	}
}
void dfs(int x,int fa){Fa[x]=::fa[x]=fa,val[x]=-dep[x];for(auto [v,w]:e[x])if(v!=fa)ch[x][1]=v,dep[v]=dep[x]+w,dfs(v,x);}
int main(){
	int n,m;read(n,m);
	for(int i=1,x,y,t;i<n;++i)read(x,y,t),e[x].pb({y,t}),e[y].pb({x,t});
	dfs(1,0);for(int i=1;i<=n;++i)tag[i]=-1;
	for(int i=1,s,t;i<=m;++i)read(s,t),access(s,t);
	std::sort(a+1,a+pos+1);
	ll cur=1;int j=1;
	std::priority_queue<ll,std::vector<ll>,std::greater<ll>> q;
	while(j<=pos||!q.empty()){
		if(q.empty())cur=a[j].l;
		while(j<=pos&&a[j].l<=cur)q.push(a[j++].r);
		if(q.top()<cur){
			ll ans=q.top();int res=0;for(int i=1;i<=pos;++i)if(a[i].l<=cur&&a[i].r<ans)++res;
			return printf("%lld %d\n",q.top(),res),0;
		}
		q.pop(),++cur;
	}
	printf("-1 %d\n",pos);
	return 0;
}