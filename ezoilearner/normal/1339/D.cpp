#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
#define Maxn 100010
int head[Maxn],v[Maxn<<1],nxt[Maxn<<1],tot=0;
int in[Maxn];
bool leaf[Maxn];
int depth[Maxn];
bool f[2];
int ansmax,ansmin;
inline void add_edge(int s,int e){
	in[s]++;in[e]++;
	tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;
	tot++;v[tot]=s;nxt[tot]=head[e];head[e]=tot;
} 

void dfs(int u,int fa){
	if(leaf[u])f[depth[u]]=true;
    int t=0;
	for(int i=head[u];i;i=nxt[i])
	    if(v[i]^fa){
			depth[v[i]]=1-depth[u];
			dfs(v[i],u);
			if(leaf[v[i]])t++;
	    }
	if(t>0)ansmax-=(t-1);
}

int main(){
	scanf("%d",&n);ansmax=n-1;
	int s,e;
	for(int i=1;i<n;++i){
		scanf("%d%d",&s,&e);
		add_edge(s,e);
	}
	int rt;
	for(int i=1;i<=n;++i){
	    if(in[i]==1)leaf[i]=true;
	}
	for(int i=1;i<=n;++i)
	    if(in[i]>=2){
			rt=i;
			break;
	    }
	dfs(rt,0);
	if(f[0]&&f[1])ansmin=3;
	else ansmin=1;
    printf("%d %d\n",ansmin,ansmax);
    return 0;
}