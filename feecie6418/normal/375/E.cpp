#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{
	int to,val;
};
int n,m,id[505],iid[505],N,M,is[505],c[505];
ll dis[505][505];
long double a[505][505],b[505];
vector<E> g[505];
void Swap(int id1,int id2){
	swap(id[id1],iid[id2]);
	long double w=a[id2][id1];
	a[id2][id1]=1/w;
	for(int i=0;i<=N;i++)if(i!=id1)a[id2][i]*=-a[id2][id1];
	for(int i=0;i<=N;i++)if(i!=id1)b[i]+=b[id1]*a[id2][i];
	b[id1]*=1/w;
	for(int j=1;j<=M;j++){
		if(j==id2)continue;
		for(int i=0;i<=N;i++)if(i!=id1)a[j][i]+=a[id2][i]*a[j][id1];
		a[j][id1]*=1/w;
	}
}
void dfs(int x,int fa,ll d,ll dis[]){
	dis[x]=d;
	for(E i:g[x]){
		int y=i.to;
		if(y==fa)continue;
		dfs(y,x,d+i.val,dis);
	}
}
int main(){
	cin>>n>>m;
	int s=0;
	for(int i=1;i<=n;i++)cin>>c[i],s+=c[i];
	for(int i=1,x,y,z;i<n;i++){
		cin>>x>>y>>z;
		g[x].push_back({y,z}),g[y].push_back({x,z});
	}
	for(int i=1;i<=n;i++)dfs(i,0,0,dis[i]);
	N=n,M=n+2;
	for(int i=1;i<=n;i++)b[i]=c[i]-1;
	for(int i=1;i<=n;i++){
		a[i][0]=-1;
		for(int j=1;j<=n;j++)if(dis[i][j]<=m)a[i][j]=1;
	}
	a[n+1][0]=s;
	for(int i=1;i<=n;i++)a[n+1][i]=-1;
	a[n+2][0]=-s;
	for(int i=1;i<=n;i++)a[n+2][i]=1;
	while(1){
		bool flag=0;
		for(int i=1;i<=M;i++){
			if(a[i][0]>-1e-9)continue;
			int pos=0;
			long double mx=0;
			for(int j=1;j<=N;j++)if(a[i][j]>1e-10&&a[i][j]>mx)mx=a[i][j],pos=j;
			if(!pos)return puts("-1"),0;
			Swap(pos,i),flag=1;
		}
		if(!flag)break;
	}
	while(1){
		int pos=0,mnp=0;
		long double mn=2e9;
		for(int i=1;i<=N;i++,mnp=0,mn=2e9){
			if(b[i]<=1e-10)continue;
			for(int j=1;j<=M;j++)if(a[j][i]<-1e-9&&-a[j][0]/a[j][i]<mn)mn=-a[j][0]/a[j][i],mnp=j;
			if(!mnp)return puts("Unbounded"),assert(0),0;
			pos=i;
			break;
		}
		if(!pos)break;
		Swap(pos,mnp);
	}
	printf("%d\n",(int)round(-b[0]));
}