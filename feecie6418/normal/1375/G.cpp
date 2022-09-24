#include<bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int d[200005],s[2],n,ans=0;
void dfs1(int x,int fa){
	d[x]=d[fa]^1,s[d[x]]++;
	for(int y:g[x]){
		if(y==fa)continue;
		dfs1(y,x);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),g[x].push_back(y),g[y].push_back(x);
	dfs1(1,0),printf("%d\n",min(s[0],s[1])-1);
}