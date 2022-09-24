#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,cnt=1,h[18005],pre[18005],inq[18005],S,T,N,x[405],y[405],FLOW=0;
double dis[18005];
struct Edge {
	int to,next,flow;
	double cost;
} e[200005];
void Add_Edge(int x,int y,int z,double w) {
	e[++cnt]=(Edge) {y,h[x],z,w};
	h[x]=cnt;
	e[++cnt]=(Edge) {x,h[y],0,-w};
	h[y]=cnt;
}
bool SPFA(int s,int t) {
	memset(inq,0,sizeof(inq));
	memset(pre,0,sizeof(pre));
	memset(dis,127,sizeof(dis));
	queue<int> q;
	q.push(s),inq[s]=1,dis[s]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop(),inq[now]=0;
		for(int i=h[now]; i; i=e[i].next) {
			if(!e[i].flow)continue;
			int y=e[i].to;
			if(dis[y]>dis[now]+e[i].cost) {
				dis[y]=dis[now]+e[i].cost,pre[y]=i;
				if(!inq[y])q.push(y),inq[y]=1;
			}
		}
	}
	return dis[t]<inf;
}
double Adjust(int t,int s) {
	int dlt=inf;
	for(int i=t; i!=s; i=e[pre[i]^1].to)dlt=min(dlt,e[pre[i]].flow);
	for(int i=t; i!=s; i=e[pre[i]^1].to)e[pre[i]].flow-=dlt,e[pre[i]^1].flow+=dlt;
	FLOW+=dlt;
	return dlt*dis[t];
}
double EK(int s,int t) {
	double ret=0;
	while(SPFA(s,t))ret+=Adjust(t,s);
	return ret;
}
int main() {
	scanf("%d",&n);
	S=2*n+1,N=T=S+1;
	for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]),Add_Edge(S,i,2,0),Add_Edge(i+n,T,1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(y[i]>y[j])Add_Edge(i,j+n,1,sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
		}
	}
	double x=EK(S,T);
	if(FLOW==n-1)printf("%.8lf\n",x);
	else puts("-1");
	return 0;
}