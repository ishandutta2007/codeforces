#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3fll
using namespace std;
int n,m,N,h[55005],cnt=1,S,T,dis[55005],gap[55005];
struct Edge{
	int to,next,flow;
}e[400005];
void Add_Edge(int x,int y,int z){
	e[++cnt]=(Edge){y,h[x],z};
	h[x]=cnt;
	e[++cnt]=(Edge){x,h[y],0};
	h[y]=cnt;
}
int DFS(int now,int maxf,int s,int t){
	if(now==t)return maxf;
	int ret=0;
	for(int i=h[now];i;i=e[i].next){
		int y=e[i].to;
		if(!e[i].flow||dis[y]+1!=dis[now])continue;
		int dlt=DFS(y,min(maxf,e[i].flow),s,t);
		e[i].flow-=dlt,e[i^1].flow+=dlt;
		maxf-=dlt,ret+=dlt;
		if(dis[s]==N||!maxf)return ret;
	}
	if(!(--gap[dis[now]]))dis[s]=N;
	else gap[++dis[now]]++;
	//cout<<s<<' '<<dis[s]<<endl;
	return ret;
}
int SAP(int s,int t){
	int ret=0;
	memset(gap,0,sizeof(gap));
	memset(dis,0,sizeof(dis));
	gap[0]=N;
	while(dis[s]<N)ret+=DFS(s,inf,s,t);
	return ret;
}
signed main() {
	scanf("%lld%lld",&n,&m);
	int ss=0;
	S=n+m+1,N=T=n+m+2;
	for(int i=1,x;i<=n;i++)scanf("%lld",&x),Add_Edge(i+m,T,x);
	for(int i=1,x,y,z;i<=m;i++)scanf("%lld%lld%lld",&x,&y,&z),ss+=z,Add_Edge(S,i,z),Add_Edge(i,x+m,inf),Add_Edge(i,y+m,inf);
	cout<<ss-SAP(S,T);
	return 0;
}