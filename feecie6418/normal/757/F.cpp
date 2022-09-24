#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
vector<int> g[N],h[N];
int n,m,cnt,o[N],S,f[N][18],d[N],id[N],pos[N],size[N],sign,dep[N],fr[N],ans=0;
ll dis[N];
struct Edge{
	int to,next,value;
}e[N*3];
int LCA(int x,int y) {
	if(x==-1)return y;
	if(fr[x]^fr[y])return 0;
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;i>=0;i--)if(dep[f[x][i]]>=dep[y])x=f[x][i];
	if(x==y)return x;
	for(int i=17;i>=0;i--)if(f[x][i]^f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
void A(int x,int y,int z){
	e[++cnt]={y,o[x],z};
	o[x]=cnt;
}
struct Node{
	ll dis;
	int x;
	bool operator <(const Node Y) const {
		return dis>Y.dis;
	} 
};
void Dijkstra(){
	priority_queue<Node> q;
	memset(dis,0x3f,sizeof(dis)),dis[S]=0;
	q.push({0,S});
	while(!q.empty()){
		Node now=q.top();
		q.pop();
		if(now.dis!=dis[now.x])continue;
		for(int i=o[now.x];i;i=e[i].next){
			int y=e[i].to;
			if(dis[y]>dis[now.x]+e[i].value)dis[y]=dis[now.x]+e[i].value,q.push({dis[y],y});
		}
	}
}
int main() {
	//dagghd
	scanf("%d%d%d",&n,&m,&S);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		A(x,y,z),A(y,x,z);
	}
	Dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[i]<inf)size[i]=1;
		for(int j=o[i];j;j=e[j].next){
			int y=e[j].to;
			if(dis[y]==dis[i]+e[j].value)g[i].push_back(y),h[y].push_back(i),d[y]++;
		}
	}
	queue<int> q;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	while(!q.empty()) {
		int x=q.front();
		q.pop(),id[++sign]=x,pos[x]=sign;
		for(int y:g[x])if(!--d[y])q.push(y);
	}
	for(int i=1;i<=n;i++) {
		int x=id[i],lca=-1;
		for(int y:h[x])lca=LCA(lca,y);
		if(lca==-1)lca=0;
		f[x][0]=lca,dep[x]=dep[lca]+1;
		if(lca)fr[x]=fr[lca];
		else fr[x]=x;
		for(int j=1;j<=17;j++)f[x][j]=f[f[x][j-1]][j-1];
	}
	for(int i=n;i>=1;i--)size[f[id[i]][0]]+=size[id[i]];
	for(int i=1;i<=n;i++)if(i^S)ans=max(ans,size[i]);
	cout<<ans;
}