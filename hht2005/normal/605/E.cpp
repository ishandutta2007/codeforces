#include<bits/stdc++.h>
using namespace std;
const int N=1010;
double g[N][N],e[N],pro[N];
int vis[N];
int main() {
	int n,x;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			scanf("%d",&x);
			g[i][j]=x/100.0;
		}
	for(int i=1;i<n;i++) {
		pro[i]=1-g[i][n];
		e[i]=1;
	}
	vis[n]=1;
	for(int i=1;i<n;i++) {
		int J=-1;
		double Min=1e9;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&Min>e[j]/(1-pro[j]))
				Min=e[J=j]/(1-pro[j]);
		vis[J]=1;
		for(int j=1;j<=n;j++) {
			if(vis[j])continue;
			e[j]+=Min*g[j][J]*pro[j],pro[j]*=(1-g[j][J]);
		}
	}
	printf("%.10f\n",e[1]/(1-pro[1]));
	return 0;
}