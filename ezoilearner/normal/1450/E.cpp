#include<bits/stdc++.h>
using namespace std;
int n,m;
#define Maxn 205
#define Maxm 2005
#define cout cerr
#define FR first
#define SE second

struct Edge{
	int s,e;
}edge[Maxm];
int dis[Maxn][Maxn];

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	rd(n);rd(m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		rd(edge[i].s);rd(edge[i].e);int t;rd(t);
		dis[edge[i].s][edge[i].e]=1;
		if(t)dis[edge[i].e][edge[i].s]=-1;
		else dis[edge[i].e][edge[i].s]=1;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;++i)
		if(dis[i][i]<0){
			puts("NO");
			return 0;
		}
	int ans=0,id=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			if(dis[i][j]>ans){
				ans=dis[i][j];
				id=i;
			}
	}
	for(int i=1;i<=m;++i)
		if(dis[id][edge[i].s]==dis[id][edge[i].e]){
			puts("NO");
			return 0;
		}
	puts("YES");
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)printf("%d ",dis[id][i]);
	return 0;
}