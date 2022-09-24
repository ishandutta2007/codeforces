#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
struct E{
	int to,id;
};
int n,m,istree[400005],X[400005],Y[400005],fa[400005];
int st[400005],top;
vector<E> g[400005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void dfs(int x,int fa,int to){
	if(x==to){
		istree[fa]^=1;
		return ;
	}
	for(E i:g[x]){
		int y=i.to;
		if(i.id==fa)continue;
		dfs(y,i.id,to);
	}
}
void Solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	vector<int> bad;
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(gf(x)!=gf(y)){
			fa[gf(x)]=gf(y);
			g[x].push_back({y,i});
			g[y].push_back({x,i});
			istree[i]=1;
		}
		else bad.push_back(x),bad.push_back(y);
		X[i]=x,Y[i]=y;
	}
	sort(bad.begin(),bad.end());
	if(bad.size()==6&&bad[0]==bad[1]&&bad[2]==bad[3]&&bad[4]==bad[5]){
		//puts("PP");
		dfs(bad[0],0,bad[2]);
		for(int i=1;i<=m;i++){
			if(min(X[i],Y[i])==bad[0]&&max(X[i],Y[i])==bad[2])istree[i]^=1;
		}
	}
	for(int i=1;i<=m;i++)cout<<istree[i];
	puts("");
	for(int i=0;i<=max(n,m);i++){
		istree[i]=X[i]=Y[i]=fa[i]=st[i]=top=0,g[i].clear();
	}
	
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}