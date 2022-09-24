#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int n,m,K,a[200005],dis[200005];
vector<int> g[200005],g2[200005];
void BFS(int s){
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<g2[now].size();i++){
			int y=g2[now][i];
			if(dis[y]==0x3f3f3f3f){
				dis[y]=dis[now]+1;
				q.push(y);
			}
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g2[y].push_back(x);
	}
	scanf("%d",&K);
	for(int i=1;i<=K;i++)scanf("%d",&a[i]);
	BFS(a[K]);
	int minn=0,maxx=0;
	for(int i=1;i<K;i++){
		if(dis[a[i+1]]+1!=dis[a[i]])minn++;
		for(int j=0;j<g[a[i]].size();j++){
			int y=g[a[i]][j];
			if(y!=a[i+1]&&dis[y]+1==dis[a[i]]){
				maxx++;
				break;
			}
		}
	}
	cout<<minn<<' '<<maxx<<endl;
}