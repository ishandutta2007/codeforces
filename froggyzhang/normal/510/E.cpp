#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 20010
inline int read(){
	int x=0,f=1;
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
int n,head[N],cnt,tot,a[N],S,T,dep[N],odd,vis[N];
vector<int> ans[N];
bool isp[N];
struct Edge{
	int to,nxt,val;
}edge[N<<2];
void add(int a,int b,int c){
	edge[++cnt]={b,head[a],c};
	head[a]=cnt;
}
bool bfs(){
	memset(dep,0,sizeof(dep));
	queue<int> q;
	q.push(S);
	dep[S]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].val&&!dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[T];
}
int dfs(int u,int limit){
	if(u==T)return limit;
	int flow=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(dep[v]==dep[u]+1&&edge[i].val){
			int k=dfs(v,min(edge[i].val,limit));
			edge[i].val-=k;
			edge[i^1].val+=k;
			flow+=k;
			limit-=k;
		}
		if(!limit)break;
	}
	if(!flow)dep[u]=inf;
	return flow;
}
int Dinic(){
	int maxflow=0;
	while(bfs()){
		maxflow+=dfs(S,inf);
	}
	return maxflow;
}
bool check(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	n=read(),S=n+1,T=S+1,cnt=1;
	if(n&1){
		return !printf("Impossible\n");
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=2;i<=20000;++i){
		isp[i]=check(i);
	}
	for(int i=1;i<=n;++i){
		if(a[i]&1){
			add(S,i,2),add(i,S,0);
			++odd;
			for(int j=1;j<=n;++j){
				if(isp[a[i]+a[j]]){
					add(i,j,1),add(j,i,0);
				}
			}
		}
		else{
			add(i,T,2),add(T,i,0);
		}
	}
	if(odd!=(n>>1)||Dinic()^n){
		return !printf("Impossible\n");
	}
	
	for(int qwq=1;qwq<=n;++qwq){
		if(!vis[qwq]&&a[qwq]&1){
			int u=qwq;
			++tot;
			while("MYH AK IOI!"){
				vis[u]=1;
				ans[tot].push_back(u);
				for(int i=head[u];i;i=edge[i].nxt){
					int v=edge[i].to;
					if(v<=n&&!((a[v]&1)^edge[i].val)&&!vis[v]){
						u=v;
						break;
					}
				}
				if(vis[u])break;
			}
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i){
		printf("%d ",(int)ans[i].size());
		for(auto x:ans[i]){
			printf("%d ",x);
		}
		printf("\n");
	}
	return 0;
}