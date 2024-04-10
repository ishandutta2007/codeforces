#include <bits/stdc++.h>
int n,u,v,degr[100005]={0},vis[100005]={0};
std::vector<int>conj[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		conj[u].push_back(v);
		conj[v].push_back(u);
		degr[u]++;degr[v]++;
	}int sum=n;
	for(int i=1;i<=n;++i)if (degr[i]==2){printf("NO\n");return 0;}
	printf("YES\n");
	return 0;
}