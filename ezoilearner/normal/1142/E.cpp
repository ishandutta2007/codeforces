#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,m;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int head[Maxn],v[Maxn],nxt[Maxn],tot=0;
inline void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
pii edge[Maxn];
int dfn[Maxn],low[Maxn],dfk=0,st[Maxn],top=0;bool flag[Maxn];
int bel[Maxn],cnt=0,in[Maxn],at[Maxn];
vector<int> point[Maxn],vec[Maxn];
void tarjan(int u){
	dfn[u]=low[u]=++dfk;
	st[++top]=u;flag[u]=true;
	for(int i=head[u];i;i=nxt[i])
		if(!dfn[v[i]])tarjan(v[i]),low[u]=min(low[u],low[v[i]]);
		else if(flag[v[i]])low[u]=min(low[u],dfn[v[i]]);
	if(dfn[u]==low[u]){
		int x;
		cnt++;
		do
		{
			x=st[top];top--;
			bel[x]=cnt;
			point[cnt].push_back(x);
			flag[x]=false;
		}while(x!=u);
		at[cnt]=point[cnt].size()-1;
	}
}

bool query(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	int t;scanf("%d",&t);
	if(t==-1)exit(0);
	return t;
}

int hh[Maxn];
bool vis[Maxn];
int mx,sx;
void go(){
	while(mx&&!vis[mx])mx--;
	sx=min(sx,mx-1);
	while(sx>0&&!vis[sx])sx--;
}
void remove(int x){
	at[st[x]]--;
	if(at[st[x]]<0){
		vis[x]=false;
		go();
	}
}
void del(int u){
	for(int i=0;i<vec[u].size();++i){
		in[vec[u][i]]--;
		if(!in[vec[u][i]])st[++top]=vec[u][i];
	}
}

int main(){
	scanf("%d%d",&n,&m);
	int s,e;
	rep(i,1,m){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
		edge[i]=pii(s,e);
	}
	rep(i,1,n)
		if(!dfn[i])tarjan(i);
	rep(i,1,m)
		if(bel[edge[i].FR]^bel[edge[i].SE])vec[bel[edge[i].FR]].push_back(bel[edge[i].SE]),in[bel[edge[i].SE]]++;
	top=0;
	rep(i,1,cnt)
		if(!in[i])st[++top]=i;
	int x=st[1],u=point[st[1]][at[st[1]]];at[st[1]]--;
	while(top>1){
		memset(vis,false,sizeof(bool)*(top+1));
		rep(i,1,top)
			if(at[st[i]]>=0)vis[i]=true;
		mx=sx=top;go();
		while(true){
			if((mx<=0||st[mx]==x)&&(sx<=0||st[sx]==x))break;
			int to;
			if(mx>0&&st[mx]!=x)to=mx;
			else to=sx;
			int z=point[st[to]][at[st[to]]];
			remove(to);
			if(query(z,u)){
				u=z;
				x=st[to];
			}
		}
		memcpy(hh,st,sizeof(int)*(top+1));
		int pre=top;top=0;
		rep(i,1,pre)
			if(hh[i]!=x)del(hh[i]);
		st[++top]=x;
	}
	printf("! %d\n",u);
	fflush(stdout);
	return 0;
}