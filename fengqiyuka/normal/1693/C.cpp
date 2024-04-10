#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;	

struct node{
	int x,c;
	node() {}
	node(int _x,int _c) {x=_x;c=_c;}
	bool operator < (node a) const{
		if(c==a.c) return (x<a.x);
		return (c<a.c);
	}
};
set<node> S;
set<node>::iterator iter;

vector<int> B[N];
map<int,int> G[N];

int dis[N],du[N];

int main()
{
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		B[y].push_back(x);
		du[x]++;G[x][y]++;
	}
	
	memset(dis,60,sizeof(dis));
	dis[n]=0;
	for(int i=1;i<=n;i++) S.insert(node(i,dis[i]));
	
	while(1){
		iter=S.begin();
		node t=(*iter);S.erase(iter);
		if(t.x==1){
			printf("%d\n",t.c);
			return 0;
		}
		int x=t.x;
		for(auto y:B[x]){
			du[y]--;
			int t2=dis[x]+du[y]+1;
			if(dis[y]>t2){
				S.erase(node(y,dis[y]));
				dis[y]=t2;
				S.insert(node(y,dis[y]));
			}
		}
	}
	
	return 0;
}