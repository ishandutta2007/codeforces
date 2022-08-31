#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,size[100005],fa[100005],minn=1e9,cent1,cent2;
vector<int> g[100005];
void dfs(int x,int f){
	fa[x]=f,size[x]=1;
	int mx=0;
	for(int y:g[x]){
		if(y==f)continue;
		dfs(y,x);
		size[x]+=size[y];
		mx=max(mx,size[y]);
	}
	mx=max(mx,n-size[x]);
	if(mx<minn)minn=mx,cent1=x,cent2=0;
	else if(mx==minn)cent2=x;
}
int S;
void dfs2(int x,int f){
	if(g[x].size()==1){
		S=x;
		return ;
	}
	for(int y:g[x]){
		if(y==f)continue;
		dfs2(y,x);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
	cin>>n,cent1=cent2=0,minn=1e9;
	for(int i=1;i<=n;i++)g[i].clear(),fa[i]=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	if(!cent2){
		printf("1 %d\n1 %d\n",g[1][0],g[1][0]);
		continue;
	}
	if(fa[cent1]!=cent2)swap(cent1,cent2);
	dfs2(cent1,cent2);
	printf("%d %d\n%d %d\n",S,fa[S],S,cent2);}
	return 0;
}