#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,m;
vector<pair<int,int> > G[N];
ll dis[N];
struct Point{
	int x,y,id;
}p[N],S,T;
inline bool cmp1(Point a,Point b){
	return a.x<b.x;
}
inline bool cmp2(Point a,Point b){
	return a.y<b.y;
}
inline int Dis1(Point a,Point b){
	return min(abs(a.x-b.x),abs(a.y-b.y));
}
inline int Dis2(Point a,Point b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void Dijkstra(int S){
	static int vis[N];
	memset(dis,0x3f,sizeof(dis));
	dis[S]=0;
	q.push(make_pair(0LL,S));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto [v,w]:G[u]){
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
	n=read(),m=read();
	S.x=read(),S.y=read(),T.x=read(),T.y=read();
	for(int i=1;i<=m;++i){
		p[i].x=read(),p[i].y=read();
		p[i].id=i;
	}
	sort(p+1,p+m+1,cmp1);
	for(int i=2;i<=m;++i){
		G[p[i].id].emplace_back(p[i-1].id,p[i].x-p[i-1].x);
		G[p[i-1].id].emplace_back(p[i].id,p[i].x-p[i-1].x);
	}
	sort(p+1,p+m+1,cmp2);
	for(int i=2;i<=m;++i){
		G[p[i].id].emplace_back(p[i-1].id,p[i].y-p[i-1].y);
		G[p[i-1].id].emplace_back(p[i].id,p[i].y-p[i-1].y);
	}
	for(int i=1;i<=m;++i){
		G[m+1].emplace_back(p[i].id,Dis1(S,p[i]));
	}
	G[m+1].emplace_back(m+2,Dis2(S,T));
	for(int i=1;i<=m;++i){
		G[p[i].id].emplace_back(m+2,Dis2(T,p[i]));
	}
	Dijkstra(m+1);
	printf("%lld\n",dis[m+2]);
	return 0;
}