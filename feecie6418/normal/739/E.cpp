#include <bits/stdc++.h>
using namespace std;
int n,a1,a2,cnt=1,h[2015],pre[2015],inq[2015],cn[2015],S,T,N;
double dis[2015],p[2015];
struct Edge {
	int to,next,flow;
	double cost;
} e[200005];
void Add_Edge(int x,int y,int z,double w) {
	e[++cnt]={y,h[x],z,w};
	h[x]=cnt;
	e[++cnt]={x,h[y],0,-w};
	h[y]=cnt;
}
bool SPFA(int s,int t) {
	queue<int> q;
	for(int i=1;i<=N;i++)dis[i]=-1e9,cn[i]=0,inq[i]=0,pre[i]=0;
	q.push(s),inq[s]=1,dis[s]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop(),inq[now]=0;
		for(int i=h[now]; i; i=e[i].next) {
			if(!e[i].flow)continue;
			int y=e[i].to;
			if(dis[y]+1e-10<dis[now]+e[i].cost) {
				dis[y]=dis[now]+e[i].cost,pre[y]=i,cn[y]=cn[now]+1;
				if(cn[y]>N+1)exit(1);
				if(!inq[y])q.push(y),inq[y]=1;
			}
		}
	}
	return dis[t]>-1e9;
}
double Adjust(int t,int s) {
	int dlt=1e9;
	for(int i=t; i!=s; i=e[pre[i]^1].to)dlt=min(dlt,e[pre[i]].flow);
	for(int i=t; i!=s; i=e[pre[i]^1].to)e[pre[i]].flow-=dlt,e[pre[i]^1].flow+=dlt;
	return dlt*dis[t];
}
double EK(int s,int t) {
	double ret=0;
	while(SPFA(s,t))ret+=Adjust(t,s);
	return ret;
}
int main() {
	scanf("%d%d%d",&n,&a1,&a2);
	S=n+1,T=n+2,N=n+4;
	Add_Edge(S,N-1,a1,0),Add_Edge(S,N,a2,0);
	for(int i=1;i<=n;i++)scanf("%lf",&p[i]),Add_Edge(N-1,i,1,p[i]);
	double x;
	for(int i=1;i<=n;i++)scanf("%lf",&x),Add_Edge(N,i,1,x),Add_Edge(i,T,1,0),Add_Edge(i,T,1,-x*p[i]);
	printf("%.10lf\n",EK(S,T));
	return 0;
}