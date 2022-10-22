#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
#define Maxn 100010
#define cout cerr
#define FR first
#define SE second
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
inline void add_edge(int s,int e){
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
}

int siz[Maxn],f[Maxn][2];
void dfs(int u,int ff){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^ff)dfs(v[i],u),siz[u]+=siz[v[i]];
	//1
	int mx=-n*20,tmp;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^ff){
			if(siz[v[i]]==1)tmp=f[v[i]][1];
			else tmp=max(f[v[i]][0]+1,f[v[i]][1]);
			f[u][1]+=tmp;
			mx=max(mx,f[v[i]][1]-tmp);
		}
	if(siz[u]>1)f[u][0]=f[u][1]+mx;
}

bool c[Maxn<<1];
int bel[Maxn];
void check(int id){
	c[id]=true;
	if(id&1)c[id+1]=true;
	else c[id-1]=true;
}
void gao(int u,int ff,int ty){
	int mx=-n*20,tmp,pos;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^ff){
			if(siz[v[i]]==1)bel[v[i]]=1,tmp=f[v[i]][1];
			else{
				if(f[v[i]][1]>=f[v[i]][0]+1)bel[v[i]]=1;
				else bel[v[i]]=0;
				tmp=max(f[v[i]][1],f[v[i]][0]+1);
			}
			if(f[v[i]][1]-tmp>mx){
				mx=f[v[i]][1]-tmp;
				pos=v[i];
			}
		}
	if(!ty)bel[pos]=1;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]^ff){
			if(!bel[v[i]])check(i);
			gao(v[i],u,bel[v[i]]);
		}
}

int ans[Maxn],len,p[Maxn];
void search(int u,int f){
	ans[++len]=u;
	for(int i=head[u];i;i=nxt[i])
		if(v[i]!=f&&!c[i])search(v[i],u);
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
	rd(n);
	int s,e;
	for(int i=1;i<n;++i){
		rd(s);rd(e);
		add_edge(s,e);
	}
	dfs(1,0);
	gao(1,0,0);
	for(int i=1;i<=n;++i)
		if(!p[i]){
			len=0;
			search(i,0);
			for(int j=1;j<len;++j)p[ans[j]]=ans[j+1];
			p[ans[len]]=ans[1];
		}
	printf("%d\n",(n-1-f[1][0])*2);
	for(int i=1;i<=n;++i)printf("%d ",p[i]);
	return 0;
}