#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int cnt=1,h[10005],dis[10005],inq[10005],pre[10005],S,T,n,m,d[10005];
struct Edge {
	int to,next,flow,cost,dn;
}e[200005];
void Add(int x,int y,int z,int w,int dn){
	e[++cnt]={y,h[x],z,w,dn},h[x]=cnt,e[++cnt]={x,h[y],0,-w,0},h[y]=cnt;
}
void add(int x,int y,int l,int r,int c){
	Add(x,y,r-l,c,l),d[x]-=l,d[y]+=l;
}
bool SPFA(int s,int t){
	memset(inq,0,sizeof(inq)),memset(pre,0,sizeof(pre)),memset(dis,0x3f,sizeof(dis));
	deque<int> q;
	q.push_back(s),inq[s]=1,dis[s]=0;
	while(!q.empty()) {
		int now=q.front();
		q.pop_front(),inq[now]=0;
		for(int i=h[now];i;i=e[i].next){
			if(!e[i].flow)continue;
			int y=e[i].to;
			if(dis[y]<=dis[now]+e[i].cost)continue;
			dis[y]=dis[now]+e[i].cost,pre[y]=i;
			if(inq[y])continue;
			if(q.size()&&dis[y]<dis[q.front()])q.push_front(y);
			else q.push_back(y);
			inq[y]=1;
		}
	}
	return dis[t]<inf;
}
int Adjust(int t,int s){
	int dlt=inf;
	for(int i=t;i!=s;i=e[pre[i]^1].to)dlt=min(dlt,e[pre[i]].flow);
	for(int i=t;i!=s;i=e[pre[i]^1].to)e[pre[i]].flow-=dlt,e[pre[i]^1].flow+=dlt;
	return dlt*dis[t];
}
int EK(int s,int t){
	int ret=0;
	while(SPFA(s,t))ret+=Adjust(t,s);
	return ret;
}
int main(){
	cin>>n>>m,S=1,T=n;
	int sum=0;
	for(int i=1,x,y,c,f;i<=m;i++){
		cin>>x>>y>>c>>f,add(x,y,f,f,0);
		if(c<f)sum+=f-c,add(x,y,0,inf,2),add(y,x,0,f-c,0),add(y,x,0,c,1);
		else add(x,y,0,c-f,1),add(x,y,0,inf,2),add(y,x,0,f,1);
	}
	int s=n+1,t=n+2;
	for(int i=1;i<=n;i++)if(d[i]>0)Add(s,i,d[i],0,0);else Add(i,t,-d[i],0,0);
	Add(T,S,inf,0,0);
	int ans=EK(s,t);
	for(int i=2;i<=cnt;i+=2)ans+=e[i].cost*e[i].dn;
	cout<<sum+ans;
}