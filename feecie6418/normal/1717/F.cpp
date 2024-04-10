#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e9;
int n,m,S,T,cur[50008],dis[50008],out[50008],in[50008],tot;
struct E{
	int to,rev,flow;
};
vector<E> g[50008];
void Add(int x,int y,int z){
	g[x].push_back({y,(int)g[y].size(),z});
	g[y].push_back({x,(int)g[x].size()-1,0});
}
void add(int x,int y,int z,int w){
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
ll dfs(int x,int t,ll fl){
	if(x==t||!fl)return fl;
	ll ret=0;
	for(int &i=cur[x];i<g[x].size();i++){
		int y=g[x][i].to;
		if(!g[x][i].flow||dis[y]!=dis[x]+1)continue;
		ll w=dfs(y,t,min(fl,(ll)g[x][i].flow));
		g[x][i].flow-=w,g[y][g[x][i].rev].flow+=w,ret+=w,fl-=w;
		if(!fl)return ret;
	}
	return ret;
}
ll Dinic(int s,int t){
	ll ans=0;
	while(bfs(s,t))memset(cur,0,sizeof(cur)),ans+=dfs(s,t,inf);
	return ans;
}
int s[100005],a[100005],ours[100005],X[100005],Y[100005],id[100005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),X[i]=x,Y[i]=y;
		ours[x]--,ours[y]++;
	}
	tot=n,S=++tot,T=++tot;
	Add(T,S,inf);
	for(int i=1;i<=n;i++){
		if(!s[i]){
			Add(S,i,inf),Add(i,T,inf);
			continue;
		}
		if(abs(ours[i]-a[i])%2){
			puts("NO");
			return 0;
		}
		if(a[i]>=ours[i]){
			add(S,i,abs(a[i]-ours[i])/2,abs(a[i]-ours[i])/2);
		}
		else {
			add(i,T,abs(a[i]-ours[i])/2,abs(a[i]-ours[i])/2);
		}
	}
	for(int i=1;i<=m;i++)Add(X[i],Y[i],1),id[i]=g[X[i]].size()-1;
	int tS=tot+1,tT=tot+2,sum=0;
	for(int i=1;i<=tot;i++)if(out[i]>in[i])Add(i,tT,out[i]-in[i]),sum+=out[i]-in[i];else Add(tS,i,in[i]-out[i]);
	if(Dinic(tS,tT)!=sum)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=m;i++){
		if(g[X[i]][id[i]].flow){
			cout<<X[i]<<' '<<Y[i]<<'\n';
		}
		else cout<<Y[i]<<' '<<X[i]<<'\n';
	}
}