#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n;
#define Maxn 300010
int a[Maxn],ra[Maxn];ll Ans=0;
int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
}

int R[Maxn],fa[Maxn];
pii seq[Maxn];int len;
int siz[Maxn];
vector<int> vec[Maxn];
int dist[Maxn];
void pre_dfs(int u){
	R[u]=a[u];siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		dist[v[i]]=dist[u]+1;fa[v[i]]=u;
		pre_dfs(v[i]);siz[u]+=siz[v[i]];
		R[u]=max(R[u],R[v[i]]);
	}
	len=0;
	for(int i=head[u];i;i=nxt[i])seq[++len]=pii(R[v[i]],v[i]);
	sort(seq+1,seq+len+1);
	rep(i,1,len)vec[u].push_back(seq[i].SE);
}

int b[Maxn],dfk=0;
int c[Maxn];
int p[Maxn],plen=0;
void Dfs(int u){
	b[u]=++dfk;
	for(int i=0;i<vec[u].size();++i)Dfs(vec[u][i]);
}

int hh[Maxn],L;
int D;
void gao(int u){
	for(int i=0;i<vec[u].size();++i)gao(vec[u][i]);
	hh[++L]=u;
}

void dfs1(int u,int &dfn){
	c[u]=++dfn;
	for(int i=0;i<vec[u].size();++i)dfs1(vec[u][i],dfn);
}
void dfs2(int u,int &dfn){
	for(int i=0;i<vec[u].size();++i)dfs2(vec[u][i],dfn);
	c[u]=++dfn;
}

int main(){
	rd(n);
	rep(i,1,n)rd(a[i]),ra[a[i]]=i;
	int s,e;
	rep(i,1,n-1){
		rd(s);rd(e);
		add_edge(s,e);
	} 
	pre_dfs(1);
	Dfs(1);
	if(a[1]==1){
		rep(i,1,n)c[i]=b[i];
	}else{
		gao(1);
		int y=a[1]-1;
		D=dist[ra[y]];
		rep(i,1,y-1)Ans+=dist[hh[i]];
		if(dist[hh[y]]<D){
			puts("NO");
			return 0;
		}
		Ans+=D;
		c[hh[y]]=y;
		int u=hh[y];int pre=u;
		u=fa[u];
		while(u>0){
			p[++plen]=u;
			u=fa[u];
		}
		reverse(p+1,p+plen+1);
		rep(j,1,plen)c[p[j]]=y+j;
		int l=1,r=n;p[plen+1]=pre;
		rep(j,1,plen){
			u=p[j];
			int to=p[j+1];bool fl=false;int at;
			for(int i=0;i<vec[u].size();++i)
				if(vec[u][i]==to)at=i;
			for(int i=0;i<at;++i){
				int z=vec[u][i];
				int cur=l-1;
				dfs2(z,cur);
				l+=siz[z];
			}
			for(int i=vec[u].size()-1;i>at;--i){
				int z=vec[u][i];
				int cur=r-siz[z];
				dfs1(z,cur);
				r-=siz[z];
			}
		}
		if(l<y){
			int cur=l-1;
			dfs2(hh[y],cur);
		}
		u=pre;
		rep(i,1,dist[hh[y]]-D){
			swap(c[u],c[fa[u]]);
			u=fa[u];
		}
	}
	bool fl=true;
	rep(i,1,n)
		if(c[i]!=a[i])fl=false;
	if(fl){
		puts("YES");
		printf("%lld\n",Ans);
		rep(i,1,n)printf("%d ",b[i]);
	}else puts("NO");
	return 0;
}