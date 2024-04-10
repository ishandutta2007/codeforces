#include <bits/stdc++.h>

char G[1005][1005];
int n,m,right[2005][2005]={0},down[2005][2005]={0},min[2005][2005]={0},min2[2005][2005]={0};

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%s",G[i]+1);
	for (int i=n;i>=1;i--) {
		for (int j=m;j>=1;j--) {
			right[i][j]=down[i][j]=1;
			if (i<n&&G[i][j]==G[i+1][j]) down[i][j]=down[i+1][j]+1;
			if (j<m&&G[i][j]==G[i][j+1]) right[i][j]=right[i][j+1]+1;
		}
	}for (int i=1;i<=n;++i) 
		for (int j=1;j<=m;++j) {
			min[i][j]=right[i][j];
			if (i>1&&G[i][j]==G[i-1][j]) min[i][j]=std::min(min[i][j],min[i-1][j]);
		}
	for (int i=n;i>=1;--i) 
		for (int j=1;j<=m;++j) {
			min2[i][j]=right[i][j];
			if (i<n&&G[i][j]==G[i+1][j]) min2[i][j]=std::min(min2[i][j],min2[i+1][j]);
		}
	long long ans=0;
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			int d=down[i][j];int det=min2[i][j];
			if (i+d<=n&&down[i+d][j]==d) {det=std::min(det,min[i+d+d-1][j]);}
			else continue;
			if (i+d+d<=n&&down[i+d+d][j]>=d) {det=std::min(det,min[i+d+d+d-1][j]);}
			else continue;
			ans=(ans+(long long)det);
		}
	}std::cout<<ans;
			
	return 0;
}