#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,S,T,cur[200005],dis[200005],id[200005],a[50005];
struct E{
	int to,rev,flow;
};
vector<E> g[200005];
void Add(int x,int y,int z){
	g[x].push_back({y,(int)g[y].size(),z});
	g[y].push_back({x,(int)g[x].size()-1,0});
}
bool bfs(){
	for(int i=1;i<=T;i++)dis[i]=-1;
	queue<int> q;
	q.push(T),dis[T]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(E i:g[x]){
			int y=i.to;
			if(!g[y][i.rev].flow)continue;
			if(dis[y]==-1)dis[y]=dis[x]+1,q.push(y);
			if(y==S)return 1;
		}
	}
	return dis[S]!=-1;
}
int dfs(int x,int fl){
	if(x==T||!fl)return fl;
	int ret=0;
	for(int &i=cur[x];i<g[x].size();i++){
		int y=g[x][i].to;
		if(!g[x][i].flow||dis[x]!=dis[y]+1)continue;
		int w=dfs(y,min(fl,g[x][i].flow));
		g[x][i].flow-=w,g[y][g[x][i].rev].flow+=w,ret+=w,fl-=w;
		if(!fl)return ret;
	}
	return ret;
}
int Dinic(){
	int ans=0;
	while(bfs()){
		for(int i=1;i<=T;i++)cur[i]=0;
		ans+=dfs(S,inf);
	}
	return ans;
}
void Solve(){
	scanf("%d",&n),S=4*n+1,T=4*n+2;
	for(int i=1;i<=n;i++){
		Add(S,i,1),Add(i+n,T,1),Add(i+n,i,inf);
		Add(S,i+2*n,1),Add(i+3*n,T,1),Add(i+3*n,i+2*n,inf);
		Add(i,i+3*n,inf);
		scanf("%d",&a[i]),id[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j*j<=a[i];j++){
			if(a[i]%j)continue;
			if(j!=a[i]&&id[j]){
				Add(id[j],i+n,inf);
				Add(id[j]+2*n,i+3*n,inf);
			}
			if(a[i]/j!=a[i]&&id[a[i]/j]){
				Add(id[a[i]/j],i+n,inf);
				Add(id[a[i]/j]+2*n,i+3*n,inf);
			}
		}
	}
	cout<<Dinic()-n<<'\n';
	for(int i=1;i<=n;i++)id[a[i]]=0;
	for(int i=1;i<=T;i++)g[i].clear();
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}