#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K;
#define Maxn 500010
#define cout cerr
#define E 5000010
int c[Maxn];
int head[Maxn],v[E],nxt[E],tot=0;
int to[Maxn],mate[Maxn];
int id[2];
void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int vis[Maxn],col[Maxn],T=0;
bool flag;
void dfs(int u,int c){
	vis[u]=T;
	col[u]=c;
	if(!id[c])id[c]=u;
	for(int i=head[u];i;i=nxt[i])
		if(vis[v[i]]!=T){
			dfs(v[i],c^1);
		}else if(col[v[i]]==col[u])flag=false;
}
void search(int u){
	to[u]=id[col[u]];
	vis[u]=T;
	for(int i=head[u];i;i=nxt[i])
		if(vis[v[i]]!=T)search(v[i]);
}

struct Edge{
	int c1,c2,s,e;
	Edge(){c1=c2=0;s=e=0;}
	Edge(int _c1,int _c2,int _s,int _e){c1=_c1;c2=_c2;s=_s;e=_e;}
	bool operator <(const Edge &t)const{
		if(c1!=t.c1)return c1<t.c1;
		if(c2!=t.c2)return c2<t.c2;
		return s<t.s;
	}
}edge[Maxn];int len=0;

bool type[Maxn];

void Modify(int u){
	if(mate[u])add_edge(u,mate[u]);
}
void cao(int u){
	head[u]=head[mate[u]]=0;
}

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

int main(){
	rd(n);rd(m);rd(K);
	for(int i=1;i<=n;++i)rd(c[i]);
	int s,e;
	for(int i=1;i<=m;++i){
		rd(s);rd(e);
		if(c[s]>c[e])swap(s,e);
		if(c[s]!=c[e])edge[++len]=Edge(c[s],c[e],s,e);
		else add_edge(s,e);
	}
	sort(edge+1,edge+len+1);
	int num=K;
	for(int i=1;i<=K;++i)type[i]=true;
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			T++;
			id[0]=id[1]=0;flag=true;
			dfs(i,0);
			if(!flag&&type[c[i]]){
				type[c[i]]=false;
				num--;
			}
			mate[id[0]]=id[1];
			mate[id[1]]=id[0];
			T++;
			search(i);
		}
	tot=0;memset(head,0,sizeof(head));
	ll Ans=1ll*num*(num-1)/2;
	cout<<num<<endl;
	for(int i=1,last;i<=len;i=last+1){
		last=i;
		while(last<len&&edge[last+1].c1==edge[i].c1&&edge[last+1].c2==edge[i].c2)last++;
		if(!type[edge[i].c1]||!type[edge[i].c2])continue;
		for(int j=i;j<=last;++j){
			edge[j].s=to[edge[j].s];
			edge[j].e=to[edge[j].e];
			Modify(edge[j].s);
			Modify(edge[j].e);
			add_edge(edge[j].s,edge[j].e);
		}
		flag=true;
		int pre=T;
		for(int j=i;j<=last;++j)
			if(vis[edge[j].s]<=pre){
				T++;
				dfs(edge[j].s,0);
				if(!flag){
					Ans--;
					break;
				}
			}
		tot=0;
		for(int j=i;j<=last;++j){
			cao(edge[j].s);cao(edge[j].e);
			head[edge[j].s]=head[edge[j].e]=0;
		}
	}
	if(Ans==-1)cout<<num<<endl;
	printf("%lld\n",Ans);
	return 0;
}