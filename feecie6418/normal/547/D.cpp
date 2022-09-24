#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,lstx[200005],lsty[200005],v[200005],col[200005];
vector<int> g[200005];
void dfs(int x,int c){
	v[x]=1,col[x]=c;
	for(int y:g[x])if(!v[y])dfs(y,1-c);
}
int main() {
	cin>>n;
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		if(lstx[x])g[lstx[x]].push_back(i),g[i].push_back(lstx[x]),lstx[x]=0;
		else lstx[x]=i;
		if(lsty[y])g[lsty[y]].push_back(i),g[i].push_back(lsty[y]),lsty[y]=0;
		else lsty[y]=i;
	}
	for(int i=1;i<=n;i++)if(!v[i])dfs(i,0);
	for(int i=1;i<=n;i++)putchar(col[i]?'r':'b');
}