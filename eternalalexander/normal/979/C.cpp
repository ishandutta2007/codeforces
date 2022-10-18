#include <bits/stdc++.h>
#define ll long long
#define maxn 300005
int n,x,y,u,v,size[maxn];std::vector<int>ch[maxn];
void dfs(int u,int f){
	size[u]=1;
	for(int i=0;i<ch[u].size();++i){
		if (ch[u][i]==f)continue;
		dfs(ch[u][i],u);size[u]+=size[ch[u][i]];
	}
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);ch[u].push_back(v);ch[v].push_back(u);
	}int s1,s2;dfs(x,0);s1=size[y];dfs(y,0);s2=size[x];
	std::cout<<(ll)n*(n-1)-(ll)s1*s2;
	return 0;
}