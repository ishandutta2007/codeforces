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

int n,m,W=0;
#define Maxn 200010 

int col[Maxn],cnt;
pii edge[Maxn];int w[Maxn];
int V[Maxn],E[Maxn],num[Maxn];

set<int> S;

int head[Maxn],v[Maxn<<1],z[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void link(int s,int e,int t){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;z[tot]=t;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;z[tot]=t;
}
int fa[Maxn][18],dep[Maxn],d[Maxn];
void go_up(int &k,int d){
	rep(i,0,17)
		if(d&(1<<i))k=fa[k][i];
}
int LCA(int a,int b){
	if(dep[a]>dep[b])go_up(a,dep[a]-dep[b]);
	if(dep[a]<dep[b])go_up(b,dep[b]-dep[a]);
	if(a==b)return a;
	per(i,17,0)
		if(fa[a][i]!=fa[b][i]){
			a=fa[a][i];
			b=fa[b][i];
		}
	return fa[a][0];
}
void dfs(int u,int f){
	rep(i,1,17)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f){
			dep[v[i]]=dep[u]+1;d[v[i]]=d[u]+z[i];
			fa[v[i]][0]=u;
			dfs(v[i],u);
		}
}

namespace Graph{
	vector<int> vec[Maxn];
	void add_edge(int s,int e){
		vec[s].push_back(e);
		vec[e].push_back(s);
	}
	void dfs(int u){
		S.erase(u);col[u]=cnt;V[cnt]++;
		for(int i=0;i<vec[u].size()-1;++i)
			if(vec[u][i]+1<vec[u][i+1]){
				int l=vec[u][i]+1,r=vec[u][i+1]-1;
				while(true){
				set<int>::iterator it=S.lower_bound(l);
				if(it!=S.end()&&((*it)<=r)){
					int to=(*it);
					link(u,to,1);
					dfs(to);
				}else break;
			}
			}
	}
	void build(){
		rep(u,1,n)vec[u].push_back(0),vec[u].push_back(n+1);
		rep(u,1,n)sort(vec[u].begin(),vec[u].end()),S.insert(u);
		rep(u,1,n)
			if(!col[u]){
				cnt++;
				dfs(u);
			}
	}
}

int anc[Maxn];
int getroot(int x){
	if(anc[x]!=x)anc[x]=getroot(anc[x]);
	return anc[x];
}

struct Edge{
	int s,e,t;
	bool operator <(const Edge &p)const{return t<p.t;}
}ed[1000010],cur[1000010];int len;

void umin(int &x,int y){x=min(x,y);}

bool ch[Maxn];

int main(){
	int s,e,t;
	rd(n);rd(m);
	rep(i,1,m){
		rd(s);rd(e);
		rd(t);w[i]=t;edge[i]=pii(s,e);
		W^=t;
		Graph::add_edge(s,e);
	}
	Graph::build();
	rep(i,1,cnt)num[i]=W;
	rep(i,1,m)
		if(col[edge[i].FR]==col[edge[i].SE])E[col[edge[i].FR]]++,umin(num[col[edge[i].FR]],w[i]);
		else ed[++len]=(Edge){edge[i].FR,edge[i].SE,w[i]};
	rep(i,1,cnt)anc[i]=i;
	sort(ed+1,ed+len+1);
	ll Ans=0;
	ll mn=1000000000000000000ll;
	rep(i,1,len){
		int fx=getroot(col[ed[i].s]),fy=getroot(col[ed[i].e]);
		if(fx==fy){
			ch[i]=true;
			continue;
		}
		anc[fx]=fy;
		link(ed[i].s,ed[i].e,0);
		Ans+=ed[i].t;
	}
	rep(i,1,cnt)
		if(V[i]>1){
			ll M=1ll*V[i]*(V[i]-1)/2;
			M-=E[i];
			if(M>V[i]-1)mn=0;
			else mn=min(mn,(ll)num[i]);
		}
	dfs(1,0);
	rep(i,1,len)
		if(ch[i]){
			int lca=LCA(ed[i].s,ed[i].e);
			if(d[ed[i].s]+d[ed[i].e]>2*d[lca])mn=min(mn,(ll)ed[i].t);
		}
		Ans+=mn;
		printf("%lld\n",Ans);
	return 0;
}