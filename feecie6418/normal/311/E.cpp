#include <bits/stdc++.h>
#define pos(i,j) (((i)-1)*(n+1)+(j)+1)
#define inf 0x3f3f3f3f
using namespace std;
int n,m,cnt=1,h[20005],dis[20005],gap[20005],S,T,N,a[20005],g,v[20005];
struct Edge{
	int to,next,flow;
}e[600005];
void Add_Edge(int x,int y,int z){
	//cout<<x<<' '<<y<<' '<<z<<endl;
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
int main(){
	scanf("%d%d%d",&n,&m,&g);
	S=n+m+1,T=n+m+2,N=T;
	int sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		if(!a[i])Add_Edge(S,i,v[i]);
		else Add_Edge(i,T,v[i]);
	}
	for(int i=1;i<=m;i++){
		int opt,w,k,x,y;
		scanf("%d%d%d",&opt,&w,&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			if(!opt)Add_Edge(i+n,x,inf);
			else Add_Edge(x,i+n,inf);
		}
		scanf("%d",&y);
		if(!opt)Add_Edge(S,i+n,y?w+g:w);
		else Add_Edge(i+n,T,y?w+g:w);
		sum+=w;
	}
	printf("%d\n",sum-SAP(S,T));
	return 0;
}