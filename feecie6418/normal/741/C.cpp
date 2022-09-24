#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,col[200005],X[200005],Y[200005];
vector<int> g[200005];
void Add(int x,int y){
	g[x].push_back(y),g[y].push_back(x);
}
void dfs(int x,int c){
	col[x]=c;
	for(int y:g[x]){
		if(!col[y])dfs(y,3-c);
		else if(col[y]==col[x])puts("-1"),exit(0);
	}
}
int main(){
	cin>>n;
	for(int i=1,x,y;i<=n;i++)cin>>x>>y,X[i]=x,Y[i]=y,Add(x,y),Add(2*i-1,2*i);
	for(int i=1;i<=2*n;i++)if(!col[i])dfs(i,1);
	for(int i=1;i<=n;i++)cout<<col[X[i]]<<' '<<col[Y[i]]<<'\n';
}