#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 500050
inline int read(){
	int x=0,f=1;
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
int n,m,dis[N],col[N];
vector<pair<int,int> > G[N];
queue<int> q;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		G[v].emplace_back(u,w);
	}
	for(int i=1;i<=n;++i){
		col[i]=-1;
	}
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto qwq:G[u]){
			int v=qwq.first,t=qwq.second;
			if(~col[v]){
				if(col[v]==t&&dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;
					q.push(v);
				}
			}
			else{
				col[v]=t^1;
			}
		}
	}
	if(dis[1]>n){
		printf("-1\n");
	}
	else{
		printf("%d\n",dis[1]);
	}
	for(int i=1;i<=n;++i){
		putchar(col[i]<=0?'0':'1');
	}
	return 0;
}