#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef double db;
const int M=998244353;
const int maxn=666*666/2;
const ll inf=1e12;
ll d[666][666],p[666][666],mx[666][666],val[maxn];
int n,m,s[maxn],t[maxn],ans,q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			d[i][j]=(i==j)?0:inf;
	for (int i=1;i<=m;i++){
		int u,v; ll w;
		scanf("%d%d%lld",&u,&v,&w);
		s[i]=u; t[i]=v; val[i]=w;
        d[u][v]=d[v][u]=min(d[u][v],w);
	}
	scanf("%d",&q);
	while (q--){
		int u,v; ll w;
		scanf("%d%d%lld",&u,&v,&w);
		p[u][v]=p[v][u]=max(p[u][v],w);
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++){
        mx[i][j]=-inf;
        for (int k=1;k<=n;k++) mx[i][j]=max(mx[i][j],p[i][k]-d[j][k]);
	}
	for (int i=1;i<=m;i++){
        int S=s[i],T=t[i];
        for (int j=1;j<=n;j++) if (mx[j][T]>=d[S][j]+val[i]) {ans++;break;}
	}
	printf("%d\n",ans);
	return 0;
}