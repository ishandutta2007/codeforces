#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
#define N 300030
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
int n,m,S,pre[N],head[N],cnt,vis[N]; 
ll dis[N],ans;
struct Edge{
	int to,nxt,val;
}edge[N<<1];
void add(int a,int b,int c){
	++cnt;
	edge[cnt].to=b;
	edge[cnt].val=c;
	edge[cnt].nxt=head[a];
	head[a]=cnt;
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}
	S=read();
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	q.push(make_pair(0,S));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].val||(dis[v]==dis[u]+edge[i].val&&edge[pre[v]].val>edge[i].val)){
				pre[v]=i;
				dis[v]=dis[u]+edge[i].val;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(i==S)continue;
		ans+=edge[pre[i]].val;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i){
		if(i==S)continue;
		printf("%d ",(pre[i]+1)>>1);;
	}
	return 0;
}