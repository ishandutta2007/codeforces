#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const ll inf=1e18;
int n,m,p,qq;
ll dis[300005];
int dxq[]={0,2,0,-2};
int dyq[]={2,0,-2,0};
int dxp[]={1,1,-1,-1};
int dyp[]={1,-1,1,-1};
string a[300005];
char str[300005];
int pos(int x,int y){
	return (x-1)*m+y;
}
struct E{
	int to;
	ll val;
};
bool operator <(const E& x,const E& y){
	return x.val>y.val;
}
vector<E> g[300005];
priority_queue<E> q;
int Getgrid(int x,int y){
	if(x<1||x>n||y<1||y>m)return 1;
	return (a[x][y-1]=='#');
}
bool issame(int x1,int y1,int x2,int y2){
	if(x1>x2||(x1==x2&&y1>y2))swap(x1,x2),swap(y1,y2);
	if(x1==x2)return a[x1][y1-1]=='L'&&a[x2][y2-1]=='R';
	return a[x1][y1-1]=='U'&&a[x2][y2-1]=='D';
}
int main(){
	scanf("%d%d%d%d",&n,&m,&p,&qq);
	for(int i=1;i<=n;i++){
		scanf("%s",str),a[i]=str;
	}
	fill(dis+1,dis+n*m+1,inf);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int x=i+dxp[k],y=j+dyp[k];
				if(!Getgrid(i,j)&&!Getgrid(x,y)){
					bool ok=0;
					if(!Getgrid(i,y)&&issame(i,y,x,y))ok=1;
					if(!Getgrid(x,j)&&issame(x,j,x,y))ok=1;
					if(ok){// 
						g[pos(i,j)].push_back({pos(x,y),p});
					}
				}
				x=i+dxq[k],y=j+dyq[k];
				if(!Getgrid(i,j)&&!Getgrid(x,y)){
					if(!Getgrid((i+x)/2,(j+y)/2)&&issame((i+x)/2,(j+y)/2,x,y)){
						g[pos(i,j)].push_back({pos(x,y),qq});
					} 
				}
			}
			if(a[i][j-1]=='.')dis[pos(i,j)]=0,q.push({pos(i,j),0});
		}
	}
	while(!q.empty()){
		E u=q.top();
		q.pop();
		if(dis[u.to]!=u.val)continue;
		for(E i:g[u.to]){
			int y=i.to;
			if(dis[y]>dis[u.to]+i.val){
				dis[y]=dis[u.to]+i.val;
				q.push({y,dis[y]});
			}
		}
	}
	ll ans=inf;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!Getgrid(i,j)&&!Getgrid(i,j+1)){
				ans=min(ans,dis[pos(i,j)]+dis[pos(i,j+1)]);
			}
			if(!Getgrid(i,j)&&!Getgrid(i+1,j)){
				ans=min(ans,dis[pos(i,j)]+dis[pos(i+1,j)]);
			}
		}
	}
	if(ans>=inf)puts("-1");
	else cout<<ans;
}