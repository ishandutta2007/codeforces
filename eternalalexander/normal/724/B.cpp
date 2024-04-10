#include <bits/stdc++.h>
int n,m,G[100][100],rank[100];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&G[i][j]);
		}
	}for(int i=1;i<=m;++i)rank[i]=i;
	int flag=0;
			for(int i=1;i<=n;++i){
				int cnt=0;
				for(int j=1;j<=m;++j){
					if (G[i][j]!=rank[j])cnt++;
				}if (cnt>2)flag=1;
			}if (!flag){
				printf("Yes");return 0;
			}
	for(int p1=1;p1<=m;++p1){
		for(int p2=p1+1;p2<=m;++p2){
			std::swap(rank[p1],rank[p2]);
			int flag=0;
			for(int i=1;i<=n;++i){
				int cnt=0;
				for(int j=1;j<=m;++j){
					if (G[i][j]!=rank[j])cnt++;
				}if (cnt>2)flag=1;
			}if (!flag){
				printf("Yes");return 0;
			}std::swap(rank[p1],rank[p2]);
		}
	}printf("No");return 0;
}