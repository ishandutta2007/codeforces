#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,S,T,cur[200008],dis[200008],out[200008],in[200008];
struct E{
	int to,rev,flow;
};
vector<E> g[200008];
void Add(int x,int y,int z){
	g[x].push_back({y,(int)g[y].size(),z});
	g[y].push_back({x,(int)g[x].size()-1,0});
}
void add(int x,int y,int z,int w){
	if(z>w)puts("-1"),exit(0);
	Add(x,y,w-z),out[x]+=z,in[y]+=z;
}
bool bfs(int s,int t){
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	q.push(s),dis[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(E i:g[x]){
			if(!i.flow)continue;
			int y=i.to;
			if(dis[y]==-1)dis[y]=dis[x]+1,q.push(y);
		}
	}
	return dis[t]!=-1;
}
int dfs(int x,int t,int fl){
	if(x==t||!fl)return fl;
	int ret=0;
	for(int &i=cur[x];i<g[x].size();i++){
		int y=g[x][i].to;
		if(!g[x][i].flow||dis[y]!=dis[x]+1)continue;
		int w=dfs(y,t,min(fl,g[x][i].flow));
		g[x][i].flow-=w,g[y][g[x][i].rev].flow+=w,ret+=w,fl-=w;
		if(!fl)return ret;
	}
	return ret;
}
int Dinic(int s,int t){
	int ans=0;
	while(bfs(s,t))memset(cur,0,sizeof(cur)),ans+=dfs(s,t,inf);
	return ans;
}
map<int,int> cx,cy,idx,idy,mnx,mny;
int X[100005],Y[100005],tot=0,R,B,id[100005];
int main(){
	int fl=0;
	scanf("%d%d%d%d",&n,&m,&R,&B);
	if(R>B)fl=1,swap(R,B);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&X[i],&Y[i]),cx[X[i]]++,cy[Y[i]]++;
		if(!idx[X[i]])idx[X[i]]=++tot;
		if(!idy[Y[i]])idy[Y[i]]=++tot;
	}
	for(int i=1,t,l,d;i<=m;i++){
		scanf("%d%d%d",&t,&l,&d);
		if(t==1){
			if(!mnx.count(l))mnx[l]=1e9;
			mnx[l]=min(mnx[l],d);
		}
		else {
			if(!mny.count(l))mny[l]=1e9;
			mny[l]=min(mny[l],d);
		}
	}
	S=++tot,T=++tot;
	Add(T,S,inf);
	for(auto i:idx){
		int d;
		if(!mnx.count(i.first))d=1e9;
		else d=mnx[i.first];
		int l=max(0,(cx[i.first]-d+1)/2),r=min(n,(cx[i.first]+d)/2);
		add(S,i.second,l,r);
	}
	for(auto i:idy){
		int d;
		if(!mny.count(i.first))d=1e9;
		else d=mny[i.first];
		int l=max(0,(cy[i.first]-d+1)/2),r=min(n,(cy[i.first]+d)/2);
		add(i.second,T,l,r);
	}
	for(int i=1;i<=n;i++)add(idx[X[i]],idy[Y[i]],0,1),id[i]=g[idy[Y[i]]].size()-1;
	int tS=tot+1,tT=tot+2,sum=0;
	for(int i=1;i<=tot;i++)if(out[i]>in[i])Add(i,tT,out[i]-in[i]),sum+=out[i]-in[i];else Add(tS,i,in[i]-out[i]);
	if(Dinic(tS,tT)!=sum)return puts("-1"),0;
	int f=Dinic(S,T);
	printf("%lld\n",1ll*f*R+1ll*(n-f)*B);
	for(int i=1;i<=n;i++)if(g[idy[Y[i]]][id[i]].flow^fl)cout<<'r';else cout<<'b';
}