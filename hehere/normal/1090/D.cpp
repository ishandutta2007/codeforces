#include <bits/stdc++.h>
using namespace std;
int n,m,ta,tb;
vector < int > adj[100005];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ta=tb=-1;
	for(i=0;i<n && ta==-1;++i){
		if((int)adj[i].size()==n-1) continue;
		sort(adj[i].begin(),adj[i].end());
		for(j=i+1;j<n;++j){
			int d=lower_bound(adj[i].begin(),adj[i].end(),j)-adj[i].begin();
			if(d==(int)adj[i].size() || adj[i][d]!=j){
				ta=i;
				tb=j;
				break;
			}
		}
	}
	if(ta==-1){
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");
	for(i=0;i<ta;++i){
		printf("%d ",i+1);
	}
	printf("%d ",tb+1);
	for(i=ta+1;i<=tb;++i){
		printf("%d ",i);
	}
	for(i=tb+1;i<n;++i){
		printf("%d ",i+1);
	}
	printf("\n");
	for(i=0;i<n;++i){
		if(i!=ta)
			printf("%d ",i+1);
		else
			printf("%d ",tb+1);
	}
	printf("\n");
	return 0;
}