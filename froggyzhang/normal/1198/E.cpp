#include<bits/stdc++.h>
using namespace std;
#define N 223
const int inf=0x3f3f3f3f;
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
namespace Maxflow{
	int head[N],ecnt,S,T,dep[N];
	struct Edge{
		int nxt,to,val;
	}edge[N*N<<2];
	void add(int a,int b,int c){
		edge[++ecnt]={head[a],b,c};
		head[a]=ecnt;
	}
	void adde(int a,int b,int c){
		add(a,b,c),add(b,a,0);
	}
	void init(int _S,int _T){
		ecnt=1;
		memset(head,0,sizeof(head));
		S=_S,T=_T;
	}
	queue<int> q;
	bool bfs(){
		memset(dep,0,sizeof(dep));
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
		return dep[T]>0;
	}
	int dfs(int u,int limit){
		if(u==T)return limit;
		int flow=0;
		for(int i=head[u];i&&limit;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]==dep[u]+1&&edge[i].val){
				int k=dfs(v,min(limit,edge[i].val));
				edge[i].val-=k;
				edge[i^1].val+=k;
				flow+=k;
				limit-=k;
			}
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
}
struct Rec{
	int x1,x2,y1,y2;
}a[N];
int n,m;
int bx[N],by[N],lenx,leny;
int main(){
	n=read(),m=read();
	bx[++lenx]=by[++leny]=0;
	bx[++lenx]=by[++leny]=n;
	for(int i=1;i<=m;++i){
		a[i].x1=read(),a[i].y1=read();
		a[i].x2=read(),a[i].y2=read();
		bx[++lenx]=a[i].x1-1;
		bx[++lenx]=a[i].x2;
		by[++leny]=a[i].y1-1;
		by[++leny]=a[i].y2;
	}
	sort(bx+1,bx+lenx+1);
	sort(by+1,by+leny+1);
	lenx=unique(bx+1,bx+lenx+1)-bx-1;
	leny=unique(by+1,by+leny+1)-by-1;
	Maxflow::init(lenx+leny+1,lenx+leny+2);
	for(int i=1;i<=lenx;++i)Maxflow::adde(Maxflow::S,i,bx[i]-bx[i-1]);
	for(int i=1;i<=leny;++i)Maxflow::adde(i+lenx,Maxflow::T,by[i]-by[i-1]);
	for(int u=1;u<=m;++u){
		for(int i=1;i<=lenx;++i){
			for(int j=1;j<=leny;++j){
				if(a[u].x1<=bx[i-1]+1&&a[u].x2>=bx[i]&&a[u].y1<=by[j-1]+1&&a[u].y2>=by[j]){
					Maxflow::adde(i,j+lenx,inf);
				}		
			}
		}
	}
	printf("%d\n",Maxflow::Dinic());
	return 0;
}