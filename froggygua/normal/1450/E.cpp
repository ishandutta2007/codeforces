#include<bits/stdc++.h>
using namespace std;
#define N 233
#define NO !printf("NO\n")
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
int dis[N][N],n,m;
vector<pair<int,int> > E;
int main(){
	n=read(),m=read();
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i){
		dis[i][i]=0;
	}
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),t=read();
		if(t){
			dis[u][v]=1,dis[v][u]=-1;
		}
		else{
			dis[u][v]=dis[v][u]=1;
		}
		E.emplace_back(u,v);
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dis[i][i]<0)return NO;
	}
	pair<int,int> p={-1,-1};
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			p=max(p,make_pair(dis[i][j],i));
		}
	}
	int s=p.second;
	for(auto [u,v]:E){
		if(dis[s][u]==dis[s][v])return NO;
	}
	printf("YES\n");
	printf("%d\n",p.first);
	for(int i=1;i<=n;++i){
		printf("%d ",dis[s][i]);
	}	
	return 0;
}