#include<bits/stdc++.h>
using namespace std;
int h[510][510],r[510][510],f[250010];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n*m;i++)f[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) {
				scanf("%d",h[i]+j);
				f[h[i][j]]=i;
			}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",r[i]+j);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++)
				printf("%d ",h[f[r[1][i]]][j]);
			puts("");
		}
	}
	return 0;
}