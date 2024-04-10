#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 200020
typedef long long ll;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,k,head[N],cnt,siz[N],vis[N],dep[N],d[N];
ll ans;
struct Edge{
	int to,nxt;
}edge[N<<1];
void add(int a,int b){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(v==fa)continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
priority_queue<pair<int,int> > q;
int main(){
	n=read(),k=read();
	++d[1];
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
		++d[u],++d[v];
	}
	dep[0]=-1;
	dfs(1,0);
	for(int i=1;i<=n;++i){
		if(d[i]==1)q.push(make_pair(dep[i],i));
	}
	while(k--){
		int u=q.top().second;
		ans+=q.top().first;
		q.pop();
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(vis[v])continue;
			--d[v];
			if(d[v]==1){
				q.push(make_pair(dep[v]-siz[v]+1,v));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}