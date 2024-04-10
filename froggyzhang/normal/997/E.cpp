#include<bits/stdc++.h>
using namespace std;
#define N 600030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],p[N];
struct Inter{
	int l,r;
	Inter(int _l=0,int _r=0){l=_l,r=_r;}
	friend Inter operator + (const Inter &a,const Inter &b){
		return Inter(min(a.l,b.l),max(a.r,b.r));
	}
};
int lg[N];
Inter g[N][20];
void init(){
	for(int i=2;i<=n;++i){
		lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=n;++i){
		g[i][0]=Inter(p[i],p[i]);
	}
	for(int j=1;j<=19;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){
			g[i][j]=g[i][j-1]+g[i+(1<<j-1)][j-1];
		}
	}
}
inline Inter Query(int l,int r){
	int k=lg[r-l+1];
	return g[l][k]+g[r-(1<<k)+1][k];
}
int cnt,type[N];
struct node{
	Inter I,ran,fsup,sup;
	friend node operator + (const node &a,const node &b){
		return (node){a.I+b.I,a.ran+b.ran,a.fsup+b.fsup,a.fsup+b.sup};
	}
	inline bool check(){
		return I.r-I.l==ran.r-ran.l;
	}
}t[N],fnd[N];
int st[N];
vector<int> G[N];
int Add(int u){
	static int top,fail[N];
	int v=st[top];
	node tmp=t[v]+t[u];
	if(!top||tmp.sup.r>t[u].I.r){
		st[++top]=u;
		fnd[top]=t[u];
		fail[top]=top-1;
		return 0;
	}
	if(type[v]&&!G[v].empty()&&(t[G[v].back()]+t[u]).check()){
		t[v]=tmp,G[v].push_back(u);
		--top;
		return v;
	}
	if(tmp.check()){
		t[++cnt]=tmp;
		type[cnt]=true;
		G[cnt].push_back(v);
		G[cnt].push_back(u);
		--top;
		return cnt;
	}
	v=top;
	tmp=t[u];
	do{
		tmp=fnd[v]+tmp;
		v=fail[v];
	}while(tmp.sup.r<=t[u].I.r&&!tmp.check());
	if(tmp.check()){
		t[++cnt]=tmp;
		type[cnt]=0;
		for(int i=v+1;i<=top;++i){
			G[cnt].push_back(st[i]);
		}
		G[cnt].push_back(u);
		top=v;
		return cnt;
	}
	st[++top]=u;
	fail[top]=v;
	fnd[top]=tmp;
	return 0;	
}
int f[N][20],top[N],siz[N],son[N],dep[N],rt,Q;
ll sl[N],sr[N];
void dfs1(int u){
	dep[u]=dep[f[u][0]]+1;
	for(int j=1;j<=19;++j){
		f[u][j]=f[f[u][j-1]][j-1]; 
	}
	siz[u]=1;
	for(auto v:G[u]){
		if(v==f[u][0])continue;
		f[v][0]=u;
		dfs1(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]){
			son[u]=v;
		}
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u])return;
	dfs2(son[u],topf);
	for(auto v:G[u]){
		if(v==f[u][0]||v==son[u])continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]][0];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline int Get(int x,int k){
	for(int i=19;i>=0;--i){
		if(k>>i&1)x=f[x][i];
	}
	return x;
}
int pos[N];
ll pl[N],pr[N];
ll dfsl(int u){
	int siz=G[u].size();
	ll now=0;
	for(int i=siz-1;i>=0;--i){
		int v=G[u][i];
		sl[v]=sl[u]+now+(type[u]?1LL*(siz-i-1)*(siz-i-2)/2:0);
		now+=dfsl(v);
	}
	return now+(type[u]&&u>n?1LL*siz*(siz-1)/2:1);
}
ll dfsr(int u){
	int siz=G[u].size();
	ll now=0;
	for(int i=0;i<siz;++i){
		int v=G[u][i];
		pr[v]=now;
		sr[v]=sr[u]+now+(type[u]?1LL*i*(i-1)/2:0);
		pos[v]=i;
		now+=dfsr(v);
		pl[v]=now;
	}
	return now+(type[u]&&u>n?1LL*siz*(siz-1)/2:1);
}
int main(){
	n=read();
	a[1]=n+2,a[n+2]=1;
	p[n+2]=1,p[1]=n+2;
	for(int i=2;i<=n+1;++i){
		a[i]=read()+1;
		p[a[i]]=i;
	}
	n+=2;
	init();
	cnt=n;
	for(int i=1;i<=n;++i){
		t[i].I=Inter(i,i);
		t[i].ran=Inter(a[i],a[i]);
		t[i].fsup= i==n?Inter(i,i):Query(min(a[i],a[i+1]),max(a[i],a[i+1]));
		t[i].sup= Inter(i,i);
		type[i]=1;
	}
	for(int i=1;i<=n;++i)
		for(int u=i;u;u=Add(u));
	rt=st[1];
	dfs1(rt);
	dfs2(rt,rt);
	dfsl(rt);
	dfsr(rt);
	Q=read();
	while(Q--){
		int l=read(),r=read()+2;
		int lca=LCA(l,r);
		int ls=Get(l,dep[l]-dep[lca]-1);
		int rs=Get(r,dep[r]-dep[lca]-1);
		ll ans=sl[l]-sl[ls]+sr[r]-sr[rs]+pr[rs]-pl[ls];
		int res=pos[rs]-pos[ls]-1;
		ans+=type[lca]?1LL*res*(res-1)/2:0;
		printf("%lld\n",ans);
	}
	return 0;
}