#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[300005],b[300005],dis[300005][2],fa[300005];
int gf(int x){
	if(x==-1)return -1;
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
struct Node{
	int tp,x,dis;
}pre[300005][2];
bool operator <(const Node x,const Node y){
	return x.dis!=y.dis?x.dis>y.dis:x.tp>y.tp;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	memset(dis,0x3f,sizeof(dis));
	priority_queue<Node> q;//1: 2: 
	dis[n][1]=0,q.push({1,n,0});
	while(!q.empty()){
		Node x=q.top();
		q.pop();
		if(x.dis!=dis[x.x][x.tp])continue;
		if(!x.x)break;
		if(x.tp){
			for(int i=gf(x.x);i>=x.x-a[x.x];i=gf(i)){
				if(dis[i][0]>dis[x.x][1]+1){
					dis[i][0]=dis[x.x][1]+1;
					q.push({0,i,dis[i][0]});
					pre[i][0]=x;
				}
				fa[i]=i-1;
			}
		}
		else {
			if(dis[x.x+b[x.x]][1]>x.dis){
				dis[x.x+b[x.x]][1]=x.dis;
				q.push({1,x.x+b[x.x],x.dis});
				pre[x.x+b[x.x]][1]=x;
			}
		}
	}
	if(dis[0][0]<1e9){
		cout<<dis[0][0]<<'\n';
		vector<pr> tmp;
		int u=0,v=0;
		while(1){
			tmp.push_back(pr(u,v));
			Node y=pre[u][v];
			u=y.x,v=y.tp;
			if(u==n&&v==1)break;
		}
		for(int i=tmp.size()-1;i>=0;i--){
			if(tmp[i].second==0)cout<<tmp[i].first<<' ';
		}
	}
	else puts("-1");
}