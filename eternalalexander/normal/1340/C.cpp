#include <bits/stdc++.h>
#define mp std::make_pair
#define pii std::pair<int,int>
#define ll long long
ll inf=9e18;
std::deque<pii>q;
int dis[10005][1005],n,m,r,g,a[10005];
void update(int u,int t1,int v,int t2,int w){
	if(t2>g||v<1||v>m)return;
	if(dis[v][t2]!=-1&&dis[v][t2]<=dis[u][t1]+w)return;
	dis[v][t2]=dis[u][t1]+w;
	if(w==0)q.push_front(mp(v,t2));
	else q.push_back(mp(v,t2));
}

int main(){
	std::memset(dis,-1,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]);
	scanf("%d%d",&g,&r);
	std::sort(a+1,a+m+1);
	dis[1][0]=0;
	q.push_front(mp(1,0));
	while(!q.empty()){
		pii u=q.front();q.pop_front();
		int x=u.first,t=u.second;
		if(t==g){
			update(x,t,x,0,1);
		}else {
			update(x,t,x+1,t+a[x+1]-a[x],0);
			update(x,t,x-1,t+a[x]-a[x-1],0);
		}
	}
	if(n<=g)printf("%d",n);
	else{
		ll ans=inf;
		for(int i=1;i<=m;++i)
			if(n-a[i]<=g&&dis[i][0]!=-1)ans=std::min(ans,(ll)dis[i][0]*(r+g)+n-a[i]);
		printf("%lld",ans==inf?-1:ans);
	}		
	return 0;
}